#include <gtest/gtest.h>

#include "circuit_spec.h"
#include "component.h"
#include "component_library.h"
#include "test_component_spec.h"

using namespace construction;
using namespace model;
using namespace std;

class CircuitSpecTest : public testing::Test {
	protected:
	Component *c1 = new Component("c1", { "in1" }, { "out1" });
	Component *c2 = new Component("c2", { "in1" }, { "out1" });
	TestComponentSpec *ts1 = new TestComponentSpec("ts1", c1);
	TestComponentSpec *ts2 = new TestComponentSpec("ts2", c2);
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

#include <iostream>
TEST_F(CircuitSpecTest, ConstructSimpleNoConnections) {
	lib.add_spec(movep(&ts1));
	map<string, string> cnmap;
	cnmap["tabernacle"] = "ts1";
	CircuitSpec spec = CircuitSpec("sut", i_names, o_names, cnmap, {});
	string spec_name = "hoo";
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
	EXPECT_EQ(cmap["tabernacle"], c1);

	delete result;
}

TEST_F(CircuitSpecTest, ConstructSimpleConnection) {
	lib.add_spec(movep(&ts1));
	map<string, string> cnmap;
	cnmap["pendrel"] = "ts1";
	vector<ConnectionSpec> connections = {
		ConnectionSpec(
			PinIdentifier::make_exterior(PinIdentifierType::OUTPUT, "in1"),
			PinIdentifier::make_interior("pendrel", PinIdentifierType::INPUT, "in1")
		)
	};
	CircuitSpec spec = CircuitSpec("sut", i_names, o_names, cnmap, connections); 
	string spec_name = "ugg";
	Circuit *result = spec.construct(&lib, spec_name);

	EXPECT_EQ(
		(*result->get_input_pin("in1")->output_wire())->wire_outputs()[0],
		result->get_component("pendrel")->get_input_pin("in1")
	);
}

TEST_F(CircuitSpecTest, ConstructMultipleChildren) {
	lib.add_spec(movep(&ts1));
	lib.add_spec(movep(&ts2));
	map<string, string> cnmap;
	cnmap["cc1"] = "ts1";
	cnmap["cc2"] = "ts2";
	vector<ConnectionSpec> connections = {
		ConnectionSpec(
			PinIdentifier::make_interior(
				"cc1",
				PinIdentifierType::OUTPUT,
				"out1"
			),
			PinIdentifier::make_interior("cc2", PinIdentifierType::INPUT, "in1")
		)
	};
	CircuitSpec spec = CircuitSpec("sut", i_names, o_names, cnmap, connections); 
	string spec_name = "speec";
	Circuit *result = spec.construct(&lib, spec_name);

	EXPECT_EQ(result->get_component("cc1"), c1);
	EXPECT_EQ(result->get_component("cc2"), c2);
	EXPECT_EQ(
		(*result->get_component("cc1")->get_output_pin("out1")->output_wire())
			->wire_outputs()[0],
		result->get_component("cc2")->get_input_pin("in1")
	);
}