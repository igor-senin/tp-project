cmake_minimum_required(VERSION 3.21)
project(test_game)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_game src/main.cpp src/game.cpp
        include/game.h include/player.h src/player.cpp
        include/tile.h src/tile.cpp include/tilemap.h
        src/tilemap.cpp
)

target_link_libraries(test_game sfml-graphics sfml-window sfml-system)

include_directories("test-game" "include")