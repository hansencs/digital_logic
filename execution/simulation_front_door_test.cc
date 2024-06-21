#include <gtest/gtest.h>

#include <string>

#include "test_model.h"
#include "simulation.h"

using namespace execution;
using namespace model;
using namespace model::test;
using namespace std;

class SimulationTest : public testing::TestWithParam<string> {
	protected:
	TestModel *model;

	Simulation *make_simulation(Model *model) {
		return nullptr;
	};

	~SimulationTest(void) {
		delete model;
	}
};

INSTANTIATE_TEST_SUITE_P(
	SimulationFrontDoorTests,
	SimulationTest,
	testing::Values("placeholder")
);


TEST_P(SimulationTest, PlaceHolder) {
	model = new TestModel();
	make_simulation(model);
}