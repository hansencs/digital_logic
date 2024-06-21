#ifndef EXECUTION__MODEL_BACKED_SIMULATION_H_
#define EXECUTION__MODEL_BACKED_SIMULATION_H_

#include "simulation.h"

namespace execution {
namespace impl {

	class ModelBackedSimulation : public Simulation {
		public:
		virtual void step(void) override;
	};

} // impl
} // execution

#endif