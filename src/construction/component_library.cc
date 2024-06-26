#include "component_library.h"
#include "component_spec.h"

using namespace construction;
using namespace model;
using namespace std;

void ComponentLibrary::add_spec(const ComponentSpec *spec) {
	if (library_.find(spec->name()) != library_.end())
		throw "adding duplicate spec name <" + spec->name() + ">";
	library_[spec->name()] = spec;
}

Component *ComponentLibrary::produce(
	const string &spec_name,
	const string &component_name
) const {
	auto it = library_.find(spec_name);
	if (it == library_.end()) throw  "spec name <" + spec_name + "> not found";
	return it->second->construct(this, component_name);
}

ComponentLibrary::~ComponentLibrary(void) {
	for (auto spec : library_) delete spec.second;
}