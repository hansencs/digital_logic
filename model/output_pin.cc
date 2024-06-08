#include "output_pin.h"

using namespace model;
using namespace std;

OutputPin::OutputPin(const string &name, const Component *component) {
	name_ = name;
	component_ = component;
}

optional<Wire *> OutputPin::output_wire(void) const {
	return output_wire_;
}

void OutputPin::set_output_wire(Wire *output_wire) {
	output_wire_ = output_wire;
}