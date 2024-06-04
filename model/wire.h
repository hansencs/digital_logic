#ifndef MODEL__WIRE_H_
#define MODEL__WIRE_H_

#include <optional>
#include <vector>

namespace model {

	class InputPin;
	class OutputPin;

	class Wire {
		public:
		std::optional<const OutputPin *> wire_input(void) const;
		const std::vector<const InputPin *> &wire_outputs(void) const;
		void set_wire_input(const OutputPin *);
		void add_wire_output(const InputPin *);
		
		private:
		std::optional<const OutputPin *> wire_input_;
		std::vector<const InputPin *> wire_outputs_;
	};

} // model

#endif