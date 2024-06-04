#ifndef MODEL__INPUT_PIN_H_
#define MODEL__INPUT_PIN_H_

#include <optional>

#include "base_pin.h"

namespace model {

	class Wire;

	class InputPin : public virtual base_pin::BasePin {
		public:
		InputPin(const std::string &name, const Component *);
		std::optional<const Wire *> input_wire(void) const;
		void set_input_wire(const Wire *);

		private:
		std::optional<const Wire *> input_wire_;
	};

} // model

#endif