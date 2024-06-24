#ifndef EXECUTION__MODEL_BACKED_SIMULATION_H_
#define EXECUTION__MODEL_BACKED_SIMULATION_H_

#include <vector> // TODO delete when temp_devices goes

#include "simulation.h"

namespace model {

	class Model;

}

namespace execution {
namespace impl {

	class ModelBackedSimulation : public Simulation {
		public:
		ModelBackedSimulation(const model::Model *);
		virtual void insert_device(const model::Slot *, Device *) override;
		virtual void step(void) override;

		private:
		const model::Model *model_;
		std::vector<Device *> temp_devices_;
	};

} // impl
} // execution

#endif