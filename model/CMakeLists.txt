add_library(model model.cc)

enable_testing()

add_executable(model_test model_test.cc)
target_link_libraries(
	model_test
	GTest::gtest_main
	model
)

include(GoogleTest)
gtest_discover_tests(model_test)