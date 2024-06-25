#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "model_backed_simulation.h"
#include "test_circuit.h"
#include "test_device.h"
#include "test_model.h"
#include "test_nand.hpp"
#include "test_slot.h"
#include "test_wire.hpp"

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
			simulation = new ModelBackedSimulation(model);
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
	TestSlot *slot = new TestSlot(0, 1);
	model = new TestModel(slot);
	make_simulation();

	simulation->step();
}

TEST_P(SimulationTest, OneDevice) {
	TestDevice device {};
	TestSlot *slot = new TestSlot(0, 1);
	model = new TestModel(slot);
	make_simulation();
	simulation->insert_device(slot, &device);

	simulation->step();
	device.set(Signal::HIGH);
	simulation->step();
}

TEST_P(SimulationTest, TwoDevicesPassThrough) {
	TestSlot *slot1 = new TestSlot(0, 1);
	TestSlot *slot2 = new TestSlot(1, 0);
	TestWire *w1 = new TestWire();
	w1->connect_pin(slot1->output_pins_[0]);
	w1->connect_pin(slot2->input_pins_[0]);
	TestCircuit *circuit = new TestCircuit();
	circuit->components_.push_back(slot1);
	circuit->components_.push_back(slot2);
	model = new TestModel(circuit);
	make_simulation();
	TestDevice device1 {};
	TestDevice device2 {};
	simulation->insert_device(slot1, &device1);
	simulation->insert_device(slot2, &device2);


	device1.set(Signal::HIGH);
	vector<Signal> results = { device2.check() };
	simulation->step();
	results.push_back(device2.check());
	simulation->step();
	results.push_back(device2.check());

	EXPECT_EQ(
		results,
		vector<Signal>({ Signal::LOW, Signal::LOW, Signal::HIGH })
	);
}

TEST_P(SimulationTest, SingleNand) {
	TestSlot *slot1 = new TestSlot(0, 1);
	TestSlot *slot2 = new TestSlot(0, 1);
	TestNand *nand = new TestNand();
	TestSlot *slot3 = new TestSlot(1, 0);
	TestWire *w1 = new TestWire();
	TestWire *w2 = new TestWire();
	TestWire *w3 = new TestWire();
	w1->connect_pin(slot1->output_pins_[0]);
	w1->connect_pin(nand->input_pins_[0]);
	w2->connect_pin(slot2->output_pins_[0]);
	w2->connect_pin(nand->input_pins_[1]);
	w3->connect_pin(nand->output_pin_[0]);
	w3->connect_pin(slot3->input_pins_[0]);
	TestCircuit *circuit = new TestCircuit();
	circuit->components_.push_back(slot1);
	circuit->components_.push_back(slot2);
	circuit->components_.push_back(nand);
	circuit->components_.push_back(slot3);
	model = new TestModel(circuit);
	make_simulation();
	TestDevice device1 {};
	TestDevice device2 {};
	TestDevice device3 {};
	simulation->insert_device(slot1, &device1);
	simulation->insert_device(slot2, &device2);
	simulation->insert_device(slot3, &device3);


	simulation->step();
	simulation->step();
	simulation->step();
	vector<Signal> results = { device3.check() };
	device1.set(Signal::HIGH);
	simulation->step();
	simulation->step();
	simulation->step();
	results.push_back(device3.check());
	device2.set(Signal::HIGH);
	simulation->step();
	simulation->step();
	simulation->step();
	results.push_back(device3.check());
	device1.set(Signal::LOW);
	simulation->step();
	simulation->step();
	simulation->step();
	results.push_back(device3.check());
	device2.set(Signal::LOW);
	simulation->step();
	simulation->step();
	simulation->step();
	results.push_back(device3.check());

	EXPECT_EQ(
		results,
		vector<Signal>({
			Signal::HIGH,
			Signal::HIGH,
			Signal::LOW,
			Signal::HIGH,
			Signal::HIGH
		})
	);
}
// TODO
// empty slots
// model validation
// component handles and slot handles
// device classes, slot types
// unused output pin
// src dir
// hpp 
// model virtual destructors
// rethink pin naming scheme
// logging