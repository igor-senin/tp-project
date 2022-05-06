#include "tilemap.h"
#include "default_map_settings.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

TileMap::TileMap() {
  ConvertToMapFromFile convert(default_map_settings::path_to_file, 
                               default_map_settings::separator);
  tile_map_ = convert.GetTileMap();
  InitSprites();
}

void TileMap::InitSprites() {
  for (int i = 0; i < tile_map_.size(); ++i) {
    sprites_.push_back(std::vector<sf::Sprite>(tile_map_[i].size()));
    for (int j = 0; j < tile_map_[i].size(); ++j) {
      sprites_[i][j].setTexture(tile_map_[i][j]->GetTexture());
      sprites_[i][j].setScale(sf::Vector2f(
          tile_map_[i][j]->GetScale(), tile_map_[i][j]->GetScale())); 
      sprites_[i][j].setPosition(
          sf::Vector2f(default_map_settings::start_map_coordinate_x + 
                       float(j) * default_map_settings::tile_size, 
                       default_map_settings::start_map_coordinate_y + 
                       float(i) * default_map_settings::tile_size));
    }
  }
}

void TileMap::Draw(sf::RenderWindow& window) {
  for (int i = 0; i < sprites_.size(); ++i) {
    for (int j = 0; j < sprites_[i].size(); ++j) {
      window.draw(sprites_[i][j]);
    }
  }
}

/*
void TileMap::ChangeTile(MainTile* another, int x_coordinate, 
                         int y_coordinate) {
  tile_map_[x_coordinate][y_coordinate] = another;
}
*/

const std::vector<std::vector<MainTile*>>& TileMap::GetTileMap() {
  return tile_map_;
}

std::vector<std::vector<sf::Sprite>>& TileMap::GetSpriteMap() {
  return sprites_;
}
