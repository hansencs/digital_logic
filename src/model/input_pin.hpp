#ifndef MODEL__INPUT_PIN_HPP_
#define MODEL__INPUT_PIN_HPP_

#include "pin.hpp"

namespace model {

	class Wire;

	class InputPin : public Pin {
		public:
		virtual const Wire *input_wire(void) const = 0;
		virtual ~InputPin(void) override {};
	};

} // model

#endif