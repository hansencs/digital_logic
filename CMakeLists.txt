# arbitary cmake version requirement because build systems are confusing
cmake_minimum_required(VERSION 3.27)

project(DigitalLogic)

# require c++ 14 for GoogleTest
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(Go go.cpp)

add_subdirectory(model)

target_link_libraries(Go Model)

target_include_directories(
	Go
	PUBLIC
	"${PROJECT_SOURCE_DIR}/model"
)

enable_testing()

add_executable(
  hello_test
  hello_test.cc
)
target_link_libraries(
  hello_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)