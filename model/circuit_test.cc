#include <gtest/gtest.h>

#include "circuit.h"

using namespace model;
using namespace std;

class CircuitTest : public testing::Test {
	protected:
	string name = "short";
	map<string, const Component *> component_map;
	string n1 = "c1";
	Component *comp1 = (Component *) 0xadd5ecc5;
	string n2 = "c2";
	Component *comp2 = (Component *) 0x10dbd;
	vector<string> input_names { "in1", "in2" };
	vector<string> output_names { "out1", "out2" };
	Circuit *c;

	CircuitTest(void) {
		component_map[n1] = comp1;
		component_map[n2] = comp2;
		c = new Circuit(name, component_map, input_names, output_names);
	}

	~CircuitTest(void) {
		delete c;
	}
};

TEST_F(CircuitTest, Accessors) {
	EXPECT_EQ(c->get_component("c2"), comp2);
	EXPECT_TRUE(c->get_input_pin(0));
	
	EXPECT_THROW(c->get_component("oh hi mark"), const char *);
	EXPECT_THROW(c->get_input_pin(2), const char *);
}

TEST_F(CircuitTest, PinInitialization) {
	const DualPin *p = c->get_input_pin(0);
	EXPECT_EQ(p->component(), c);
	EXPECT_EQ(p->name(), "in1");
	EXPECT_FALSE(p->input_wire().has_value());
	EXPECT_FALSE(p->output_wire().has_value());

	p = c->get_output_pin("out2");
	EXPECT_EQ(p->component(), c);
	EXPECT_EQ(p->name(), "out2");
	EXPECT_FALSE(p->input_wire().has_value());
	EXPECT_FALSE(p->output_wire().has_value());
}