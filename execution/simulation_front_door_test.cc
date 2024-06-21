#include <gtest/gtest.h>

#include <string>

#include "model_backed_simulation.h"
#include "test_model.h"

using namespace execution;
using namespace execution::impl;
using namespace model;
using namespace model::test;
using namespace std;

class SimulationTest : public testing::TestWithParam<string> {
	protected:
	TestModel *model;
	Simulation *simulation;

	void make_simulation(void) {
		if (GetParam() == "ModelBackedSimulation") {
			simulation = new ModelBackedSimulation();
			return;
		}
		throw string("invalid test parameter");
	};

	~SimulationTest(void) {
		delete simulation;
		delete model;
	}
};

INSTANTIATE_TEST_SUITE_P(
	SimulationFrontDoorTests,
	SimulationTest,
	testing::Values("ModelBackedSimulation")
);

TEST_P(SimulationTest, PlaceHolder) {
	model = new TestModel();
	make_simulation();

	simulation->step();
	simulation->step();
	simulation->step();
}