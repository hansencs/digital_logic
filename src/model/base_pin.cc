#include "base_pin.h"

using namespace model;
using namespace model::base_pin;
using namespace std;

const Component *BasePin::component(void) const {
	return component_;
}

const string &BasePin::name(void) const {
	return name_;
}