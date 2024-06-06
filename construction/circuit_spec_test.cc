#include <gtest/gtest.h>

#include "circuit_spec.h"
#include "component_library.h"
#include "test_component_spec.h"

using namespace construction;
using namespace model;
using namespace std;

class CircuitSpecTest : public testing::Test {
	protected:
	Component *fake_c1 = (Component *) 0xfacc1;
	Component *fake_c2 = (Component *) 0xfacc2;
	TestComponentSpec *ts1 = new TestComponentSpec("ts1", fake_c1);
	TestComponentSpec *ts2 = new TestComponentSpec("ts2", fake_c2);
	vector<string> i_names { "in1", "in2" };
	vector<string> o_names { "out1", "out2" };
	ComponentLibrary lib;
	ComponentSpec *movep(TestComponentSpec **p) {
		ComponentSpec *t = *p;
		*p = nullptr;
		return t;
	}
	~CircuitSpecTest(void) {
		if (ts1) delete ts1;
		if (ts2) delete ts2;
	}
};

TEST_F(CircuitSpecTest, ConstructSimpleNoConnections) {
	lib.add_spec(movep(&ts1));
	map<string, string> cnmap;
	cnmap["tabernacle"] = "ts1";
	CircuitSpec spec = CircuitSpec("sut", i_names, o_names, cnmap);
	string spec_name = "hoo boy this project has gotten pretty large already";
	Circuit *result = spec.construct(&lib, spec_name);

	EXPECT_EQ(result->name(), spec_name);
	EXPECT_EQ(result->input_pins().size(), 2);
	EXPECT_EQ(result->input_pins()[0]->name(), "in1");
	EXPECT_EQ(result->input_pins()[1]->name(), "in2");
	EXPECT_EQ(result->output_pins().size(), 2);
	EXPECT_EQ(result->output_pins()[0]->name(), "out1");
	EXPECT_EQ(result->output_pins()[1]->name(), "out2");

	auto cmap = result->component_map();
	EXPECT_EQ(cmap.size(), 1);
	EXPECT_EQ(cmap["tabernacle"], fake_c1);

	delete result;
}