#ifndef TEST_GAME_INCLUDE_CHARACTER_VIEW_H_
#define TEST_GAME_INCLUDE_CHARACTER_VIEW_H_

#include <SFML/Graphics.hpp>
#include <model.h>

const int line_starts[] = {0, 798, 1630, 2403};
const int number_of_frames_in_line[] = {5, 4, 6, 6};
const sf::Vector2i frame_sizes = {642, 738};
const sf::Vector2f frame_scale = {0.2f, 0.2f};

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
  void jump();
  void fall();
  void turn();
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