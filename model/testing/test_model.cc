#include "test_model.h"

using namespace model;
using namespace model::test;

TestModel::TestModel(const Component *top_level_component)
	: top_level_component_(top_level_component)
{}

const Component *TestModel::top_level_component(void) const {
	return top_level_component_;
}