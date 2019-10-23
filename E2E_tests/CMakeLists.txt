project(E2E_tests)

add_executable(E2E_tests_run SimpleTest.cpp)

target_link_libraries(E2E_tests_run VendingMachine_lib)

target_link_libraries(E2E_tests_run gtest gtest_main)