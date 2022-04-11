#include "tile.h"

MainTile::MainTile(int damage, std::string& input_path_to_texture)
  : damaging(damage)
  , path_to_texture(input_path_to_texture)
{}

Air::Air()
  : MainTile(default_tile_settings::air_damage, 
             default_tile_settings::air_path_to_texture)
{}

DefaultTile::DefaultTile()
 :  MainTile(default_tile_settings::default_tile_damage, 
             default_tile_settings::default_tile_path_to_texture)
{}

DamageTile::DamageTile()

  : MainTile(default_tile_settings::damage_tile_damage, 
             default_tile_settings::damage_tile_path_to_texture)
{}
