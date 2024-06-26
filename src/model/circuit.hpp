#ifndef MODEL__CIRCUIT_HPP_
#define MODEL__CIRCUIT_HPP_

#include <span>
#include <string>

#include "component.hpp"

namespace model {

	class OutputPin;

	class Circuit : public Component {
		public:
		virtual ComponentType component_type(void) const override;
		virtual std::span<const Component * const> components(void) const = 0;
		virtual const OutputPin *get_interior_input_pin(
			std::string pin_name
		) const = 0;
		virtual ~Circuit(void) override {};
	};

} // model

#endif