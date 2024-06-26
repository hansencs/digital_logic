#include "test_pin.hpp"
#include "test_wire.hpp"

using namespace model;
using namespace model::test;
using namespace std;

TestPin::TestPin(Component *component, string name)
	: component_(component), name_(name) {}

const Component *TestPin::component(void) const {
	return component_;
}

const Wire *TestPin::input_wire(void) const {
	return wire_;
}

optional<const Wire *> TestPin::output_wire(void) const {
	if (wire_ == nullptr) return {};
	return { wire_ };
}

const std::string &TestPin::name(void) const {
	return name_;
}

void TestPin::set_wire(TestWire *wire) {
	wire_ = wire;
}