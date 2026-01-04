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
include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
    GIT_TAG "5.5"
)
FetchContent_MakeAvailable(raylib)
set(PLATFORM PLATFORM_DESKTOP)

target_link_libraries(game_of_life PRIVATE raylib)

