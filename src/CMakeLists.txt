project(${CMAKE_PROJECT_NAME}_lib)

set(HEADER_FILES
        Game.hpp
        Player.hpp
        Board.hpp
        helper.hpp
        Ai_Player.hpp
        Score.hpp
        Human_Player.hpp
        )

set(SOURCE_FILES
        Game.cpp
        Player.cpp
        Board.cpp
        Ai_Player.cpp
        Score.cpp
        Human_Player.cpp )

#set(SOURCE_FILES $(SOURCE_FILES))
message(STATUS "SOURCE_FILES: ${SOURCE_FILES}")


# The library contains header and source files.
add_library(${CMAKE_PROJECT_NAME}_lib STATIC
        ${SOURCE_FILES}
        ${HEADER_FILES}
        )