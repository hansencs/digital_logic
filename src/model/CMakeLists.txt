add_library(
	model
	circuit.cc
	model.cc
	nand.cc
	slot.cc
)
target_include_directories(
	model
	PUBLIC
	"${PROJECT_SOURCE_DIR}/src/model"
)

add_subdirectory(testing)

enable_testing()

add_executable(
	model_test
	model_test.cc
)
target_link_libraries(
	model_test
	GTest::gtest_main
	model
	model_testing
)

include(GoogleTest)
gtest_discover_tests(model_test)