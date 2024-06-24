#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "model_backed_simulation.h"
#include "test_circuit.h"
#include "test_device.h"
#include "test_model.h"
#include "test_slot.h"

using namespace execution;
using namespace execution::impl;
using namespace execution::test;
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
	Slot *slot = new TestSlot();
	model = new TestModel(slot);
	make_simulation();

	simulation->step();
}

TEST_P(SimulationTest, OneDevice) {
	TestDevice device {};
	Slot *slot = new TestSlot();
	model = new TestModel(slot);
	make_simulation();
	simulation->insert_device(slot, &device);

	simulation->step();
	device.set(Signal::HIGH);
	simulation->step();
}

TEST_P(SimulationTest, TwoDevicesPassThrough) {
	TestDevice device1 {};
	TestDevice device2 {};
	Slot *slot1 = new TestSlot();
	Slot *slot2 = new TestSlot();
	Circuit *circuit = new TestCircuit();
	model = new TestModel(circuit);
	make_simulation();
	simulation->insert_device(slot1, &device1);
	simulation->insert_device(slot2, &device2);


	vector<Signal> results = { device2.check() };
	device1.set(Signal::HIGH);
	simulation->step();
	results.push_back(device2.check());

	EXPECT_EQ(
		results,
		vector<Signal>({ Signal::LOW, Signal::HIGH })
	);
}

TEST_P(SimulationTest, TwoDevicesPassThroughRequiresStep) {
	TestDevice device1 {};
	TestDevice device2 {};
	Slot *slot1 = new TestSlot();
	Slot *slot2 = new TestSlot();
	Circuit *circuit = new TestCircuit();
	model = new TestModel(circuit);
	make_simulation();
	simulation->insert_device(slot1, &device1);
	simulation->insert_device(slot2, &device2);


	vector<Signal> results = { device2.check() };
	device1.set(Signal::HIGH);
	results.push_back(device2.check());

	EXPECT_EQ(
		results,
		vector<Signal>({ Signal::LOW, Signal::LOW })
	);
}

// TODO
// empty slots
// model validation
// component handles and slot handles
// device classes, slot types