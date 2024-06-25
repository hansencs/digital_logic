#include "output_pin.hpp"
#include "test_circuit.h"

using namespace model;
using namespace model::test;
using namespace std;

TestCircuit::TestCircuit(void) {
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