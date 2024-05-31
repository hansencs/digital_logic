#include "model.h"

#include <gtest/gtest.h>

TEST(ModelTest, TestTest) {
	EXPECT_STRNE("hello", "world");
	EXPECT_EQ(7 * 6, 42);
	EXPECT_EQ(model::Model::hi(), 16) << "how did this fail" << std::endl;
}