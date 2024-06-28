#include "test_output_pin.hpp"
#include "test_wire.hpp"

using namespace model;
using namespace model::test;
using namespace std;

TestOutputPin::TestOutputPin(Component *component, string name)
	: component_(component), name_(name), wire_()
{}

const Component *TestOutputPin::component(void) const {
	return component_;
}

optional<const Wire *> TestOutputPin::output_wire(void) const {
	if (wire_ == nullptr) return {};
	return { wire_ };
}

const std::string &TestOutputPin::name(void) const {
	return name_;
}

void TestOutputPin::set_wire(TestWire *wire) {
	wire_ = wire;
}