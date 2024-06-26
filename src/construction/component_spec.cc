#include "component_spec.h"

using namespace construction;
using namespace std;

ComponentSpec::ComponentSpec(const string &name) :
	name_(name)
{}

const string &ComponentSpec::name(void) const {
	return name_;
}