#ifndef MODEL__TEST_MODEL__TEST_DEVICE_H_
#define MODEL__TEST_MODEL__TEST_DEVICE_H_

#include "device.h"
#include "execution.h"

namespace execution {
namespace test {

	class TestDevice : public Device {
		public:
		TestDevice(void);
		virtual void step(void) override;
		void set(Signal);
		Signal check(void) const;

		private:
		Signal temp_s_;
	};

} // test
} // execution


#endif