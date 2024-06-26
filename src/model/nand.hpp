#ifndef MODEL__NAND_HPP_
#define MODEL__NAND_HPP_

#include "component.h"

namespace model {

	class Nand : public Component {
		public:
		virtual ComponentType component_type(void) const override;
		virtual const InputPin *nand_left_input(void) const = 0;
		virtual const InputPin *nand_right_input(void) const = 0;
		virtual const OutputPin *nand_output(void) const = 0;
	};

} // model

#endif