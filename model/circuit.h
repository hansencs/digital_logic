#ifndef MODEL__CIRCUIT_H_
#define MODEL__CIRCUIT_H_

#include <span>
#include <string>

#include "component.h"

namespace model {

	class Circuit : public Component {
		public:
		virtual ComponentType component_type(void) const override;
		virtual std::span<const Component * const> components(void) const = 0;
		virtual const Pin *get_interior_output_pin(
			std::string pin_name
		) const = 0;
	};

} // model

#endif