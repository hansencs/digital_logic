#include <gtest/gtest.h>

#include "test_component_spec.h"

using namespace construction;
using namespace std;

TEST(ComponentSpecTest, Accessors) {
	string name = "Reremy Jenner";
	TestComponentSpec spec = TestComponentSpec(name, nullptr);

	EXPECT_EQ(spec.name(), name);
}