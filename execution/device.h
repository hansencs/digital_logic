#ifndef EXECUTION__DEVICE_H_
#define EXECUTION__DEVICE_H_

#include <functional>

#include "execution.h"

namespace execution {

	class Device {
		public:
		virtual std::function<
			void (uint8_t *input_buffer, uint8_t *output_buffer)
		> step_fn(void) = 0;
	};

} // model

#endif