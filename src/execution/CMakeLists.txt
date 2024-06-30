add_library(
	execution
	simulation.cc
)
target_include_directories(
	execution
	PUBLIC
	"${PROJECT_SOURCE_DIR}/src/execution"
)
target_link_libraries(
	execution
	INTERFACE
	logging
	model_backed_simulation
)

add_subdirectory(logging)
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
	logging_testing
	model_testing
)

include(GoogleTest)
gtest_discover_tests(simulation_front_door_test)