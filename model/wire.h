#ifndef MODEL__WIRE_H_
#define MODEL__WIRE_H_

#include <span>

namespace model {

	class Pin;

	class Wire {
		public:
		virtual std::span<const Pin * const> outputs(void) const = 0;
	};

} // model

#endif