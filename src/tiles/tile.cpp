#include "tile.h"
#include "default_tile_settings.h"

MainTile::MainTile(int damage, std::string& input_path_to_texture)
  : damaging(damage)
  , path_to_texture(input_path_to_texture)
{}

Air::Air(int damage = default_tile_settings::air_damage, 
         std::string& input_path_to_texture = air_path_to_texture)
{}

DefaultTile::DefaultTile(int damage = default_tile_settings::default_tile_damage, 
                         std::string& input_path_to_texture = 
                             default_tile_settings::default_tile_path_to_texture)
  : MainTile(damage, input_path_to_texture)
{}

DamageTile::DamageTile(int damage = default_tile_settings::damage_tile_damage, 
                       std::string& input_path_to_texture = 
                           default_tile_settings::damage_tile_path_to_texture)
  : MainTile(damage, input_path_to_texture)
{}
