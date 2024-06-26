#include <gtest/gtest.h>

#include "dual_pin.h"
#include "input_pin.h"
#include "output_pin.h"

using namespace model;
using namespace base_pin;
using namespace std;

class PinTest : public testing::Test {
	protected:
	Component *c = (Component *) 0xbeefcaac;
	string name = "Jatrick";
	Wire w1;
	Wire w2;
};

TEST_F(PinTest, InputPinAccessors) {
	InputPin p = InputPin(name, c);

	EXPECT_EQ(p.component(), c);
	EXPECT_EQ(p.name(), name);
	EXPECT_FALSE(p.input_wire().has_value());

	p.set_input_wire(&w1);

	EXPECT_EQ(*p.input_wire(), &w1);
}

TEST_F(PinTest, OutputPinAccessors) {
	OutputPin p = OutputPin(name, c);

	EXPECT_EQ(p.component(), c);
	EXPECT_EQ(p.name(), name);
	EXPECT_FALSE(p.output_wire().has_value());

	p.set_output_wire(&w1);

	EXPECT_EQ(*p.output_wire(), &w1);
}

TEST_F(PinTest, DualPinAccessors) {
	DualPin p = DualPin(name, c);

	EXPECT_EQ(p.component(), c);
	EXPECT_EQ(p.name(), name);
	EXPECT_FALSE(p.input_wire().has_value());
	EXPECT_FALSE(p.output_wire().has_value());

	p.set_input_wire(&w1);
	p.set_output_wire(&w2);

	EXPECT_EQ(*p.input_wire(), &w1);
	EXPECT_EQ(*p.output_wire(), &w2);
}