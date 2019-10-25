cmake_minimum_required(VERSION 3.14)
project(testing_test)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)
add_executable(VendingMachine_run ${SOURCE_FILES})

include_directories(VendingMachine_lib)
add_subdirectory(VendingMachine_lib)

target_link_libraries(VendingMachine_run VendingMachine_lib)

add_subdirectory(Google_tests)
add_subdirectory(E2E_tests)