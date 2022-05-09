#include <iostream>

#include <view.h>

View::View(Model* ptr): model(ptr) {
  initTexture();
  initSprite();
  initAnimations();
}

void View::initAnimations() {
  animationTimer.restart();
}

void View::initTexture() {
  if (!textureSheet.loadFromFile("../resources/player_sheet.png")) {
    std::cerr << "ERROR!\n Player could not load the player sheet.\n";
  }
}

void View::initSprite() {
  sprite.setTexture(textureSheet);
  currentFrame =sf::IntRect(
      0,
      line_starts[1],
      frame_sizes.x,
      frame_sizes.y
      );

  sprite.setTextureRect(currentFrame);
  sprite.setScale(frame_scale);
}

void View::stay() {
  if (animationTimer.getElapsedTime().asSeconds() >= 0.2f) {
    currentFrame.top = line_starts[1];
    currentFrame.left += frame_sizes.x;
    if (currentFrame.left >= number_of_frames_in_line[1] * frame_sizes.x) {
      currentFrame.left = 0;
    }
    animationTimer.restart();
    sprite.setTextureRect(currentFrame);
  }
  sprite.setOrigin(0.f, 0.f);
}

void View::moveRight() {
  if (animationTimer.getElapsedTime().asSeconds() >= 0.07f) {
    currentFrame.left += frame_sizes.x;
    if (currentFrame.left >= number_of_frames_in_line[2] * frame_sizes.x) {
      currentFrame.left = 0;
      currentFrame.top =
          line_starts[(currentFrame.top == line_starts[2] ? 3 : 2)];
    }
    animationTimer.restart();
    sprite.setTextureRect(currentFrame);
  }
  sprite.setScale(frame_scale);
  sprite.setOrigin(0.f, 0.f);
}

void View::jump() {
  if (animationTimer.getElapsedTime().asSeconds() >= 0.17f) {
    currentFrame.top = 0;
    currentFrame.left += frame_sizes.x;
    if (currentFrame.left >= number_of_frames_in_line[0] * frame_sizes.x) {
      currentFrame.left = 0;
    }
    animationTimer.restart();
  }
  sprite.setScale(frame_scale);
  sprite.setTextureRect(currentFrame);
  sprite.setOrigin(0.f, 0.f);
}

void View::fall() {
  currentFrame.top = 0;
  currentFrame.left = 2568;
  sprite.setScale(frame_scale);
  sprite.setTextureRect(currentFrame);
  sprite.setOrigin(0.f, 0.f);
}

void View::turn() {
  sprite.setScale(-frame_scale.x, frame_scale.y);
  sprite.setOrigin(sprite.getGlobalBounds().width / frame_scale.x, 0.f);
}

void View::updateAnimations() {
  sprite.move(model->getVelocity());

  switch(model->state) {
    case IDLE:
      stay();
      break;
    case MOVING:
      moveRight();
      break;
    case JUMPING:
      jump();
      break;
    case FALLING:
      fall();
      break;
    default:
      break;
  }

  if (!model->looksRight)
    turn();
}

void View::render(sf::RenderTarget& target) {
  target.draw(sprite);
}

void View::setPosition(float x, float y) {
  sprite.setPosition(x, y);
}

sf::FloatRect View::getGlobalBounds() const {
  return sprite.getGlobalBounds();
}

sf::Vector2f View::getPosition() const {
  return sprite.getPosition();
}
