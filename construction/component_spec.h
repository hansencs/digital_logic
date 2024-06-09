#ifndef CONSTRUCTION__COMPONENT_SPEC_H_
#define CONSTRUCTION__COMPONENT_SPEC_H_

#include <string>
#include <vector>

namespace model {

	class Component;

} // model

namespace construction {

	class ComponentLibrary;

	class ComponentSpec {
		public:
		ComponentSpec(const std::string &name);
		const std::string &name(void) const;
		virtual model::Component *construct(
			const ComponentLibrary *,
			const std::string &name
		) const = 0;
		virtual ~ComponentSpec(void) {};

		protected:
		std::string name_;
	};

} // construction

#endif