#ifndef MODEL__TESTING__TEST_WIRE_HPP_
#define MODEL__TESTING__TEST_WIRE_HPP_

#include <vector>

#include "wire.h"

namespace model {
namespace test {

	class TestPin;

	class TestWire : public Wire {
		public:
		virtual std::span<const Pin * const> outputs(void) const override;
		// true = wire input, temp function signature will be replaced by overloads
		void connect_pin(Pin *, bool);
		std::vector<Pin *> output_pins_;
	};

} // test
} // model

#endif