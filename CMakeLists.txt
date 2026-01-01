cmake_minimum_required(VERSION 3.10)
project(test_boost)

# Print Boost search paths
message(STATUS "Looking for Boost...")

set(BOOST_ROOT "C:/Dima/CPP/boost_1_82_0")  # or "C:/boost"
set(BOOST_INCLUDEDIR "${BOOST_ROOT}/boost")
set(BOOST_LIBRARYDIR "${BOOST_ROOT}/stage/lib")

#  Try to find Boost
set(Boost_DEBUG ON)  # Enable debug output
find_package(Boost 1.82 REQUIRED COMPONENTS )

if(Boost_FOUND)
    message(STATUS "Boost found!")
    message(STATUS "  Version: ${Boost_VERSION}")
    message(STATUS "  Includes: ${Boost_INCLUDE_DIRS}")
    message(STATUS "  Libraries: ${Boost_LIBRARIES}")
else()
    message(FATAL_ERROR "Boost NOT found! Install: sudo apt install libboost-all-dev")
endif()

add_executable(test_boost main.cpp)
add_library(test_lib lib.cpp)

target_include_directories(test_boost PRIVATE ${Boost_INCLUDE_DIRS})

set_target_properties(test_boost test_lib PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(test_boost PRIVATE test_lib )
target_link_libraries(test_boost ${Boost_LIBRARIES})

target_compile_options(test_boost PRIVATE -Wall -Wextra -pedantic -Werror )
target_compile_options(test_lib PRIVATE -Wall -Wextra -pedantic -Werror )
