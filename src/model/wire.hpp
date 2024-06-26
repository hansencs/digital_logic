#ifndef MODEL__WIRE_HPP_
#define MODEL__WIRE_HPP_

#include <span>

namespace model {

	class InputPin;
	class OutputPin;

	class Wire {
		public:
		virtual const OutputPin *input(void) const = 0;
		virtual std::span<const InputPin * const> outputs(void) const = 0;
		virtual ~Wire(void) {};
	};

} // model

#endif