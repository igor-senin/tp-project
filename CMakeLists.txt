cmake_minimum_required(VERSION 3.21)

project(test_tile)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SFML COMPONENTS graphics window system REQUIRED)
set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}
                    "include" 
                    "src" 
                    "resources"
                    "test_build_tile"
)

add_executable(
  tileout 
    src/main.cpp
      include/convert_map_file_to_matrix.h 
      include/default_map_settings.h 
      include/tilemap.h
      include/default_tile_settings.h 
      include/initialization_of_tiles.h 
      include/tile.h
      src/convert_map_file_to_matrix.cpp 
      src/tilemap.cpp 
      src/default_map_settings.cpp
      src/default_tile_settings.cpp
      src/initialization_of_tiles.cpp
      src/tile.cpp
)

target_link_libraries(tileout sfml-graphics sfml-window sfml-system)
