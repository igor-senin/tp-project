#pragma once
#include <string>
#include <SFML/Graphics.hpp>

namespace default_tile_settings {
  extern int air_damage;
  extern int default_tile_damage;
  extern int damage_tile_damage;
  extern int stone_tile_damage;

  extern bool air_is_wall;
  extern bool damage_tile_is_wall;
  extern bool default_tile_is_wall;
  extern bool stone_tile_is_wall;

  extern std::string air_path_to_texture;
  extern std::string default_tile_path_to_texture;
  extern std::string damage_tile_path_to_texture;
  extern std::string stone_tile_path_to_texture;

  extern char air_default_short_name;
  extern char default_tile_default_short_name;
  extern char damage_tile_default_short_name;
  extern char stone_tile_default_short_name;

  extern int air_tile_upper_left_corner_x_coordinate;
  extern int air_tile_upper_left_corner_y_coordinate;
  extern int air_tile_size_tile_x_coordinate;
  extern int air_tile_size_tile_y_coordinate;

  extern int damage_tile_upper_left_corner_x_coordinate;
  extern int damage_tile_upper_left_corner_y_coordinate;
  extern int damage_tile_size_tile_x_coordinate;
  extern int damage_tile_size_tile_y_coordinate;

  extern int default_tile_upper_left_corner_x_coordinate;
  extern int default_tile_upper_left_corner_y_coordinate;
  extern int default_tile_size_tile_x_coordinate;
  extern int default_tile_size_tile_y_coordinate;

  extern int stone_tile_upper_left_corner_x_coordinate;
  extern int stone_tile_upper_left_corner_y_coordinate;
  extern int stone_tile_size_tile_x_coordinate;
  extern int stone_tile_size_tile_y_coordinate;
}
