#include "test_input_pin.hpp"
#include "test_nand.hpp"
#include "test_output_pin.hpp"

using namespace model;
using namespace model::test;
using namespace std;

TestNand::TestNand(void) {
	input_pins_.push_back(new TestInputPin(this, "left"));
	input_pins_.push_back(new TestInputPin(this, "right"));
	output_pin_.push_back(new TestOutputPin(this, "out"));
}

span<const InputPin * const> TestNand::input_pins(void) const {
	return { input_pins_ };
}

span<const OutputPin * const> TestNand::output_pins(void) const {
	return { output_pin_ };
}

const InputPin *TestNand::nand_left_input(void) const {
	return input_pins_[0];
}

const InputPin *TestNand::nand_right_input(void) const {
	return input_pins_[1];
}

const OutputPin *TestNand::nand_output(void) const {
	return output_pin_[0];
}

TestNand::~TestNand(void) {
	for (auto pin : input_pins_) delete pin;
	for (auto pin : output_pin_) delete pin;
}