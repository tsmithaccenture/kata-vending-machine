project(VendingMachine_lib)
add_subdirectory(Tests)

set(HEADER_FILES
       VendingMachine.h)

set(SOURCE_FILES
        VendingMachine.cpp)

add_library(VendingMachine_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})