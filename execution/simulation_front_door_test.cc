#include <gtest/gtest.h>

#include <string>

#include "model.h"
#include "simulation.h"

using namespace execution;
using namespace model;
using namespace std;

class SimulationTest : public testing::TestWithParam<string> {
	protected:
	Simulation *make_simulation(Model *model) {
		return nullptr;
	};
};

INSTANTIATE_TEST_SUITE_P(
	SimulationFrontDoorTests,
	SimulationTest,
	testing::Values("placeholder")
);


TEST_P(SimulationTest, PlaceHolder) {
	Model *model = nullptr;
	make_simulation(model);
}