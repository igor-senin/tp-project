#ifndef TEST_GAME_INCLUDE_TILEMAP_H_
#define TEST_GAME_INCLUDE_TILEMAP_H_

#include <vector>
#include "tile.h"

class TileMap {
 private:
  std::vector<std::vector<Tile*>> tiles;
 public:
  TileMap();
 ~TileMap();

 // Functions
 void addTile(unsigned, unsigned);
 void removeTile(unsigned, unsigned);

 void update();
 void render();
};

#endif //TEST_GAME_INCLUDE_TILEMAP_H_