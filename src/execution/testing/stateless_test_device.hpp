#ifndef MODEL__TEST_MODEL__STATELESS_TEST_DEVICE_HPP_
#define MODEL__TEST_MODEL__STATELESS_TEST_DEVICE_HPP_

#include "device.h"

namespace execution {
namespace test {

	typedef void (*step_fn_type)(uint8_t *, uint8_t *);

	class StatelessTestDevice : public Device {
		public:
		StatelessTestDevice(step_fn_type);
		virtual std::function<void (uint8_t *, uint8_t *)> step_fn(void) 
			override;

		private:
		step_fn_type step_fn_;
	};

} // test
} // execution


#endif