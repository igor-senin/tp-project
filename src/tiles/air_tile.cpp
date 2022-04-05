#include "tile.h"
#include "default_tile_settings.h"

// TODO no initializing field
Air::Air()
  : damage(default_tile_settings::air_damage)
  , path_to_texture(default_tile_settings::air_path_to_texture)
{}
