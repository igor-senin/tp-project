cmake_minimum_required(VERSION 3.21)

project(test_tile)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(SFML/SFML-2.5.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER "clang++")

include_directories(${CMAKE_SOURCE_DIR}
                    "include" 
                    "src" 
                    "resources"
)

add_executable(
    proj
      include/game.h 
      include/character/player.h 
      include/character/control.h
      include/character/model.h 
      include/character/view.h 
      include/convert_map_file_to_matrix.h 
      include/default_map_settings.h 
      include/tilemap.h
      include/default_tile_settings.h 
      include/initialization_of_tiles.h 
      include/tile.h
      src/character/view.cpp
      src/character/player.cpp
      src/main.cpp 
      src/game.cpp
      src/character/model.cpp
      src/character/control.cpp 
      src/convert_map_file_to_matrix.cpp 
      src/tilemap.cpp 
      src/default_map_settings.cpp
      src/default_tile_settings.cpp
      src/initialization_of_tiles.cpp
      src/tile.cpp
)

target_link_libraries(proj sfml-graphics sfml-window sfml-system)
include_directories("include" "include/character")
