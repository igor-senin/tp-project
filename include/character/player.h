#ifndef TEST_GAME_INCLUDE_PLAYER_H_
#define TEST_GAME_INCLUDE_PLAYER_H_

#include <SFML/Graphics.hpp>
#include <view.h>
#include <model.h>
#include <control.h>
#include <tilemap.h>


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

  std::pair<sf::Vector2f, sf::Vector2f> getCorners() const;
  void updateCollision();

  void update();
  void render(sf::RenderTarget& target);
};

#endif //TEST_GAME_INCLUDE_PLAYER_H_
