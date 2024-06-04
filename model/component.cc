#include "component.h"

using namespace model;
using namespace std;

Component::Component(
	const string &name,
	const vector<string> &input_names,
	const vector<string> &output_names,
	const PinFactory *pin_factory
) :
	name_(name)
{
	for (auto input_name : input_names) {
		inputs_.push_back(pin_factory->make_input_pin(this, input_name));
	}
	for (auto output_name : output_names) {
		outputs_.push_back(pin_factory->make_output_pin(this, output_name));
	}
}

Component::Component(
	const std::string &name,
	const std::vector<std::string> &input_names,
	const std::vector<std::string> &output_names
) :
	Component(name, input_names, output_names, &component_pin_factory)
{}

const string &Component::name(void) const {
	return name_;
}

const InputPin *Component::get_input_pin(unsigned index) const {
	if (index >= inputs_.size()) throw "pin index out of range";
	return inputs_[index];
}

const InputPin *Component::get_input_pin(std::string name) const {
	for (auto pin : inputs_) {
		if (pin->name() == name) return pin;
	}
	throw "pin name not found";
}

const OutputPin *Component::get_output_pin(unsigned index) const {
	if (index >= outputs_.size()) throw "pin index out of range";
	return outputs_[index];
}

const OutputPin *Component::get_output_pin(std::string name) const {
	for (auto pin : outputs_) {
		if (pin->name() == name) return pin;
	}
	throw "pin name not found";
}