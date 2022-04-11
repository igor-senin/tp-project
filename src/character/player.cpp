#include "player.h"

void Player::update() {
  control.updateMovement();
  view.updateAnimations();
  model.updatePhysics();
}

Player::Player():
model(Model()), control(Control(&model)), view(View(&model)) {}

sf::FloatRect Player::getGlobalBounds() const {
  return view.getGlobalBounds();
}

void Player::setPosition(float x, float y) {
  view.setPosition(x, y);
}

void Player::landedY() {
  model.landedY();
}

sf::Vector2f Player::getPosition() const {
  return view.getPosition();
}

void Player::render(sf::RenderTarget& target) {
  view.render(target);
}