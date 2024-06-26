#ifndef EXECUTION__EXECUTION_H_
#define EXECUTION__EXECUTION_H_

#include <cinttypes>

#define SIGNAL_TO_BYTE(s) static_cast<uint8_t>(s)
#define BYTE_TO_SIGNAL(b) static_cast<execution::Signal>(b)

namespace execution {

	enum class Signal : uint8_t {
		LOW = 0,
		HIGH = 1,
	};

} // execution

#endif