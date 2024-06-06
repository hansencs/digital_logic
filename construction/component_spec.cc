#include "component_spec.h"

using namespace construction;
using namespace std;

ComponentSpec::ComponentSpec(
	const string &name,
	const std::vector<std::string> &input_names,
	const std::vector<std::string> &output_names
) :
	name_(name),
	inputs_(input_names),
	outputs_(output_names)
{}

const string &ComponentSpec::name(void) const {
	return name_;
}