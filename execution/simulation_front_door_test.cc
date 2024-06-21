#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "model_backed_simulation.h"
#include "test_device.h"
#include "test_model.h"
#include "test_slot.h"

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

TEST_P(SimulationTest, EmptySlot) {
	Slot slot = TestSlot();
	model = new TestModel();
	make_simulation();

	simulation->step();
}

TEST_P(SimulationTest, OneDevice) {
	TestDevice device {};
	model = new TestModel();
	make_simulation();

	simulation->step();
	device.set(Signal::HIGH);
	simulation->step();
}

TEST_P(SimulationTest, TwoDevicesPassThrough) {
	TestDevice device1 {};
	TestDevice device2 {};
	model = new TestModel();
	make_simulation();


	vector<Signal> results = { device2.check() };
	device1.set(Signal::HIGH);
	simulation->step();
	results.push_back(device2.check());

	EXPECT_EQ(
		results,
		vector<Signal>({ Signal::LOW, Signal::HIGH })
	);
}

/*
TEST_P(SimulationTest, TwoDevicesPassThroughOnlyOnStep) {
	TestDevice device1 {};
	TestDevice device2 {};
	model = new TestModel();
	make_simulation();


	vector<Signal> results = { device2.check() };
	device1.set(Signal::HIGH);
	results.push_back(device2.check());
	simulation->step();
	results.push_back(device2.check());

	EXPECT_EQ(
		results,
		vector<Signal>({ Signal::LOW, Signal::LOW, Signal::HIGH })
	);
}
*/
// TODO
// empty slots
// model validation