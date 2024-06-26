#include <gtest/gtest.h>

#include "circuit.h"
#include "connection_spec.h"

#define INPUT PinIdentifierType::INPUT
#define OUTPUT PinIdentifierType::OUTPUT

using namespace construction;
using namespace model;
using namespace std;

class ConnectionSpecTest : public testing::Test {
	protected:
	Component *c1 = new Component("c1", { "in1" }, { "out1" });
	Component *c2 = new Component("c2", { "in1", "in2" }, { "out1" });
	map<string, const Component *> cmap;
	Circuit *circuit;
	ConnectionSpecTest(void) {
		cmap["cc1"] =  c1;
		cmap["cc2"] = c2;
		circuit = new Circuit(
			"circuit",
			move(cmap),
			{ "cin1", "cin2" },
			{ "cout1", "cout2" }
		);
	};
	void assert_interior_in_out(
		const string &outc,
		unsigned outpi,
		const string &inc,
		unsigned inpi)
	{
		auto outp = circuit->get_component(outc)->get_output_pin(outpi);
		auto inp = circuit->get_component(inc)->get_input_pin(inpi);
		EXPECT_EQ((*outp->output_wire())->wire_outputs()[0], inp);
		EXPECT_EQ(*(*inp->input_wire())->wire_input(), outp);
	};
	void assert_interior_in_in(
		const string &in1c,
		unsigned in1pi,
		const string &in2c,
		unsigned in2pi)
	{
		auto in1p = circuit->get_component(in1c)->get_input_pin(in1pi);
		auto in2p = circuit->get_component(in2c)->get_input_pin(in2pi);
		EXPECT_EQ(
			(*in1p->input_wire())->wire_outputs(),
			(*in2p->input_wire())->wire_outputs()
		);
	};
	void assert_out_in(OutputPin *outp, InputPin *inp) {
		EXPECT_EQ((*outp->output_wire())->wire_outputs()[0], inp);
		EXPECT_EQ(*(*inp->input_wire())->wire_input(), outp);
	};
	void assert_in_in(InputPin *in1p, InputPin *in2p) {
		EXPECT_EQ(
			(*in1p->input_wire())->wire_outputs(),
			(*in2p->input_wire())->wire_outputs()
		);

	};
	~ConnectionSpecTest(void) {
		delete circuit;
	}
};

TEST_F(ConnectionSpecTest, InteriorInOut) {
	ConnectionSpec cs = ConnectionSpec(
		PinIdentifier::make_interior("cc1", OUTPUT, 0),
		PinIdentifier::make_interior("cc2", INPUT, 0)
	);
	cs.apply(circuit);

	assert_interior_in_out("cc1", 0, "cc2", 0);
}

TEST_F(ConnectionSpecTest, InteriorInOutReverseArgs) {
	ConnectionSpec cs = ConnectionSpec(
		PinIdentifier::make_interior("cc2", INPUT, 0),
		PinIdentifier::make_interior("cc1", OUTPUT, 0)
	);
	cs.apply(circuit);

	assert_interior_in_out("cc1", 0, "cc2", 0);
}

TEST_F(ConnectionSpecTest, InteriorInOutPinNames) {
	ConnectionSpec cs = ConnectionSpec(
		PinIdentifier::make_interior("cc2", INPUT, "in1"),
		PinIdentifier::make_interior("cc1", OUTPUT, "out1")
	);
	cs.apply(circuit);

	assert_interior_in_out("cc1", 0, "cc2", 0);
}

TEST_F(ConnectionSpecTest, InteriorInIn) {
	ConnectionSpec cs = ConnectionSpec(
		PinIdentifier::make_interior("cc2", INPUT, "in1"),
		PinIdentifier::make_interior("cc1", INPUT, "in1")
	);
	cs.apply(circuit);

	assert_interior_in_in("cc1", 0, "cc2", 0);
}

TEST_F(ConnectionSpecTest, InteriorOutOutException) {
	ConnectionSpec cs = ConnectionSpec(
		PinIdentifier::make_interior("cc2", OUTPUT, "out1"),
		PinIdentifier::make_interior("cc1", OUTPUT, "out1")
	);
	EXPECT_THROW(cs.apply(circuit), string);
}

TEST_F(ConnectionSpecTest, InteriorInInSameComponent) {
	ConnectionSpec cs = ConnectionSpec(
		PinIdentifier::make_interior("cc2", INPUT, "in1"),
		PinIdentifier::make_interior("cc2", INPUT, "in2")
	);
	cs.apply(circuit);

	assert_interior_in_in("cc2", 0, "cc2", 1);
}

