#ifndef TEST_GAME_INCLUDE_TILE_H_
#define TEST_GAME_INCLUDE_TILE_H_

#include <SFML/Graphics.hpp>

class MainTile {
 private:
  sf::Sprite sprite;
  const int damaging;
  std::string path_to_texture;

 public:
  Tile(sf::Texture&, sf::IntRect, bool = false);

  const sf::FloatRect getGlobalBounds() const;

  void update();
  void render(sf::RenderTarget&);
};
class Air: public MainTile {

};
class DefaultTile: public MainTile {};
class DamageTile: public MainTile {};

#endif //TEST_GAME_INCLUDE_TILE_H_
