#include "test_device.h"

using namespace execution;
using namespace execution::test;

static Signal v;

TestDevice::TestDevice(void) : temp_s_(Signal::LOW) {}

void TestDevice::step(void) {
	Signal temp = temp_s_;
	temp_s_ = v;
	v = temp;
}

void TestDevice::set(Signal value) {
	temp_s_ = value;
}

Signal TestDevice::check(void) const {
	return temp_s_;
}