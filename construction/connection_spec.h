#ifndef CONSTRUCTION__CONNECTION_SPEC_H_
#define CONSTRUCTION__CONNECTION_SPEC_H_

#include "pin_identifier.h"

namespace model {

	class Circuit;

} // model;

namespace construction {

	class ConnectionSpec {
		public:
		ConnectionSpec(PinIdentifier, PinIdentifier);
		void apply(model::Circuit *containing_circuit) const;

		private:
		const PinIdentifier pin1_;
		const PinIdentifier pin2_;
	};

} // construction

#endif