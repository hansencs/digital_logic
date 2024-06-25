#include "test_pin.hpp"
#include "test_wire.hpp"

using namespace model;
using namespace model::test;
using namespace std;

const OutputPin *TestWire::input(void) const {
	return wire_input_;
}

span<const InputPin * const> TestWire::outputs(void) const {
	return { wire_outputs_ };
}

void TestWire::connect_pin(InputPin *pin) {
	auto test_pin = dynamic_cast<TestPin *>(pin);
	test_pin->set_wire(this);
	wire_outputs_.push_back(pin);
}

void TestWire::connect_pin(OutputPin *pin) {
	auto test_pin = dynamic_cast<TestPin *>(pin);
	test_pin->set_wire(this);
	wire_input_ = pin;
}