#ifndef EXECUTION__SIMULATION_H_
#define EXECUTION__SIMULATION_H_

namespace execution {

	class Simulation {
		public:
		virtual void step(void) = 0;
		virtual ~Simulation(void);
	};

} // execution

#endif