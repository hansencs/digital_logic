#ifndef EXECUTION__MODEL_BACKED_SIMULATION_H_
#define EXECUTION__MODEL_BACKED_SIMULATION_H_

#include <map>
#include <set>

#include "execution.h"
#include "simulation.h"

namespace model {

	class Component;
	class Model;
	class Nand;
	class Pin;
	class Wire;

} // model

namespace execution {
namespace impl {

	class ModelBackedSimulation : public Simulation {
		public:
		ModelBackedSimulation(const model::Model *);
		virtual void insert_device(const model::Slot *, Device *) override;
		virtual void step(void) override;
		~ModelBackedSimulation(void);

		private:
		void step_nand(const model::Nand *);
		void step_slot(const model::Slot *);
		const model::Model *model_;
		std::set<const model::Component *> discrete_components_;
		std::map<const model::Pin *, Signal> pin_values_;
		std::map<const model::Wire *, Signal> wire_values_;
		std::map<const model::Slot *, std::function<void (uint8_t *, uint8_t *)>> device_map_;
		uint8_t *device_input_buffer_;
		uint8_t *device_output_buffer_;
	};

} // impl
} // execution

#endif