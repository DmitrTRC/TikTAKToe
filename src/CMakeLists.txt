project(${CMAKE_PROJECT_NAME}_lib)

set(HEADER_FILES
        Game.hpp
        Player.hpp
        Board.hpp
        helper.hpp
        Ai_Player.hpp
        Human_Player.hpp
        Score.hpp
        )

set(SOURCE_FILES
        Game.cpp
        Player.cpp
        Board.cpp
        Ai_Player.cpp
        Human_Player.cpp
        Score.cpp
        )

#set(SOURCE_FILES $(SOURCE_FILES))
message(STATUS "SOURCE_FILES: ${SOURCE_FILES}")


# The library contains header and source files.
add_library(${CMAKE_PROJECT_NAME}_lib STATIC
        ${SOURCE_FILES}
        ${HEADER_FILES}
        )