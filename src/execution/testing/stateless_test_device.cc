#include "stateless_test_device.hpp"

using namespace execution::test;
using namespace std;

StatelessTestDevice::StatelessTestDevice(step_fn_type step_fn)
	: step_fn_(step_fn) {}

function<void (uint8_t *, uint8_t *)> StatelessTestDevice::step_fn(void) {
	return step_fn_;
}