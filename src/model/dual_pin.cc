#include "dual_pin.h"

using namespace model;
using namespace std;

DualPin::DualPin(const string &name, const Component *component) :
	InputPin(name, component), OutputPin(name, component)
{}