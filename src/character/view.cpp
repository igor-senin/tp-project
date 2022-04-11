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
  currentFrame = sf::IntRect(0,798,642,738);

  sprite.setTextureRect(currentFrame);
  sprite.setScale(0.2f, 0.2f);
}

void View::stay() {
  if (animationTimer.getElapsedTime().asSeconds() >= 0.2f) {
    currentFrame.top = 798;
    currentFrame.left += 642;
    if (currentFrame.left >= 1926) {
      currentFrame.left = 0;
    }
    animationTimer.restart();
    sprite.setTextureRect(currentFrame);
  }
}

void View::moveLeft() {
  if (animationTimer.getElapsedTime().asSeconds() >= 0.07f) {
    currentFrame.left += 642;
    if (currentFrame.left >= 3852) {
      currentFrame.left = 0;
      currentFrame.top = (currentFrame.top == 1630 ? 2403 : 1630);
    }
    animationTimer.restart();
    sprite.setTextureRect(currentFrame);
  }
  sprite.setScale(-0.2f, 0.2f);
  sprite.setOrigin(sprite.getGlobalBounds().width / 0.2f, 0.f);
}

void View::moveRight() {
  if (animationTimer.getElapsedTime().asSeconds() >= 0.07f) {
    currentFrame.left += 642;
    if (currentFrame.left >= 3852) {
      currentFrame.left = 0;
      currentFrame.top = (currentFrame.top == 1630 ? 2403 : 1630);
    }
    animationTimer.restart();
    sprite.setTextureRect(currentFrame);
  }
  sprite.setScale(0.2f, 0.2f);
  sprite.setOrigin(0.f, 0.f);
}

void View::jump() {
  if (animationTimer.getElapsedTime().asSeconds() >= 0.2f) {
    currentFrame.top = 0.f;
    currentFrame.left += 642;
    if (currentFrame.left >= 3210) {
      currentFrame.left = 0;
    }
  }
  sprite.setScale(0.2f, 0.2f);
  sprite.setTextureRect(currentFrame);
}

void View::fall() {
  currentFrame.top = 0;
  currentFrame.left = 2568;
  sprite.setScale(0.2f, 0.2f);
  sprite.setTextureRect(currentFrame);
}

void View::updateAnimations() {
  sprite.move(model->getVelocity());

  switch(model->getState()) {
    case IDLE:
      stay();
      break;
    case MOVING_RIGHT:
      moveRight();
      break;
    case MOVING_LEFT:
      moveLeft();
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