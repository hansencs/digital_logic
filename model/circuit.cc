#include "circuit.h"

using namespace model;
using namespace std;

Circuit::Circuit(
	const string &name,
	const map<string, const Component *> children,
	const vector<string> &input_names,
	const vector<string> &output_names
) :
	Component(name, input_names, output_names, &circuit_pin_factory),
	children_(children)
{}

const std::map<std::string, const Component *> &Circuit::component_map(
	void
) const {
	return children_;
}

const Component *Circuit::get_component(std::string name) const {
	auto it = children_.find(name);
	if (it == children_.end()) throw "component name <" + name + "> not found";
	return it->second;
}

DualPin *Circuit::get_input_pin(unsigned index) const {
	return static_cast<DualPin *>(Component::get_input_pin(index));
}

DualPin *Circuit::get_input_pin(std::string name) const {
	return static_cast<DualPin *>(Component::get_input_pin(name));
}

DualPin *Circuit::get_output_pin(unsigned index) const {
	return static_cast<DualPin *>(Component::get_output_pin(index));
}

DualPin *Circuit::get_output_pin(std::string name) const {
	return static_cast<DualPin *>(Component::get_output_pin(name));
}

Circuit::~Circuit(void) {
	for (auto child_component : children_) delete child_component.second;
}