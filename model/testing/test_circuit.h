#ifndef MODEL__TEST_MODEL__TEST_CIRCUIT_H_
#define MODEL__TEST_MODEL__TEST_CIRCUIT_H_

#include <vector>

#include "circuit.h"

namespace model {
namespace test {

	class TestPin;

	class TestCircuit : public Circuit {
		public:
		TestCircuit();
		virtual std::span<const Pin * const> input_pins(void) const override;
		virtual std::span<const Pin * const> output_pins(void) const override;
		virtual std::span<const Component * const> components(void)
			const override;
		virtual const Pin *get_interior_output_pin(std::string pin_name)
			const override;
		std::vector<Component *> components_;
		std::vector<Pin *> input_pins_;
		std::vector<Pin *> output_pins_;
		std::vector<Pin *> interior_output_pins_;
	};

} // test
} // model

#endif