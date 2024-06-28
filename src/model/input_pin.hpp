#ifndef MODEL__INPUT_PIN_HPP_
#define MODEL__INPUT_PIN_HPP_

#include <optional>

#include "pin.hpp"

namespace model {

	class OutputPin;
	class Wire;

	class InputPin : public Pin {
		public:
		virtual const Wire *input_wire(void) const = 0;
		virtual std::optional<const OutputPin *> dual(void) const;
		virtual ~InputPin(void) override {};
	};

} // model

#endif