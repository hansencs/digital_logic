add_library(
	execution
	model_backed_simulation.cc
	simulation.cc
)
target_include_directories(
	execution
	PUBLIC
	"${PROJECT_SOURCE_DIR}/execution"
)
target_include_directories(
	execution
	PRIVATE
	"${PROJECT_SOURCE_DIR}/model"
)

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