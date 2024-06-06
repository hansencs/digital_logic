#ifndef CONSTRUCTION__CIRCUIT_SPEC_H_
#define CONSTRUCTION__CIRCUIT_SPEC_H_

#include <map>
#include <vector>

#include "circuit.h"
#include "component_spec.h"

namespace construction {

	class CircuitSpec : public ComponentSpec {
		public:
		CircuitSpec(
			const std::string &name,
			const std::vector<std::string> &input_names,
			const std::vector<std::string> &output_names,
			const std::map<std::string, std::string> &components
		);
		virtual model::Circuit *construct(
			const ComponentLibrary *,
			const std::string &name
		) const override;

		private:
		std::map<std::string, std::string> components_;
	};

} // construction

#endif