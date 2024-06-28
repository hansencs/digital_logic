#ifndef MODEL__TEST_MODEL__TEST_CIRCUIT_HPP_
#define MODEL__TEST_MODEL__TEST_CIRCUIT_HPP_

#include <vector>

#include "circuit.hpp"

namespace model {
namespace test {

	class TestCircuit : public Circuit {
		public:
		TestCircuit(unsigned input_pin_count, unsigned output_pin_count);
		virtual std::span<const InputPin * const> input_pins(void)
			const override;
		virtual std::span<const OutputPin * const> output_pins(void)
			const override;
		virtual std::span<const Component * const> components(void)
			const override;
		~TestCircuit(void);
		std::vector<Component *> components_;
		std::vector<InputPin *> input_pins_;
		std::vector<OutputPin *> interior_input_pins_;
		std::vector<OutputPin *> output_pins_;
		std::vector<InputPin *> interior_output_pins_;
	};

} // test
} // model

#endif