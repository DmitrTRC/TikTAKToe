cmake_minimum_required(VERSION 3.22)

project(Tic)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(include)

find_package(Curses REQUIRED)
if (NOT CURSES_FOUND)
    message(FATAL_ERROR "Curses not found")
else ()
    message(STATUS "Curses found")
    include_directories(${CURSES_INCLUDE_DIR})
endif ()

add_executable(Tic
               App/main.cpp
               src/processing.cpp
               src/rendering.cpp
               src/helper.cpp
               )

target_link_libraries(Tic ${CURSES_LIBRARIES})

