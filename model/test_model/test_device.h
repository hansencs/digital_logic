#ifndef MODEL__TEST_MODEL__TEST_DEVICE_H_
#define MODEL__TEST_MODEL__TEST_DEVICE_H_

#include "device.h"
#include "execution.h"

namespace model {
namespace test {

	class TestDevice : public Device {
		public:
		void set(execution::Signal);
		execution::Signal check(void) const;
	};

} // test
} // model


#endif