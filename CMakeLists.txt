cmake_minimum_required(VERSION 3.21)

project(test_tile)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(${CMAKE_SOURCE_DIR}
                    "include" 
                    "src" 
                    "include/tiles" 
                    "src/tiles"
                    "test_build_tile"
)

add_executable(
  tileout 
    include/convert_map_file_to_matrix.h 
    include/default_map_settings.h 
    include/tilemap.h
    include/tiles/default_tile_settings.h 
    include/tiles/initialization_of_tiles.h 
    include/tiles/tile.h
    src/convert_map_file_to_matrix.cpp 
    src/tilemap.cpp 
    src/default_map_settings.cpp
    src/tiles/default_tile_settings.cpp
    src/tiles/initialization_of_tiles.cpp
    src/tiles/tile.cpp
    test_build_tile/main.cpp
)
