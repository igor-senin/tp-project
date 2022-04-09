#include <vector>
#include "convert_map_file_to_matrix.h"
#include "tile.h"

class TileMap {
 private:
  std::vector<std::vector<MainTile*>> tile_map;
 public:
  TileMap();
 ~TileMap();

 // Functions
 void addTile(unsigned, unsigned);
 void removeTile(unsigned, unsigned);

 void update();
 void render();
};
