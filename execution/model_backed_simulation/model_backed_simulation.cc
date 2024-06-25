#include <list>
#include <string>

#include "circuit.h"
#include "component.h"
#include "device.h"
#include "model.h"
#include "model_backed_simulation.h"
#include "nand.hpp"
#include "input_pin.hpp"
#include "output_pin.hpp"
#include "slot.h"
#include "wire.h"

using namespace execution;
using namespace execution::impl;
using namespace model;
using namespace std;

static void extract(
	const Component *component,
	set<const Component *> &discrete_components,
	map<const Pin *, Signal> &pin_values
);

static inline void extract_circuit(
	const Circuit *circuit,
	set<const Component *> &discrete_components,
	map<const Pin *, Signal> &pin_values
) {
	for (auto sub_component : circuit->components())
		extract(sub_component, discrete_components, pin_values);
}

static inline void extract_discrete_component(
	const Component *component,
	set<const Component *> &discrete_components,
	map<const Pin *, Signal> &pin_values
) {
	discrete_components.insert(component);
	for (auto pin : component->input_pins()) pin_values[pin] = Signal::LOW;
}

static void extract(
	const Component *component,
	set<const Component *> &discrete_components,
	map<const Pin *, Signal> &pin_values
) {
	ComponentType c_type = component->component_type();
	switch (c_type) {
		case ComponentType::CIRCUIT:
		return extract_circuit(
			static_cast<const Circuit *>(component),
			discrete_components,
			pin_values
		);

		case ComponentType::NAND:
		case ComponentType::SLOT:
		return extract_discrete_component(
			component,
			discrete_components,
			pin_values
		);
		break;

		default:
		throw string("invalid component type");
	}
}

ModelBackedSimulation::ModelBackedSimulation(const Model *model) : model_(model)
{
	extract(model->top_level_component(), discrete_components_, pin_values_);
}

void ModelBackedSimulation::insert_device(
	const model::Slot *slot,
	Device *device
) {
	device_map_[slot] = device;
}

void ModelBackedSimulation::step_nand(const model::Nand *nand) {
	Signal left = pin_values_[nand->nand_left_input()];
	Signal right = pin_values_[nand->nand_right_input()];
	pin_values_[nand->nand_output()] =
		(left == Signal::HIGH && right == Signal::HIGH) ?
		Signal::LOW : Signal::HIGH;
}

void ModelBackedSimulation::step_slot(const Slot *slot) {
	if (device_map_.find(slot) == device_map_.end()) return;
	auto device = device_map_[slot];
	Signal give = Signal::LOW, take;
	bool set = false;
	if (slot->input_pins().size() > 0) {
		set = true;
		give = pin_values_[slot->input_pins()[0]];
	}
	take = device->step(give, set);
	if (slot->output_pins().size() > 0) {
		pin_values_[slot->output_pins()[0]] = take;
	}
}

void ModelBackedSimulation::step(void) {
	for (auto component : discrete_components_) {
		ComponentType c_type = component->component_type();
		switch (c_type) {
			case ComponentType::NAND:
			step_nand(static_cast<const Nand *>(component));
			break;

			case ComponentType::SLOT:
			step_slot(static_cast<const Slot *>(component));
			break;

			default:
			throw string("invalid component type");
		}
	}
	for (auto component : discrete_components_) {
		auto pin_vec = component->output_pins();
		list<const OutputPin *> frontier { pin_vec.begin(), pin_vec.end() };
		while (!frontier.empty()) {
			auto pin = frontier.front();
			frontier.pop_front();
			auto maybe_wire = pin->output_wire();
			if (!maybe_wire.has_value()) continue;
			auto wire = *maybe_wire;
			wire_values_[wire] = pin_values_[pin];
			for (auto w_out_pin : wire->outputs()) {
				pin_values_[w_out_pin] = wire_values_[wire];
				auto w_out_component = w_out_pin->component();
				if (w_out_component->component_type() == ComponentType::CIRCUIT) {
					auto circuit = static_cast<const Circuit *>(w_out_component);
					auto name = w_out_pin->name();
					auto new_frontier_pin = circuit->get_interior_input_pin(name);
					pin_values_[new_frontier_pin] = pin_values_[w_out_pin];
					frontier.push_back(new_frontier_pin);
				}
			}
		}
	}
}