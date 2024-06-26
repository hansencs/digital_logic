#include "component.h"
#include "test_component_spec.h"

using namespace construction;
using namespace model;
using namespace std;

TestComponentSpec::TestComponentSpec(
	const string &name,
	Component *component
) :
	ComponentSpec(name),
	component_(component)
{}

Component *TestComponentSpec::construct(
	const ComponentLibrary *library,
	const string &name
) const {
	Component *temp = *component_;
	component_.reset();
	return temp;
}

TestComponentSpec::~TestComponentSpec(void) {
	if (component_.has_value()) delete *component_;
}