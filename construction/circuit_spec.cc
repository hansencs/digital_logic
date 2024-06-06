#include "circuit_spec.h"
#include "component_library.h"

using namespace construction;
using namespace model;
using namespace std;

CircuitSpec::CircuitSpec(
	const string &name,
	const vector<string> &input_names,
	const vector<string> &output_names,
	const map<string, string> &components
) :
	ComponentSpec(name, input_names, output_names),
	components_(components)
{}

Circuit *CircuitSpec::construct(
	const ComponentLibrary *library,
	const string &name
) const {
	map<string, const Component *> constructed_children;
	for (auto name_type_pair : components_) {
		constructed_children[name_type_pair.first] = library->produce(
			name_type_pair.second,
			name_type_pair.first
		);
	}
	return new Circuit(name, constructed_children, inputs_, outputs_);
}