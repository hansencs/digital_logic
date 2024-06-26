#ifndef MODEL__SLOT_HPP_
#define MODEL__SLOT_HPP_

#include "component.hpp"

namespace model {

	class Slot : public Component {
		public:
		virtual ComponentType component_type(void) const override;
		virtual ~Slot(void) override {};
	};

} // model

#endif