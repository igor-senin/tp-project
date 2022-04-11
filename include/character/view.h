#ifndef TEST_GAME_INCLUDE_CHARACTER_VIEW_H_
#define TEST_GAME_INCLUDE_CHARACTER_VIEW_H_

#include <SFML/Graphics.hpp>
#include <model.h>

class View {
 private:
  sf::Sprite sprite;
  sf::Texture textureSheet;

  sf::Clock animationTimer;

  sf::IntRect currentFrame;

  Model* model = nullptr;

  void initAnimations();
  void initTexture();
  void initSprite();

  void stay();
  void moveRight();
  void moveLeft();
  void jump();
  void fall();
 public:
  View() = default;
  View(Model*);

  void updateAnimations();
  void render(sf::RenderTarget&);
  void setPosition(float, float);

  sf::FloatRect getGlobalBounds() const;
  sf::Vector2f getPosition() const;
};


#endif //TEST_GAME_INCLUDE_CHARACTER_VIEW_H_