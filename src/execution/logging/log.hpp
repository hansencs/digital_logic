#ifndef EXECUTION__LOGGING__LOG_HPP_
#define EXECUTION__LOGGING__LOG_HPP_

namespace execution {
namespace logging {

	class LogEntry;

	class Log {
		public:
		virtual void record(LogEntry *) = 0;
		virtual ~Log(void) {};
	};

} // logging
} // execution

#endif