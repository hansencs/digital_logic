#ifndef MODEL__OUTPUT_PIN_H_
#define MODEL__OUTPUT_PIN_H_

#include <optional>

#include "base_pin.h"
#include "wire.h"

namespace model {
	
	class Wire;

	class OutputPin : public virtual base_pin::BasePin {
		public:
		OutputPin(const std::string &name, const Component *);
		std::optional<Wire *> output_wire(void) const;
		void set_output_wire(Wire *);

		private:
		std::optional<Wire *> output_wire_;
	};

} // model

#endif