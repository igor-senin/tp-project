#pragma once
#include "convert_map_file_to_matrix.h"
#include "default_map_settings.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "tile.h"

class TileMap {
 private:
  std::vector<std::vector<MainTile*>> tile_map_;
  std::vector<std::vector<sf::Sprite>> sprites_;
 public:
  TileMap();
  void InitSprites();
  void Draw(sf::RenderWindow& window);
  void Render(sf::RenderTarget&);
  std::vector<std::vector<sf::Sprite>>& GetSpriteMap();

  const std::vector<std::vector<MainTile*>>& GetTileMap();

  //void ChangeTile(MainTile*, int, int);
  //void update();  // need to moving map or changing tiles
};
