#ifndef EXECUTION__LOGGING__TESTING__TEST_LOG_HPP_
#define EXECUTION__LOGGING__TESTING__TEST_LOG_HPP_

#include <vector>

#include "log.hpp"

namespace execution {
namespace logging {
namespace test {

	class TestLog : public Log {
		public:
		virtual void record(LogEntry *) override;
		virtual ~TestLog(void) override;
		std::vector<LogEntry *> entries_;
	};

} // test
} // logging
} // execution 

#endif