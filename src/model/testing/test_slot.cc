#include "test_pin.hpp"
#include "test_slot.h"

using namespace model;
using namespace model::test;
using namespace std;

TestSlot::TestSlot(unsigned input_pin_count, unsigned output_pin_count) {
	for (unsigned i = 0; i < input_pin_count; i++) {
		input_pins_.push_back(new TestPin(this, string("in") + to_string(i)));
	}
	for (unsigned i = 0; i < output_pin_count; i++) {
		output_pins_.push_back(new TestPin(this, string("out") + to_string(i)));
	}
}

span<const InputPin * const> TestSlot::input_pins(void) const {
	return { input_pins_ };
}

span<const OutputPin * const> TestSlot::output_pins(void) const {
	return { output_pins_ };
}