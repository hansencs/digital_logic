#include "test_component_spec.h"

using namespace construction;
using namespace model;
using namespace std;

TestComponentSpec::TestComponentSpec(
	const string &name,
	Component *component
) :
	ComponentSpec(name, {}, {}),
	component_(component)
{}

Component *TestComponentSpec::construct(
	const ComponentLibrary *library,
	const string &name
) const {
	return component_;
}