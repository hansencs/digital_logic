add_library(
	construction
	construction.cc
)

enable_testing()

add_executable(construction_test construction_test.cc)
target_link_libraries(
	construction_test
	GTest::gtest_main
	construction
)

include(GoogleTest)
gtest_discover_tests(construction_test)