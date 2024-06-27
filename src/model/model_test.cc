#include <gtest/gtest.h>

#include "test_slot.hpp"
#include "test_model.hpp"

using namespace model;
using namespace model::test;

TEST(ModelTest, ValidateNoPins) {
	TestSlot *slot = new TestSlot(0, 0);
	TestModel model = TestModel(slot);

	static_cast<Model *>(&model)->validate();
}