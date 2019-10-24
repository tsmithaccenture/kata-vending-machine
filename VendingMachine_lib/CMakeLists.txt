project(VendingMachine_lib)
add_subdirectory(Tests)

set(HEADER_FILES
       VendingMachine.h Product.h)

set(SOURCE_FILES
        VendingMachine.cpp Product.cpp)

add_library(VendingMachine_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})