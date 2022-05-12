#include "default_tile_settings.h"

int default_tile_settings::air_tile_damage = 0;
int default_tile_settings::finish_tile_damage = 0;
int default_tile_settings::damage_tile_damage = 10;
int default_tile_settings::stone_tile_damage = 0;

float default_tile_settings::air_tile_scale = 2.297;
float default_tile_settings::finish_tile_scale = 2.297;
float default_tile_settings::damage_tile_scale = 2.297;
float default_tile_settings::stone_tile_scale = 2.297;

bool default_tile_settings::air_tile_is_wall = false;
bool default_tile_settings::damage_tile_is_wall = true;
bool default_tile_settings::finish_tile_is_wall = false;
bool default_tile_settings::stone_tile_is_wall = true;

bool default_tile_settings::air_tile_is_finish = false;
bool default_tile_settings::damage_tile_is_finish = false;
bool default_tile_settings::finish_tile_is_finish = true;
bool default_tile_settings::stone_tile_is_finish = false;

std::string default_tile_settings::air_tile_path_to_texture = 
    "../resources/graphics-vertex-array-tilemap-tileset.png";
std::string default_tile_settings::finish_tile_path_to_texture = 
    "../resources/graphics-vertex-array-tilemap-tileset.png";
std::string default_tile_settings::damage_tile_path_to_texture = 
    "../resources/graphics-vertex-array-tilemap-tileset.png";
std::string default_tile_settings::stone_tile_path_to_texture = 
    "../resources/graphics-vertex-array-tilemap-tileset.png";

char default_tile_settings::air_tile_default_short_name = 'a';
char default_tile_settings::finish_tile_default_short_name = 'f';
char default_tile_settings::damage_tile_default_short_name = 'd';
char default_tile_settings::stone_tile_default_short_name = 's';

int default_tile_settings::air_tile_upper_left_corner_x_coordinate = 0;
int default_tile_settings::air_tile_upper_left_corner_y_coordinate = 0;
int default_tile_settings::air_tile_size_tile_x_coordinate = 32;
int default_tile_settings::air_tile_size_tile_y_coordinate = 32;

int default_tile_settings::damage_tile_upper_left_corner_x_coordinate = 64;
int default_tile_settings::damage_tile_upper_left_corner_y_coordinate = 0;
int default_tile_settings::damage_tile_size_tile_x_coordinate = 32;
int default_tile_settings::damage_tile_size_tile_y_coordinate = 32;

int default_tile_settings::finish_tile_upper_left_corner_x_coordinate = 32;
int default_tile_settings::finish_tile_upper_left_corner_y_coordinate = 0;
int default_tile_settings::finish_tile_size_tile_x_coordinate = 32;
int default_tile_settings::finish_tile_size_tile_y_coordinate = 32;

int default_tile_settings::stone_tile_upper_left_corner_x_coordinate = 96;
int default_tile_settings::stone_tile_upper_left_corner_y_coordinate = 0;
int default_tile_settings::stone_tile_size_tile_x_coordinate = 32;
int default_tile_settings::stone_tile_size_tile_y_coordinate = 32;
