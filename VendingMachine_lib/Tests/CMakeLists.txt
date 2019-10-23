project(Tests)

add_executable(Tests_run SimpleUnitTest.cpp VendingMachine.cpp)

target_link_libraries(Tests_run VendingMachine_lib)

target_link_libraries(Tests_run gtest gtest_main)