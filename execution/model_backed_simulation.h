#ifndef EXECUTION__MODEL_BACKED_SIMULATION_H_
#define EXECUTION__MODEL_BACKED_SIMULATION_H_

#include "simulation.h"

namespace execution {
namespace impl {

	class ModelBackedSimulation : public Simulation {
		public:
		virtual void insert_device(const model::Slot *, Device *) override;
		virtual void step(void) override;
	};

} // impl
} // execution

#endif