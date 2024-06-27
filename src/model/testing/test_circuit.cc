#include "test_circuit.hpp"
#include "test_pin.hpp"

using namespace model;
using namespace model::test;
using namespace std;

TestCircuit::TestCircuit(unsigned input_pin_count, unsigned output_pin_count) {
	for (unsigned i = 0; i < input_pin_count; i++) {
		input_pins_.push_back(new TestPin(this, string("in") + to_string(i)));
	}
	for (unsigned i = 0; i < output_pin_count; i++) {
		output_pins_.push_back(new TestPin(this, string("out") + to_string(i)));
	}
}

span<const InputPin * const> TestCircuit::input_pins(void) const {
	return { input_pins_ };
}

span<const OutputPin * const> TestCircuit::output_pins(void) const {
	return { output_pins_ };
}

span<const Component * const> TestCircuit::components(void) const {
	return { components_ };
}

const OutputPin *TestCircuit::get_interior_input_pin(string pin_name) const {
	for (auto pin : interior_input_pins_) {
		if (pin->name() == pin_name) return pin;
	}
	throw string("pin name not found: " + pin_name);
}

TestCircuit::~TestCircuit(void) {
	for (auto sub_component : components_) delete sub_component;
	for (auto pin : input_pins_) delete pin;
	for (auto pin : output_pins_) delete pin;
}