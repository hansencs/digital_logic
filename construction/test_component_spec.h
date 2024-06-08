#ifndef CONSTRUCTION__TEST_COMPONENT_SPEC
#define CONSTRUCTION__TEST_COMPONENT_SPEC

#include <optional>

#include "component_spec.h"

namespace construction {

	class TestComponentSpec : public ComponentSpec {
		public:
		TestComponentSpec(
			const std::string &name,
			model::Component *component
		);
		virtual model::Component *construct(
			const ComponentLibrary *library,
			const std::string &name
		) const override;
		~TestComponentSpec(void);

		private:
		mutable std::optional<model::Component *> component_;
	};

} // construction

#endif