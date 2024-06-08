#include <algorithm>
#include <string>

#include "wire.h"

using namespace model;
using namespace std;

optional<OutputPin *> Wire::wire_input(void) {
	return wire_input_;
}

vector<InputPin *> &Wire::wire_outputs(void) {
	return wire_outputs_;
}

void Wire::set_wire_input(OutputPin *input) {
	if (wire_input_.has_value()) throw string("overwriting wire input");
	wire_input_ = input;
}

void Wire::add_wire_output(InputPin *output) {
	if (find(
		wire_outputs_.begin(),
		wire_outputs_.end(),
		output) != wire_outputs_.end()
	) {
		throw string("adding duplicate pin");
	}
	wire_outputs_.push_back(output);
}