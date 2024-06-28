#include "test_input_pin.hpp"
#include "test_output_pin.hpp"
#include "test_slot.hpp"

using namespace model;
using namespace model::test;
using namespace std;

TestSlot::TestSlot(unsigned input_pin_count, unsigned output_pin_count) {
	for (unsigned i = 0; i < input_pin_count; i++) {
		input_pins_.push_back(
			new TestInputPin(this, string("in") + to_string(i))
		);
	}
	for (unsigned i = 0; i < output_pin_count; i++) {
		output_pins_.push_back(
			new TestOutputPin(this, string("out") + to_string(i))
		);
	}
}

span<const InputPin * const> TestSlot::input_pins(void) const {
	return { input_pins_ };
}

span<const OutputPin * const> TestSlot::output_pins(void) const {
	return { output_pins_ };
}

TestSlot::~TestSlot(void) {
	for (auto pin : input_pins_) delete pin;
	for (auto pin : output_pins_) delete pin;
}