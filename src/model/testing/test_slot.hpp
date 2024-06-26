#ifndef MODEL__TEST_MODEL__TEST_SLOT_HPP_
#define MODEL__TEST_MODEL__TEST_SLOT_HPP_

#include <vector>

#include "slot.hpp"

namespace model {
namespace test {

	class TestSlot : public Slot {
		public:
		TestSlot(unsigned input_pin_count, unsigned output_pin_count);
		virtual std::span<const InputPin * const> input_pins(void)
			const override;
		virtual std::span<const OutputPin * const> output_pins(void)
			const override;
		~TestSlot(void);
		std::vector<InputPin *> input_pins_;
		std::vector<OutputPin *> output_pins_;
	};

} // test
} // model

#endif