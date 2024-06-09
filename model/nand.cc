#include "nand.h"

using namespace model;
using namespace std;

NAND::NAND(const string &name) :
	Component(name, { "left", "right" }, { "out" })
{}