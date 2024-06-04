#include <gtest/gtest.h>

#include "input_pin.h"
#include "output_pin.h"
#include "wire.h"

using namespace model;

class WireTest : public testing::Test {
	protected:
	Wire w;
	Component *c = (Component *) 0xffffffffff;
	OutputPin op1 = OutputPin("o1", c);
	InputPin ip1 = InputPin("i1", c);
};

TEST_F(WireTest, Accessors) {
	EXPECT_FALSE(w.wire_input().has_value());
	EXPECT_EQ(w.wire_outputs().size(), 0);

	w.set_wire_input(&op1);
	EXPECT_EQ(w.wire_input(), &op1);
	
	w.add_wire_output(&ip1);
	EXPECT_EQ(w.wire_outputs()[0], &ip1);

	EXPECT_THROW(w.set_wire_input(&op1), const char *);
	EXPECT_THROW(w.add_wire_output(&ip1), const char *);
}