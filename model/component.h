#ifndef MODEL__COMPONENT_H_
#define MODEL__COMPONENT_H_

#include <span>

namespace model {

	class Pin;

	enum class ComponentType {
		CIRCUIT,
		SLOT
	};

	class Component {
		public:
		virtual ComponentType component_type(void) const = 0;
		virtual std::span<const Pin * const> input_pins(void) const = 0;
		virtual std::span<const Pin * const> output_pins(void) const = 0;
	};

} // model

#endif