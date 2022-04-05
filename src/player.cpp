#include <iostream>

#include <player.h>

void Player::initTexture() {
  if (!textureSheet.loadFromFile("../resources/player_sheet (1).png")) {
    std::cerr << "ERROR!\n Player could not load the player sheet.\n";
  }
}

void Player::initSprite() {
  sprite.setTexture(textureSheet);
  currentFrame = sf::IntRect(0,0,40,50);

  sprite.setTextureRect(currentFrame);
  sprite.setScale(2.5f, 2.5f);
}

void Player::update() {
  updateMovement();
  updateAnimations();
  updatePhysics();
}

void Player::render(sf::RenderTarget& target) {
  target.draw(sprite);
}

Player::Player() {
  initVariables();
  initTexture();
  initSprite();
  initAnimations();
  initPhysics();
}

Player::~Player() {}

void Player::updateMovement() {
  wasGrounded = isGrounded;
  wasTouchingLeftWall = touchesLeftWall;
  wasTouchingRightWall = touchesRightWall;

  animState = IDLE;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
    if (!touchesLeftWall)
      move(-1.f, 0.f);
    animState = MOVING_LEFT;
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
    if (!touchesRightWall)
      move(1.f, 0.f);
    animState = MOVING_RIGHT;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)
  and isGrounded) {
    isGrounded = false;
    move(0.f, -20.f);
    animState = JUMPING;
  }
  sprite.move(velocity);
}

void Player::initAnimations() {
  animationTimer.restart();
  animationSwitch = true;
}

void Player::updateAnimations() {
  if (animState == IDLE) {
    if (animationTimer.getElapsedTime().asSeconds() >= 0.2f
        or getAnimSwitch()) {
      currentFrame.top = 0.f;
      currentFrame.left += 40.f;
      if (currentFrame.left >= 160.f) {
        currentFrame.left = 0;
      }
      animationTimer.restart();
      sprite.setTextureRect(currentFrame);
    }
  } else if (animState == MOVING_RIGHT) {
    if (animationTimer.getElapsedTime().asSeconds() >= 0.07f) {
      currentFrame.top = 50.f;
      currentFrame.left += 40.f;
      if (currentFrame.left >= 360.f) {
        currentFrame.left = 0;
      }
      animationTimer.restart();
      sprite.setTextureRect(currentFrame);
    }
    sprite.setScale(2.5f, 2.5f);
    sprite.setOrigin(0.f, 0.f);
  } else if (animState == MOVING_LEFT) {
    if (animationTimer.getElapsedTime().asSeconds() >= 0.07f) {
      currentFrame.top = 50.f;
      currentFrame.left += 40.f;
      if (currentFrame.left >= 360.f) {
        currentFrame.left = 0.f;
      }
      animationTimer.restart();
      sprite.setTextureRect(currentFrame);
    }
    sprite.setScale(-2.5f, 2.5f);
    sprite.setOrigin(sprite.getGlobalBounds().width / 2.5f, 0.f);
  } else if (animState == JUMPING) {
    if (animationTimer.getElapsedTime().asSeconds() >= 0.5f) {
      currentFrame.top = 100.f;
      currentFrame.left += 40.f;
      if (currentFrame.left >= 80.f) {
        currentFrame.left = 0.f;
      }
    }
    sprite.setScale(2.5f, 2.5f);
    sprite.setTextureRect(currentFrame);
  } else {
      animationTimer.restart();
  }
}

void Player::initVariables() {
  animState = IDLE;
}

void Player::updatePhysics() {
  oldVelocity = velocity;
  // Gravity
  velocity.y += 1.0 * gravity;
  if (std::abs(velocity.y) > maxVelocityY) {
    velocity.y = maxVelocityY * (velocity.y < 0.f ? -1.f : 1.f);
  }
  velocity *= drag;

  // Limit deceleration
  if (std::abs(velocity.x) < minVelocity) {
    velocity.x = 0.f;
  }
  if (std::abs(velocity.y) < minVelocity) {
    velocity.y = 0.f;
  }
}

void Player::initPhysics() {}

void Player::move(float dir_x, float dir_y) {
  // Acceleration
  velocity.x += dir_x * acceleration * 1.0f;
  velocity.y += dir_y * acceleration * 1.0f;

  if (std::abs(velocity.x) > maxVelocityX) {
    velocity.x = maxVelocityX * (velocity.x < 0 ? -1.f : 1.f);
  }
}

bool Player::getAnimSwitch() {
  bool anim_switch = animationSwitch;

  if (animationSwitch) {
    animationSwitch = false;
  }

  return anim_switch;
}

void Player::resetAnimationTimer() {
  animationTimer.restart();
  animationSwitch = true;
}

const sf::FloatRect Player::getGlobalBounds() const {
  return sprite.getGlobalBounds();
}

void Player::setPosition(float x, float y) {
  sprite.setPosition(x, y);
}

void Player::landedY() {
  velocity.y = 0.f;
  isGrounded = true;
}

const sf::Vector2f Player::getPosition() const {
  return sprite.getPosition();
}
