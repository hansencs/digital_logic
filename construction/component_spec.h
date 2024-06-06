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
		ComponentSpec(
			const std::string &name,
			const std::vector<std::string> &input_names,
			const std::vector<std::string> &output_names
		);
		const std::string &name(void) const;
		virtual model::Component *construct(
			const ComponentLibrary *,
			const std::string &name
		) const = 0;
		virtual ~ComponentSpec(void) {};

		protected:
		std::string name_;
		std::vector<std::string> inputs_;
		std::vector<std::string> outputs_;
	};

} // construction

#endif