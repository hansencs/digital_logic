cmake_minimum_required(VERSION 3.27)

project(DigitalLogic)

add_executable(Go go.cpp)

add_subdirectory(model)

target_link_libraries(Go Model)

target_include_directories(Go PUBLIC "${PROJECT_SOURCE_DIR}/model")