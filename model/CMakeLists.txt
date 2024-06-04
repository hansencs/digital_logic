add_library(
	model
	base_pin.cc
	circuit.cc
	component.cc
	dual_pin.cc
	input_pin.cc
	model.cc
	output_pin.cc
	wire.cc
)

enable_testing()

add_executable(circuit_test circuit_test.cc)
target_link_libraries(
	circuit_test
	GTest::gtest_main
	model
)
add_executable(component_test component_test.cc)
target_link_libraries(
	component_test
	GTest::gtest_main
	model
)
add_executable(model_test model_test.cc)
target_link_libraries(
	model_test
	GTest::gtest_main
	model
)
add_executable(pin_test pin_test.cc)
target_link_libraries(
	pin_test
	GTest::gtest_main
	model
)
add_executable(wire_test wire_test.cc)
target_link_libraries(
	wire_test
	GTest::gtest_main
	model
)

include(GoogleTest)
gtest_discover_tests(circuit_test)
gtest_discover_tests(component_test)
gtest_discover_tests(model_test)
gtest_discover_tests(pin_test)
gtest_discover_tests(wire_test)