#ifndef TEST_GAME_INCLUDE_PLAYER_H_
#define TEST_GAME_INCLUDE_PLAYER_H_

#include <SFML/Graphics.hpp>

enum PLAYER_ANIMATION_STATES {IDLE = 0, MOVING_LEFT, MOVING_RIGHT,
JUMPING, FALLING};

class Player {
 private:
  sf::Sprite sprite;
  sf::Texture textureSheet;

  sf::Clock animationTimer;

  // Core
  void initVariables();
  void initTexture();
  void initSprite();
  void initAnimations();
  void initPhysics();

  // Animation
  int animState;
  sf::IntRect currentFrame;
  bool animationSwitch;

  // Physics
  sf::Vector2f velocity = sf::Vector2f(0.f, 0.f);
  sf::Vector2f  oldVelocity = sf::Vector2f(0.f, 0.f);
  bool isGrounded = false;
  bool wasGrounded = false;
  bool touchesRightWall = false;
  bool wasTouchingRightWall = false;
  bool touchesLeftWall = false;
  bool wasTouchingLeftWall = false;

  const float minVelocity = 0.5f;
  const float maxVelocityX = 7.5f;
  const float maxVelocityY = 15.f;
  const float gravity = 0.7f; // вертикальный ускоритель вниз
  const float drag = 0.93f; // горизонтальная сила трения
  const float acceleration = 2.f; // типа горизонтальное ускорение

 public:
  Player();
  ~Player();

  // Accessors
  bool getAnimSwitch();
  const sf::FloatRect getGlobalBounds() const;
  const sf::Vector2f getPosition() const;

  // Modifiers
  void setPosition(float, float);
  void landedY(); // для коллизии

  // Functions
  void resetAnimationTimer();
  void move(float, float);
  void updatePhysics();
  void updateMovement();
  void updateAnimations();
  void update();
  void render(sf::RenderTarget&);
};

#endif //TEST_GAME_INCLUDE_PLAYER_H_