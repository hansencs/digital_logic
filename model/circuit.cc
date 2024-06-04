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

const Component *Circuit::get_component(std::string name) const {
	auto it = children_.find(name);
	if (it == children_.end()) throw "component name not found";
	return it->second;
}

const DualPin *Circuit::get_input_pin(unsigned index) const {
	return static_cast<const DualPin *>(Component::get_input_pin(index));
}

const DualPin *Circuit::get_input_pin(std::string name) const {
	return static_cast<const DualPin *>(Component::get_input_pin(name));
}

const DualPin *Circuit::get_output_pin(unsigned index) const {
	return static_cast<const DualPin *>(Component::get_output_pin(index));
}

const DualPin *Circuit::get_output_pin(std::string name) const {
	return static_cast<const DualPin *>(Component::get_output_pin(name));
}