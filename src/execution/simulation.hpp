#ifndef EXECUTION__SIMULATION_HPP_
#define EXECUTION__SIMULATION_HPP_

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
		void register_log_step(logging::Log *);
		virtual void insert_device(const model::Slot *, Device *) = 0;
		virtual void step(void) = 0;
		virtual ~Simulation(void) {};
	};

} // execution

#endif