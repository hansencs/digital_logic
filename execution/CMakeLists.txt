enable_testing()

add_executable(
	simulation_front_door_test
	simulation_front_door_test.cc
)
target_link_libraries(
	simulation_front_door_test
	GTest::gtest_main
)
target_include_directories(
	simulation_front_door_test
	PRIVATE
	"${PROJECT_SOURCE_DIR}/model"
)


include(GoogleTest)
gtest_discover_tests(simulation_front_door_test)