#ifndef TEST_GAME_SRC_CHARACTER_CONTROL_H_
#define TEST_GAME_SRC_CHARACTER_CONTROL_H_

#include <model.h>

class Control {
 private:
  Model* model;

  sf::Clock jumpReleased;
 public:
  Control(Model*);

  void updateMovement();
};

#endif //TEST_GAME_SRC_CHARACTER_CONTROL_H_