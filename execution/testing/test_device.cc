#include "test_device.h"

using namespace execution;
using namespace execution::test;

TestDevice::TestDevice(void) : temp_s_(Signal::LOW) {}

Signal TestDevice::step(Signal s, bool set) {
	Signal temp = temp_s_;
	if (set) temp_s_ = s;
	return temp;
}

void TestDevice::set(Signal value) {
	temp_s_ = value;
}

Signal TestDevice::check(void) const {
	return temp_s_;
}