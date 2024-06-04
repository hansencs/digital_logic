#ifndef MODEL__PIN_FACTORY_H_
#define MODEL__PIN_FACTORY_H_

#include <string>

#include "input_pin.h"
#include "output_pin.h"

namespace model {

	class PinFactory {
		public:
		virtual InputPin *make_input_pin(Component *, std::string) const = 0;
		virtual OutputPin *make_output_pin(Component *, std::string) const = 0;
	};

} // model

#endif