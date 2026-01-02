cmake_minimum_required(VERSION 4.0)

project(game_of_life C)

set(CMAKE_C_STANDARD 23)

add_executable(game_of_life)

target_sources(game_of_life
    PRIVATE
        main.c
        gameoflife.c
        gameoflife.h
)
find_package(raylib REQUIRED)
target_link_libraries(game_of_life PRIVATE raylib)

