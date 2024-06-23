#include "test_model.h"

using namespace model;
using namespace model::test;

TestModel::TestModel(const Component *top_level_component)
	: top_level_component_(top_level_component)
{}

void TestModel::insert_device(const Slot *slot, Device *device) {
	slot_device_map_[slot] = device;
}