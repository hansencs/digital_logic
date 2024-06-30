#ifndef EXECUTION__SIMULATION_HPP_
#define EXECUTION__SIMULATION_HPP_

#include <vector>

namespace model {

	class Slot;

} // model

namespace execution {

	class Device;

	namespace logging {

		class Log;

	} // logging

	class Simulation {
		public:
		virtual void insert_device(const model::Slot *, Device *) = 0;
		virtual void step(void) = 0;
		virtual void register_log_step(logging::Log *) = 0;
		virtual ~Simulation(void) {};

		private:
		std::vector<logging::Log *> step_logs_;
	};

} // execution

#endif