TEST_F(ConnectionSpecTest, ExteriorOutInteriorIn) {
	ConnectionSpec cs = ConnectionSpec(
		PinIdentifier::make_exterior(OUTPUT, "cin1"),
		PinIdentifier::make_interior("cc2", INPUT, "in2")
	);
	cs.apply(circuit);

	assert_out_in(
		circuit->get_input_pin("cin1"),
		circuit->get_component("cc2")->get_input_pin("in2")
	);
}

TEST_F(ConnectionSpecTest, InteriorOutExteriorIn) {
	ConnectionSpec cs = ConnectionSpec(
		PinIdentifier::make_exterior(INPUT, "cout1"),
		PinIdentifier::make_interior("cc2", OUTPUT, "out1")
	);
	cs.apply(circuit);

	assert_out_in(
		circuit->get_component("cc2")->get_output_pin("out1"),
		circuit->get_output_pin("cout1")
	);
}

TEST_F(ConnectionSpecTest, ExteriorOutOutException) {
	ConnectionSpec cs = ConnectionSpec(
		PinIdentifier::make_exterior(OUTPUT, "cin1"),
		PinIdentifier::make_exterior(OUTPUT, "cin2")
	);

	EXPECT_THROW(cs.apply(circuit), string);
}

TEST_F(ConnectionSpecTest, ExteriorInIn) {
	ConnectionSpec cs = ConnectionSpec(
		PinIdentifier::make_exterior(INPUT, "cout1"),
		PinIdentifier::make_exterior(INPUT, "cout2")
	);
	cs.apply(circuit);

	assert_in_in(
		circuit->get_output_pin("cout1"),
		circuit->get_output_pin("cout2")
	);
}

TEST_F(ConnectionSpecTest, ConnectAdditionalOutputPinException) {
	ConnectionSpec cs1 = ConnectionSpec(
		PinIdentifier::make_interior("cc2", INPUT, "in2"),
		PinIdentifier::make_interior("cc1", OUTPUT, "out1")
	);
	ConnectionSpec cs2 = ConnectionSpec(
		PinIdentifier::make_interior("cc2", INPUT, "in2"),
		PinIdentifier::make_exterior(OUTPUT, "cin1")
	);
	cs1.apply(circuit);
	EXPECT_THROW(cs2.apply(circuit), string);
}

TEST_F(ConnectionSpecTest, ConnectAdditionalInputPin) {
	ConnectionSpec cs1 = ConnectionSpec(
		PinIdentifier::make_interior("cc2", INPUT, "in2"),
		PinIdentifier::make_interior("cc1", OUTPUT, "out1")
	);
	ConnectionSpec cs2 = ConnectionSpec(
		PinIdentifier::make_interior("cc1", OUTPUT, "out1"),
		PinIdentifier::make_exterior(INPUT, "cout1")
	);
	cs1.apply(circuit);
	cs2.apply(circuit);

	EXPECT_EQ(
		(*circuit->get_component("cc1")->get_output_pin("out1")->output_wire())
			->wire_outputs().size(),
		2
	);
}

TEST_F(ConnectionSpecTest, MergeWiresTwoOutputPinsException) {
	ConnectionSpec cs1 = ConnectionSpec(
		PinIdentifier::make_interior("cc2", INPUT, "in2"),
		PinIdentifier::make_interior("cc1", OUTPUT, "out1")
	);
	ConnectionSpec cs2 = ConnectionSpec(
		PinIdentifier::make_interior("cc2", OUTPUT, "out1"),
		PinIdentifier::make_exterior(INPUT, "cout1")
	);
	ConnectionSpec cs3 = ConnectionSpec(
		PinIdentifier::make_interior("cc2", INPUT, "in2"),
		PinIdentifier::make_exterior(INPUT, "cout1")
	);
	cs1.apply(circuit);
	cs2.apply(circuit);
	EXPECT_THROW(cs3.apply(circuit), string);
}

TEST_F(ConnectionSpecTest, MergeSameWireNoException) {
	ConnectionSpec cs1 = ConnectionSpec(
		PinIdentifier::make_interior("cc2", INPUT, "in2"),
		PinIdentifier::make_interior("cc1", OUTPUT, "out1")
	);
	ConnectionSpec cs2 = ConnectionSpec(
		PinIdentifier::make_interior("cc2", INPUT, "in2"),
		PinIdentifier::make_interior("cc1", OUTPUT, "out1")
	);
	cs1.apply(circuit);
	cs2.apply(circuit);
}