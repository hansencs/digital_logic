#include <gtest/gtest.h>

#include "component.h"

using namespace model;
using namespace std;

class ComponentTest : public testing::Test {
	protected:
	string name = "Ravid Dodgers";
	vector<string> input_names { "in1", "in2" };
	vector<string> output_names { "out1", "out2" };
	Component c = Component(name, input_names, output_names);
};

TEST_F(ComponentTest, Accessors) {
	EXPECT_EQ(c.name(), name);
	EXPECT_EQ(c.get_input_pin(1), c.get_input_pin("in2"));
	EXPECT_EQ(c.get_output_pin(0), c.get_output_pin("out1"));
	
	EXPECT_THROW(c.get_input_pin(2), const char *);
	EXPECT_THROW(c.get_output_pin(2), const char *);
	EXPECT_THROW(c.get_input_pin("out1"), const char *);
	EXPECT_THROW(c.get_output_pin("jeremiah whhhhyyyyyyyy"), const char *);
}

TEST_F(ComponentTest, PinInitialization) {
	const InputPin *ip = c.get_input_pin(0);
	EXPECT_EQ(ip->component(), &c);
	EXPECT_EQ(ip->name(), "in1");
	EXPECT_FALSE(ip->input_wire().has_value());

	const OutputPin *op = c.get_output_pin(1);
	EXPECT_EQ(op->component(), &c);
	EXPECT_EQ(op->name(), "out2");
	EXPECT_FALSE(op->output_wire().has_value());
}