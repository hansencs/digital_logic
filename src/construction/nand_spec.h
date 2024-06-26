#ifndef CONSTRUCTION__NAND_SPEC_H_
#define CONSTRUCTION__NAND_SPEC_H_

#include <string>

#include "component_spec.h"

namespace construction {

	class NANDSpec : public ComponentSpec {
		public:
		NANDSpec(const std::string &name);
		virtual model::Component *construct(
			const ComponentLibrary *,
			const std::string &name
		) const override;
	};

} // construction

#endif