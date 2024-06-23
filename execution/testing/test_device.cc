#include "test_device.h"

using namespace execution;
using namespace execution::test;

static Signal v;

void TestDevice::set(Signal value) {
	v = value;
}

Signal TestDevice::check(void) const {
	return v;
}