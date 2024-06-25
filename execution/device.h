#ifndef EXECUTION__DEVICE_H_
#define EXECUTION__DEVICE_H_

#include "execution.h"

namespace execution {

	class Device {
		public:
		virtual Signal step(Signal) = 0;
	};

} // model

#endif