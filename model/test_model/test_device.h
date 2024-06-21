#ifndef MODEL__TEST_MODEL__TEST_DEVICE_H_
#define MODEL__TEST_MODEL__TEST_DEVICE_H_

#include "device.h"
#include "execution.h"

namespace model {
namespace test {

	class TestDevice : Device {
		public:
		void set(execution::Signal);
	};

} // test
} // model


#endif