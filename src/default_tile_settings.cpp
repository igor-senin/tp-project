#include "default_tile_settings.h"

int default_tile_settings::air_damage = 0;
int default_tile_settings::default_tile_damage = 0;
int default_tile_settings::damage_tile_damage = 10;
int default_tile_settings::stone_tile_damage = 0;

std::string default_tile_settings::air_path_to_texture = 
    "../resources/graphics-vertex-array-tilemap-tileset.png";
std::string default_tile_settings::default_tile_path_to_texture = 
    "../resources/graphics-vertex-array-tilemap-tileset.png";
std::string default_tile_settings::damage_tile_path_to_texture = 
    "../resources/graphics-vertex-array-tilemap-tileset.png";
std::string default_tile_settings::stone_tile_path_to_texture = 
    "../resources/graphics-vertex-array-tilemap-tileset.png";

char default_tile_settings::air_default_short_name = 'a';
char default_tile_settings::default_tile_default_short_name = 'u';
char default_tile_settings::damage_tile_default_short_name = 'd';
char default_tile_settings::stone_tile_default_short_name = 's';

int default_tile_settings::air_tile_upper_left_corner_x_coordinate = 0;
int default_tile_settings::air_tile_upper_left_corner_y_coordinate = 0;
int default_tile_settings::air_tile_size_tile_x_coordinate = 32;
int default_tile_settings::air_tile_size_tile_y_coordinate = 32;

int default_tile_settings::damage_tile_upper_left_corner_x_coordinate = 32;
int default_tile_settings::damage_tile_upper_left_corner_y_coordinate = 0;
int default_tile_settings::damage_tile_size_tile_x_coordinate = 32;
int default_tile_settings::damage_tile_size_tile_y_coordinate = 32;

int default_tile_settings::default_tile_upper_left_corner_x_coordinate = 64;
int default_tile_settings::default_tile_upper_left_corner_y_coordinate = 0;
int default_tile_settings::default_tile_size_tile_x_coordinate = 32;
int default_tile_settings::default_tile_size_tile_y_coordinate = 32;

int default_tile_settings::stone_tile_upper_left_corner_x_coordinate = 96;
int default_tile_settings::stone_tile_upper_left_corner_y_coordinate = 0;
int default_tile_settings::stone_tile_size_tile_x_coordinate = 32;
int default_tile_settings::stone_tile_size_tile_y_coordinate = 32;
