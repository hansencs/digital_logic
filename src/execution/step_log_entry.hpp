#ifndef EXECUTION__STEP_LOG_ENTRY_HPP_
#define EXECUTION__STEP_LOG_ENTRY_HPP_

#include "log_entry.hpp"

namespace execution {
namespace logging {

	class StepLogEntry : public LogEntry {
		public:
		virtual std::string to_string(void) override;
	};

} // logging
} // execution

#endif