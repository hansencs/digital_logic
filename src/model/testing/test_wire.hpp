#ifndef MODEL__TESTING__TEST_WIRE_HPP_
#define MODEL__TESTING__TEST_WIRE_HPP_

#include <vector>

#include "input_pin.hpp"
#include "output_pin.hpp"
#include "wire.h"

namespace model {
namespace test {

	class TestWire : public Wire {
		public:
		virtual const OutputPin *input(void) const override;
		virtual std::span<const InputPin * const> outputs(void)
			const override;
		// true = wire input, temp function signature will be replaced by overloads
		void connect_pin(InputPin *);
		void connect_pin(OutputPin *);
		OutputPin *wire_input_;
		std::vector<InputPin *> wire_outputs_;
	};

} // test
} // model

#endif