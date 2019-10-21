project(VendingMachine_lib)

set(HEADER_FILES

        )

set(SOURCE_FILES
        Coin.cpp Quarter.cpp Dime.cpp Nickel.cpp)

add_library(VendingMachine_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})