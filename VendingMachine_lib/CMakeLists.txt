project(VendingMachine_lib)

set(HEADER_FILES

        )

set(SOURCE_FILES
        Test.cpp
        )

add_library(VendingMachine_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})