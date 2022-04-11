#include "tilemap.h"
#include <vector>

int main() {
  TileMap t;
  std::vector<std::vector<MainTile*>> v = t.GetTileMap();
}
