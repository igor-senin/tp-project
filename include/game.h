#ifndef TEST_GAME_INCLUDE_GAME_H_
#define TEST_GAME_INCLUDE_GAME_H_

#include <SFML/Graphics.hpp>

#include "character/player.h"
#include "tilemap.h"

class Game {
 private:
  sf::RenderWindow window;
  sf::RenderWindow start_window;

  Player* player;

  TileMap* tilemap;

  void initPlayer();
  void initWindow();
  void initStartWindow();
  void initTilemap();

 public:
  Game();
  ~Game();

  // Functions
  void updateWindow();
  void updateStartWindow();
  void updatePlayer();
  void updateCollision();
  void update();

  void renderPlayer();
  void render();

  sf::RenderWindow& getWindow();
};

#endif //TEST_GAME_INCLUDE_GAME_H_
