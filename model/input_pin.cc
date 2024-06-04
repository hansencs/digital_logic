#include "input_pin.h"

using namespace model;
using namespace std;

InputPin::InputPin(const string &name, const Component *component) {
	name_ = name;
	component_ = component;
}

optional<const Wire *> InputPin::input_wire(void) const {
	return input_wire_;
}

void InputPin::set_input_wire(const Wire *input_wire) {
	input_wire_ = input_wire;
}