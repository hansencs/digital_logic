add_library(
	execution
	INTERFACE
)
target_include_directories(
	execution
	INTERFACE
	"${PROJECT_SOURCE_DIR}/src/execution"
)
target_link_libraries(
	execution
	INTERFACE
	model_backed_simulation
)

add_subdirectory(model_backed_simulation)
add_subdirectory(testing)

enable_testing()

add_executable(
	simulation_front_door_test
	simulation_front_door_test.cc
)
target_link_libraries(
	simulation_front_door_test
	execution
	execution_testing
	GTest::gtest_main
	model_testing
)

include(GoogleTest)
gtest_discover_tests(simulation_front_door_test)