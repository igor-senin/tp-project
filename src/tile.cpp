#include "tile.h"
#include "default_tile_settings.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>

void MainTile::InitTexture(int left_x, int left_y, int right_x, int right_y) {
  if (!texture_.loadFromFile(path_to_texture_, 
                            sf::IntRect(left_x, left_y, right_x, right_y))) {
    std::cerr << "Cannot load texture\n";
  }
}

bool MainTile::IsWall() { return is_wall_; }

MainTile::MainTile(int damage, std::string& input_path_to_texture, bool is_wall)
  : damage_(damage)
  , path_to_texture_(input_path_to_texture)
  , is_wall_(is_wall)
{
}

int MainTile::GetDamage() {
  return damage_;
}

Air::Air()
  : MainTile(default_tile_settings::air_damage, 
             default_tile_settings::air_path_to_texture,
             default_tile_settings::air_is_wall)
{
InitTexture(default_tile_settings::air_tile_upper_left_corner_x_coordinate,
            default_tile_settings::air_tile_upper_left_corner_y_coordinate,
            default_tile_settings::air_tile_size_tile_x_coordinate,
            default_tile_settings::air_tile_size_tile_y_coordinate);
}

DefaultTile::DefaultTile()
 :  MainTile(default_tile_settings::default_tile_damage, 
             default_tile_settings::default_tile_path_to_texture,
             default_tile_settings::default_tile_is_wall)
{
InitTexture(default_tile_settings::default_tile_upper_left_corner_x_coordinate,
            default_tile_settings::default_tile_upper_left_corner_y_coordinate,
            default_tile_settings::default_tile_size_tile_x_coordinate,
            default_tile_settings::default_tile_size_tile_y_coordinate);
}

StoneTile::StoneTile()
  : MainTile(default_tile_settings::stone_tile_damage, 
             default_tile_settings::stone_tile_path_to_texture,
             default_tile_settings::stone_tile_is_wall)
{
InitTexture(default_tile_settings::stone_tile_upper_left_corner_x_coordinate,
            default_tile_settings::stone_tile_upper_left_corner_y_coordinate,
            default_tile_settings::stone_tile_size_tile_x_coordinate,
            default_tile_settings::stone_tile_size_tile_y_coordinate);
}

DamageTile::DamageTile()
  : MainTile(default_tile_settings::damage_tile_damage, 
             default_tile_settings::damage_tile_path_to_texture,
             default_tile_settings::damage_tile_is_wall)
{
InitTexture(default_tile_settings::damage_tile_upper_left_corner_x_coordinate,
            default_tile_settings::damage_tile_upper_left_corner_y_coordinate,
            default_tile_settings::damage_tile_size_tile_x_coordinate,
            default_tile_settings::damage_tile_size_tile_y_coordinate);
}

sf::Texture& MainTile::GetTexture() {
  return texture_;
}
