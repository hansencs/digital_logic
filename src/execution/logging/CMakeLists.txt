add_library(
	logging
	INTERFACE
)
target_include_directories(
	logging
	INTERFACE
	"${PROJECT_SOURCE_DIR}/src/execution/logging"
)

add_subdirectory(
	testing
)