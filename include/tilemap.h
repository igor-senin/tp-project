#pragma once
#include "convert_map_file_to_matrix.h"
#include "default_map_settings.h"

class TileMap {
 private:
  std::vector<std::vector<MainTile*>> tile_map_;
 public:
  TileMap();

 const std::vector<std::vector<MainTile*>>& GetTileMap();
 void ChangeTile(MainTile*, int, int);
 //void update();
 //void render();
};
