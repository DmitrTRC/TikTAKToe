project(${CMAKE_PROJECT_NAME}_lib)

set(HEADER_FILES
        Game.hpp
        player.hpp
        Board.hpp
        helper.hpp
        )

set(SOURCE_FILES
        Game.cpp
        player.cpp
        Board.cpp
        Ai_Player.cpp Ai_Player.hpp Score.cpp Score.hpp)

#set(SOURCE_FILES $(SOURCE_FILES))
message(STATUS "SOURCE_FILES: ${SOURCE_FILES}")


# The library contains header and source files.
add_library(${CMAKE_PROJECT_NAME}_lib STATIC
        ${SOURCE_FILES}
        ${HEADER_FILES}
        )