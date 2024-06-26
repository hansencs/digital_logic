#ifndef MODEL__TESTING__TEST_NAND_HPP_
#define MODEL__TESTING__TEST_NAND_HPP_

#include <vector>

#include "nand.hpp"

namespace model {
namespace test {

	class TestNand : public Nand {
		public:
		TestNand(void);
		virtual std::span<const InputPin * const> input_pins(void) const override;
		virtual std::span<const OutputPin * const> output_pins(void) const override;
		virtual const InputPin *nand_left_input(void) const override;
		virtual const InputPin *nand_right_input(void) const override;
		virtual const OutputPin *nand_output(void) const override;
		~TestNand(void);
		std::vector<InputPin *> input_pins_;
		std::vector<OutputPin *> output_pin_;
	};

} // test
} // model

#endif