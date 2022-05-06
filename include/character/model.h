#ifndef TEST_GAME_INCLUDE_CHARACTER_MODEL_H_
#define TEST_GAME_INCLUDE_CHARACTER_MODEL_H_

#include <SFML/Graphics.hpp>

enum PLAYER_CONDITION_STATES {IDLE = 0, MOVING,
  JUMPING, FALLING};

class Model {
 private:
  sf::Vector2f velocity = sf::Vector2f(0.f, 0.f);
  sf::Vector2f  oldVelocity = sf::Vector2f(0.f, 0.f);

  bool wasGrounded = false;
  bool wasTouchingRightWall = false;
  bool wasTouchingLeftWall = false;
  bool lookedRight = false;

  const float minVelocity = 0.5f;
  const float maxVelocityX = 7.5f;
  const float maxVelocityY = 15.f;
  const float gravity = 0.6f;
  const float drag = 0.96f;
  const float acceleration = 2.f;

 public:
  bool isGrounded = false;
  bool touchesRightWall = false;
  bool touchesLeftWall = false; // TODO : not public
  bool looksRight = true;

  int state = 0;

  Model() = default;

  void updatePreviousCondition();
  void updatePhysics();
  void changeVelocity(float, float);
  void setVelocity(float, float);
  void landedY();
  sf::Vector2f getVelocity();

};

#endif //TEST_GAME_INCLUDE_CHARACTER_MODEL_H_
