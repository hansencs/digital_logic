#include "test_circuit.hpp"
#include "test_input_pin.hpp"
#include "test_output_pin.hpp"

using namespace model;
using namespace model::test;
using namespace std;

TestCircuit::TestCircuit(unsigned input_pin_count, unsigned output_pin_count) {
	for (unsigned i = 0; i < input_pin_count; i++) {
		auto interior = new TestOutputPin(this, string("in") + to_string(i));
		interior_input_pins_.push_back(interior);
		input_pins_.push_back(
			new TestInputPin(this, string("in") + to_string(i), interior)
		);
	}
	for (unsigned i = 0; i < output_pin_count; i++) {
		auto exterior = new TestOutputPin(this, string("out") + to_string(i));
		output_pins_.push_back(exterior);
		interior_output_pins_.push_back(
			new TestInputPin(this, string("out") + to_string(i), exterior)
		);
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

TestCircuit::~TestCircuit(void) {
	for (auto sub_component : components_) delete sub_component;
	for (auto pin : input_pins_) delete pin;
	for (auto pin : interior_input_pins_) delete pin;
	for (auto pin : output_pins_) delete pin;
	for (auto pin : interior_output_pins_) delete pin;
}