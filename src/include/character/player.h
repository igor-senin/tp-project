#ifndef TEST_GAME_INCLUDE_PLAYER_H_
#define TEST_GAME_INCLUDE_PLAYER_H_

#include <SFML/Graphics.hpp>
#include <view.h>
#include <model.h>
#include <control.h>


class Player {
 private:
  void init();

  View view;
  Model model;
  Control control;

 public:
  Player();
  ~Player() = default;

  sf::FloatRect getGlobalBounds() const;
  sf::Vector2f getPosition() const;

  void setPosition(float, float);
  void landedY();

  void update();
  void render(sf::RenderTarget& target);
};

#endif //TEST_GAME_INCLUDE_PLAYER_H_