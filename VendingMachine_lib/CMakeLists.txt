project(VendingMachine_lib)
add_subdirectory(Tests)

set(HEADER_FILES

        )

set(SOURCE_FILES
        TestClass.cpp
        )

add_library(VendingMachine_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})