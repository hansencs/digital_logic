#include "nand.h"
#include "nand_spec.h"

using namespace construction;
using namespace model;
using namespace std;

NANDSpec::NANDSpec(const string &name) :
	ComponentSpec(name)
{}

Component *NANDSpec::construct(
	const ComponentLibrary *library,
	const std::string &name
) const {
	return new NAND(name);
}