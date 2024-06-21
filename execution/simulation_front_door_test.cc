#include <gtest/gtest.h>

#include <string>

#include "simulation.h"

using namespace std;

class SimulationTest : public testing::TestWithParam<string> {
	protected:

};

INSTANTIATE_TEST_SUITE_P(
	SimulationFrontDoorTests,
	SimulationTest,
	testing::Values("placeholder")
);


TEST_P(SimulationTest, PlaceHolder) {
}