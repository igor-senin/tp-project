#ifndef TEST_GAME_INCLUDE_PLAYER_H_
#define TEST_GAME_INCLUDE_PLAYER_H_

#include <tuple>

#include <model.h>
#include <control.h>
#include <tilemap.h>
#include <view.h>

#include <SFML/Graphics.hpp>

class Player {
 private:

  View view;
  Model model;
  Control control;

  TileMap* tile_map;

  sf::Vector2u window_sizes;

 public:
  Player(TileMap*, sf::Vector2u);
  ~Player() = default;

  sf::FloatRect getGlobalBounds() const;
  sf::Vector2f getPosition() const;

  void setPosition(float, float);
  void setVelocity(float, float);
  void landedY();

  std::tuple<float, float, float, float> getCorners() const;
  std::tuple<float, float, float, float>
    getTileCorners(std::size_t, std::size_t) const;
  void updateCollision();

  void update();
  void render(sf::RenderTarget& target);
};

#endif //TEST_GAME_INCLUDE_PLAYER_H_
