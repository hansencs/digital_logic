#include "device.h"
#include "model.h"
#include "model_backed_simulation.h"

using namespace execution;
using namespace execution::impl;
using namespace model;

ModelBackedSimulation::ModelBackedSimulation(const Model *model) : model_(model)
{}

void ModelBackedSimulation::insert_device(
	const model::Slot *slot,
	Device *device
) {
	temp_devices_.push_back(device);
}

void ModelBackedSimulation::step(void) {
	for (auto device : temp_devices_) {
		device->step();
	}
}