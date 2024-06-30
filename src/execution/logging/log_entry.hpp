#ifndef EXECUTION__LOGGING__LOG_ENTRY_HPP_
#define EXECUTION__LOGGING__LOG_ENTRY_HPP_

#include <string>

namespace execution {
namespace logging {

	class LogEntry {
		public:
		virtual std::string to_string(void) = 0;
		virtual ~LogEntry(void) {};
	};

} // logging
} // execution

#endif