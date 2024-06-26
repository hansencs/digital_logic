#ifndef MODEL__DUAL_PIN_H_
#define MODEL__DUAL_PIN_H_

#include "input_pin.h"
#include "output_pin.h"

namespace model {

	class DualPin : public InputPin, public OutputPin {
		public:
		DualPin(const std::string &name, const Component *m);
	};

} // model

#endif