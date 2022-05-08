#ifndef TEST_GAME_INCLUDE_TILE_H_
#define TEST_GAME_INCLUDE_TILE_H_

#include <SFML/Graphics.hpp>

class Tile {
 private:
  sf::Sprite sprite;
  const bool damaging;

 public:
  Tile(sf::Texture&, sf::IntRect, bool = false);

  const sf::FloatRect getGlobalBounds() const;

  void update();
  void render(sf::RenderTarget&);
};

#endif //TEST_GAME_INCLUDE_TILE_H_
