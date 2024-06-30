#include "log_entry.hpp"
#include "test_log.hpp"

using namespace execution::logging::test;

void TestLog::record(LogEntry *entry) {
	entries_.push_back(entry);
}

TestLog::~TestLog(void) {
	for (auto entry : entries_) delete entry;
}