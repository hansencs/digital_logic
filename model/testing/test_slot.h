#ifndef MODEL__TEST_MODEL__TEST_SLOT_H_
#define MODEL__TEST_MODEL__TEST_SLOT_H_

#include <vector>

#include "slot.h"

namespace model {
namespace test {

	class TestSlot : public Slot {
		public:
		TestSlot(unsigned input_pin_count, unsigned output_pin_count);
		virtual std::span<const Pin * const> input_pins(void) const override;
		virtual std::span<const Pin * const> output_pins(void) const override;
		std::vector<Pin *> input_pins_;
		std::vector<Pin *> output_pins_;
	};

} // test
} // model

#endif