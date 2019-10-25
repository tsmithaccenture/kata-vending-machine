project(Tests)

add_executable(Tests_run VendingMachine.cpp)

target_link_libraries(Tests_run VendingMachine_lib)

target_link_libraries(Tests_run gtest gtest_main)

target_link_libraries(Tests_run gmock gmock_main)