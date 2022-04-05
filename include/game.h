#ifndef TEST_GAME_INCLUDE_GAME_H_
#define TEST_GAME_INCLUDE_GAME_H_

#include <SFML/Graphics.hpp>

#include "player.h"

class Game {
 private:
  sf::RenderWindow window;
  sf::Event event;

  Player* player;

  void initPlayer();
  void initWindow();

 public:
  Game();
  ~Game();

  // Functions
  void updatePlayer();
  void updateCollision();
  void update();

  void renderPlayer();
  void render();

  const sf::RenderWindow& getWindow() const;
};

#endif //TEST_GAME_INCLUDE_GAME_H_