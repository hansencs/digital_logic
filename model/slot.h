#ifndef MODEL__SLOT_H_
#define MODEL__SLOT_H_

#include "component.h"

namespace model {

	class Slot : public Component {
		public:
		virtual ComponentType component_type(void) const override;
	};

} // model

#endif