#include "tilemap.h"

TileMap::TileMap()
{
  ConvertToMapFromFile convert(default_map_settings::path_to_file, 
                               default_map_settings::separator);
  tile_map_ = convert.GetTileMap();
}

void TileMap::ChangeTile(MainTile* another, int x_coordinate, 
                         int y_coordinate) {
  tile_map_[x_coordinate][y_coordinate] = another;
}

const std::vector<std::vector<MainTile*>>& TileMap::GetTileMap() {
  return tile_map_;
}
