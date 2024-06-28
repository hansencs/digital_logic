#include "test_input_pin.hpp"
#include "test_wire.hpp"

using namespace model;
using namespace model::test;
using namespace std;

TestInputPin::TestInputPin(Component *component, string name)
	: component_(component), name_(name)
{}

TestInputPin::TestInputPin(
	Component *component, string name, const OutputPin *dual
) :
	component_(component), name_(name), dual_(dual)
{}

const Component *TestInputPin::component(void) const {
	return component_;
}

const Wire *TestInputPin::input_wire(void) const {
	return wire_;
}

std::optional<const OutputPin *> TestInputPin::dual(void) const {
	return dual_;
}

const std::string &TestInputPin::name(void) const {
	return name_;
}

void TestInputPin::set_wire(TestWire *wire) {
	wire_ = wire;
}