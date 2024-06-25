#ifndef MODEL__TEST_MODEL__TEST_DEVICE_H_
#define MODEL__TEST_MODEL__TEST_DEVICE_H_

#include "device.h"

namespace execution {
namespace test {

	class TestDevice : public Device {
		public:
		TestDevice(void);
		virtual Signal step(Signal, bool) override;
		void set(Signal);
		Signal check(void) const;

		private:
		Signal temp_s_;
	};

} // test
} // execution


#endif