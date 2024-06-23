#ifndef MODEL__TEST_MODEL__TEST_DEVICE_H_
#define MODEL__TEST_MODEL__TEST_DEVICE_H_

#include "device.h"
#include "execution.h"

namespace execution {
namespace test {

	class TestDevice : public Device {
		public:
		void set(Signal);
		Signal check(void) const;
	};

} // test
} // execution


#endif