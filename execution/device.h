#ifndef EXECUTION__DEVICE_H_
#define EXECUTION__DEVICE_H_

namespace execution {

	class Device {
		public:
		virtual void step(void) = 0;
	};

} // model

#endif