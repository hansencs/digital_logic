#ifndef MODEL__TEST_MODEL__MANUAL_TEST_DEVICE_HPP_
#define MODEL__TEST_MODEL__MANUAL_TEST_DEVICE_HPP_

#include <vector>

#include "device.h"

namespace execution {
namespace test {

	class ManualTestDevice : public Device {
		public:
		ManualTestDevice(unsigned input_pins, unsigned output_pins);
		virtual std::function<void (uint8_t *, uint8_t *)> step_fn(void)
			override;
		void set(unsigned pin_index, Signal);
		Signal check(unsigned pin_index) const;

		private:
		static void step_functor(ManualTestDevice *, uint8_t *, uint8_t *);
		std::vector<Signal> inputs_;
		std::vector<Signal> outputs_;
	};

} // test
} // execution


#endif