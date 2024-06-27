#include "manual_test_device.hpp"

using namespace execution;
using namespace execution::test;
using namespace std;

ManualTestDevice::ManualTestDevice(unsigned input_pins, unsigned output_pins) {
	for (unsigned i = 0; i < input_pins; i++)
		inputs_.push_back(Signal::LOW);
	for (unsigned i = 0; i < output_pins; i++)
		outputs_.push_back(Signal::LOW);
}

#include <iostream>
void ManualTestDevice::step_functor(
	ManualTestDevice *device, uint8_t *input_buffer, uint8_t *output_buffer
) {
	for (unsigned i = 0; i < device->inputs_.size(); i++)
		device->inputs_[i] = BYTE_TO_SIGNAL(input_buffer[i]);
	for (unsigned i = 0; i < device->outputs_.size(); i++)
		output_buffer[i] = SIGNAL_TO_BYTE(device->outputs_[i]);
}

function<void (uint8_t *, uint8_t *)> ManualTestDevice::step_fn(void) {
	return bind(step_functor, this, placeholders::_1, placeholders::_2);
}

void ManualTestDevice::set(unsigned index, Signal value) {
	outputs_[index] = value;
}

Signal ManualTestDevice::check(unsigned index) const {
	return inputs_[index];
}