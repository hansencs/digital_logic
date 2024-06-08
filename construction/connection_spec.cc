#include <string>

#include "circuit.h"
#include "connection_spec.h"

using namespace construction;
using namespace model;
using namespace std;

ConnectionSpec::ConnectionSpec(PinIdentifier pin1, PinIdentifier pin2) :
	pin1_(pin1),
	pin2_(pin2)
{}

static inline void connect_pin(InputPin *pin, Wire *wire) {
	pin->set_input_wire(wire);
	wire->add_wire_output(pin);
}

static inline void connect_pin(OutputPin *pin, Wire *wire) {
	pin->set_output_wire(wire);
	wire->set_wire_input(pin);
}

static inline void merge_wires(Wire *w1, Wire *w2) {
	if (w1 == w2) return;
	auto w1_in = w1->wire_input();
	auto w2_in = w2->wire_input();
	if (w1_in.has_value() && w2_in.has_value()) {
		if (*w1_in != *w2_in) throw string("cannot merge wires with different inputs");
	} else if (w2_in.has_value()) {
		connect_pin(*w2_in, w1);
	}
	for (auto w2_out : w2->wire_outputs()) connect_pin(w2_out, w1);
	delete w2;
}

union PinUnion {
	InputPin *ip;
	OutputPin *op;
};

static inline PinIdentifierType get_pin(
	Circuit *c,
	PinIdentifier pid,
	union PinUnion *result)
{
	if (pid.is_interior()) {
		const Component *component = c->get_component(pid.component_name());
		if (pid.pin_type() == PinIdentifierType::INPUT) {
			if (pid.has_pin_name()) {
				result->ip = component->get_input_pin(pid.pin_name());
				return PinIdentifierType::INPUT;
			} else {
				result->ip = component->get_input_pin(pid.pin_index());
				return PinIdentifierType::INPUT;
			}
		} else {
			if (pid.has_pin_name()) {
				result->op = component->get_output_pin(pid.pin_name());
				return PinIdentifierType::OUTPUT;
			} else {
				result->op = component->get_output_pin(pid.pin_index());
				return PinIdentifierType::OUTPUT;
			}
		}
	} else {
		if (pid.pin_type() == PinIdentifierType::INPUT) {
				if (pid.has_pin_name()) {
					result->ip = c->get_output_pin(pid.pin_name());
					return PinIdentifierType::INPUT;
				} else {
					result->ip = c->get_output_pin(pid.pin_index());
					return PinIdentifierType::INPUT;
				}
		} else {
			if (pid.has_pin_name()) {
				result->op = c->get_input_pin(pid.pin_name());
				return PinIdentifierType::OUTPUT;
			} else {
				result->op = c->get_input_pin(pid.pin_index());
				return PinIdentifierType::OUTPUT;
			}
		}
	}
}

void ConnectionSpec::apply(Circuit *containing_circuit) const {
	union PinUnion p1, p2;
	PinIdentifierType p1type = get_pin(containing_circuit, pin1_, &p1);
	PinIdentifierType p2type = get_pin(containing_circuit, pin2_, &p2);
	if (
		p1type == PinIdentifierType::OUTPUT &&
		p2type == PinIdentifierType::OUTPUT
	) {
		throw string("output pins cannot be connected");
	}
	if (
		p1type == PinIdentifierType::OUTPUT ||
		p2type == PinIdentifierType::OUTPUT
	) {
		OutputPin *op = p1type == PinIdentifierType::OUTPUT ? p1.op : p2.op;
		InputPin *ip = p1type == PinIdentifierType::INPUT ? p1.ip : p2.ip;
		if (op->output_wire().has_value() && ip->input_wire().has_value()) {
			merge_wires(*op->output_wire(), *ip->input_wire());
		} else if (op->output_wire().has_value()) {
			connect_pin(ip, *op->output_wire());
		} else if (ip->input_wire().has_value()) {
			connect_pin(op, *ip->input_wire());
		} else {
			Wire *w = new Wire();
			connect_pin(op, w);
			connect_pin(ip, w);
		}
	} else {
		InputPin *ip1 = p1.ip;
		InputPin *ip2 = p2.ip;
		if (ip1->input_wire().has_value() && ip2->input_wire().has_value()) {
			merge_wires(*ip1->input_wire(), *ip2->input_wire());
		} else if (ip1->input_wire().has_value()) {
			connect_pin(ip2, *ip1->input_wire());
		} else if (ip2->input_wire().has_value()) {
			connect_pin(ip1, *ip2->input_wire());
		} else {
			Wire *w = new Wire();
			connect_pin(ip1, w);
			connect_pin(ip2, w);
		}
	}
}