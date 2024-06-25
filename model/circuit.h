#ifndef MODEL__CIRCUIT_H_
#define MODEL__CIRCUIT_H_

#include <span>
#include <string>

#include "component.h"

namespace model {

	class OutputPin;

	class Circuit : public Component {
		public:
		virtual ComponentType component_type(void) const override;
		virtual std::span<const Component * const> components(void) const = 0;
		virtual const OutputPin *get_interior_input_pin(
			std::string pin_name
		) const = 0;
	};

} // model

#endif