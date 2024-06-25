#ifndef MODEL__OUTPUT_PIN_HPP_
#define MODEL__OUTPUT_PIN_HPP_

#include <optional>

#include "pin.hpp"

namespace model {
	
	class Wire;

	class OutputPin : public Pin {
		public:
		virtual std::optional<const Wire *> output_wire(void) const = 0;
	};

} // model

#endif