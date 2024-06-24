#include "device.h"
#include "model_backed_simulation.h"

using namespace execution;
using namespace execution::impl;

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