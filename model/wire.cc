#include <algorithm>

#include "wire.h"

using namespace model;
using namespace std;

optional<const OutputPin *> Wire::wire_input(void) const {
	return wire_input_;
}

const std::vector<const InputPin *> &Wire::wire_outputs(void) const {
	return wire_outputs_;
}

void Wire::set_wire_input(const OutputPin *input) {
	if (wire_input_.has_value()) throw "overwriting wire input";
	wire_input_ = input;
}

void Wire::add_wire_output(const InputPin *output) {
	if (find(
		wire_outputs_.begin(),
		wire_outputs_.end(),
		output) != wire_outputs_.end()
	) {
		throw "adding duplicate pin";
	}
	wire_outputs_.push_back(output);
}