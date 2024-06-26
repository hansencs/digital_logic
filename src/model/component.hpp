#ifndef MODEL__COMPONENT_HPP_
#define MODEL__COMPONENT_HPP_

#include <span>

namespace model {

	class InputPin;
	class OutputPin;

	enum class ComponentType {
		CIRCUIT,
		NAND,
		SLOT
	};

	class Component {
		public:
		virtual ComponentType component_type(void) const = 0;
		virtual std::span<const InputPin * const> input_pins(void) const = 0;
		virtual std::span<const OutputPin * const> output_pins(void) const = 0;
	};

} // model

#endif