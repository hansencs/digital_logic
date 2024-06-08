#include <gtest/gtest.h>

#include "pin_identifier.h"

using namespace construction;
using namespace std;

TEST(PinIdentifierTest, InteriorInputPinName) {
	auto pid = PinIdentifier::make_interior(
		"cn",
		PinIdentifierType::INPUT,
		"pn"
	);

	EXPECT_EQ(pid.pin_type(), PinIdentifierType::INPUT);
	EXPECT_TRUE(pid.is_interior());
	EXPECT_EQ(pid.component_name(), "cn");
	EXPECT_TRUE(pid.has_pin_name());
	EXPECT_EQ(pid.pin_name(), "pn");
	EXPECT_THROW(pid.pin_index(), string);
}

TEST(PinIdentifierTest, InteriorInputPinIndex) {
	auto pid = PinIdentifier::make_interior(
		"cn",
		PinIdentifierType::INPUT,
		17
	);

	EXPECT_EQ(pid.pin_type(), PinIdentifierType::INPUT);
	EXPECT_TRUE(pid.is_interior());
	EXPECT_EQ(pid.component_name(), "cn");
	EXPECT_FALSE(pid.has_pin_name());
	EXPECT_THROW(pid.pin_name(), string);
	EXPECT_EQ(pid.pin_index(), 17);
}

TEST(PinIdentifierTest, InteriorOutputPinName) {
	auto pid = PinIdentifier::make_interior(
		"cn",
		PinIdentifierType::OUTPUT,
		"pn"
	);

	EXPECT_EQ(pid.pin_type(), PinIdentifierType::OUTPUT);
	EXPECT_TRUE(pid.is_interior());
	EXPECT_EQ(pid.component_name(), "cn");
	EXPECT_TRUE(pid.has_pin_name());
	EXPECT_EQ(pid.pin_name(), "pn");
	EXPECT_THROW(pid.pin_index(), string);
}

TEST(PinIdentifierTest, InteriorOutputPinIndex) {
	auto pid = PinIdentifier::make_interior(
		"cn",
		PinIdentifierType::OUTPUT,
		17
	);

	EXPECT_EQ(pid.pin_type(), PinIdentifierType::OUTPUT);
	EXPECT_TRUE(pid.is_interior());
	EXPECT_EQ(pid.component_name(), "cn");
	EXPECT_FALSE(pid.has_pin_name());
	EXPECT_THROW(pid.pin_name(), string);
	EXPECT_EQ(pid.pin_index(), 17);
}

TEST(PinIdentifierTest, ExteriorInputPinName) {
	auto pid = PinIdentifier::make_exterior(
		PinIdentifierType::INPUT,
		"pn"
	);

	EXPECT_EQ(pid.pin_type(), PinIdentifierType::INPUT);
	EXPECT_FALSE(pid.is_interior());
	EXPECT_THROW(pid.component_name(), string);
	EXPECT_TRUE(pid.has_pin_name());
	EXPECT_EQ(pid.pin_name(), "pn");
	EXPECT_THROW(pid.pin_index(), string);
}

TEST(PinIdentifierTest, ExteriorInputPinIndex) {
	auto pid = PinIdentifier::make_exterior(
		PinIdentifierType::INPUT,
		17
	);

	EXPECT_EQ(pid.pin_type(), PinIdentifierType::INPUT);
	EXPECT_FALSE(pid.is_interior());
	EXPECT_THROW(pid.component_name(), string);
	EXPECT_FALSE(pid.has_pin_name());
	EXPECT_THROW(pid.pin_name(), string);
	EXPECT_EQ(pid.pin_index(), 17);
}

TEST(PinIdentifierTest, ExteriorOutputPinName) {
	auto pid = PinIdentifier::make_exterior(
		PinIdentifierType::OUTPUT,
		"pn"
	);

	EXPECT_EQ(pid.pin_type(), PinIdentifierType::OUTPUT);
	EXPECT_FALSE(pid.is_interior());
	EXPECT_THROW(pid.component_name(), string);
	EXPECT_TRUE(pid.has_pin_name());
	EXPECT_EQ(pid.pin_name(), "pn");
	EXPECT_THROW(pid.pin_index(), string);
}

TEST(PinIdentifierTest, ExteriorOutputPinIndex) {
	auto pid = PinIdentifier::make_exterior(
		PinIdentifierType::OUTPUT,
		17
	);

	EXPECT_EQ(pid.pin_type(), PinIdentifierType::OUTPUT);
	EXPECT_FALSE(pid.is_interior());
	EXPECT_THROW(pid.component_name(), string);
	EXPECT_FALSE(pid.has_pin_name());
	EXPECT_THROW(pid.pin_name(), string);
	EXPECT_EQ(pid.pin_index(), 17);
}