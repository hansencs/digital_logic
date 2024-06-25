#include "test_pin.hpp"
#include "test_wire.hpp"

using namespace model;
using namespace model::test;
using namespace std;

span<const Pin * const> TestWire::outputs(void) const {
	return { output_pins_ };
}

void TestWire::connect_pin(Pin *pin, bool input) {
	auto test_pin = dynamic_cast<TestPin *>(pin);
	test_pin->set_wire(this);
	if (!input) {
		output_pins_.push_back(test_pin);
	}
}