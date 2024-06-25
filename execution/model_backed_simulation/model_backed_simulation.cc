#include <list>
#include <string>

#include "circuit.h"
#include "component.h"
#include "device.h"
#include "model.h"
#include "model_backed_simulation.h"
#include "pin.hpp"
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

static inline void extract_slot(
	const Slot *slot,
	set<const Component *> &discrete_components,
	map<const Pin *, Signal> &pin_values
) {
	discrete_components.insert(slot);
	for (auto pin : slot->input_pins()) pin_values[pin] = Signal::LOW;
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

		case ComponentType::SLOT:
		return extract_slot(
			static_cast<const Slot *>(component),
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

#include <iostream>

void ModelBackedSimulation::step_slot(const Slot *slot) {
	auto device = device_map_[slot];
	Signal give = Signal::LOW, take;
	cout << "step " << slot << endl;
	if (slot->input_pins().size() > 0) {
		give = pin_values_[slot->input_pins()[0]];
		cout << " vin " << (int) give << endl;
	}
	take = device->step(give);
	if (slot->output_pins().size() > 0) {
		pin_values_[slot->output_pins()[0]] = take;
		cout << " vout " << (int) take << endl;
	}
}

void ModelBackedSimulation::step(void) {
	for (auto component : discrete_components_) {
		ComponentType c_type = component->component_type();
		switch (c_type) {
			case ComponentType::SLOT:
			step_slot(static_cast<const Slot *>(component));
			break;

			default:
			throw string("invalid component type");
		}
	}
	for (auto component : discrete_components_) {
		auto pin_vec = component->output_pins();
		list<const Pin *> frontier { pin_vec.begin(), pin_vec.end() };
		while (!frontier.empty()) {
			auto pin = frontier.front();
			frontier.pop_front();
			auto wire = pin->wire();
			wire_values_[wire] = pin_values_[pin];
			cout << "frontier pin to wire " << pin << " " << wire << " " << (int) wire_values_[wire] << endl;
			for (auto w_out_pin : wire->outputs()) {
				pin_values_[w_out_pin] = wire_values_[wire];
				auto w_out_component = w_out_pin->component();
				if (w_out_component->component_type() == ComponentType::CIRCUIT) {
					auto circuit = static_cast<const Circuit *>(w_out_component);
					auto name = w_out_pin->name();
					auto new_frontier_pin = circuit->get_interior_output_pin(name);
					pin_values_[new_frontier_pin] = pin_values_[w_out_pin];
					frontier.push_back(new_frontier_pin);
				}
			}
		}
	}
}