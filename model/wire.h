#ifndef MODEL__WIRE_H_
#define MODEL__WIRE_H_

#include <optional>
#include <vector>

namespace model {

	class InputPin;
	class OutputPin;

	class Wire {
		public:
		std::optional<OutputPin *> wire_input(void);
		std::vector<InputPin *> &wire_outputs(void);
		void set_wire_input(OutputPin *);
		void add_wire_output(InputPin *);
		
		private:
		std::optional<OutputPin *> wire_input_;
		std::vector<InputPin *> wire_outputs_;
	};

} // model

#endif