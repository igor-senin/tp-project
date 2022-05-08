#include <SFML/Graphics.hpp>

#include <model.h>

void Model::updatePreviousCondition() {
  wasGrounded = isGrounded;
  wasTouchingLeftWall = touchesLeftWall;
  wasTouchingRightWall = touchesRightWall;
  lookedRight = looksRight;
}

void Model::updatePhysics() {
  oldVelocity = velocity;

  velocity.y += 1.f * gravity;
  if (std::abs(velocity.y) > maxVelocityY) {
    velocity.y = maxVelocityY * (velocity.y < 0.f ? -1.f : 1.f);
  }
  velocity *= drag;

  if (std::abs(velocity.x) < minVelocity) {
    velocity.x = 0.f;
  }
  if (std::abs(velocity.y) < minVelocity) {
    velocity.y = 0.f;
  }
}

void Model::changeVelocity(float dir_x, float dir_y) {
  velocity.x += dir_x * acceleration * 1.0f;
  velocity.y += dir_y * acceleration * 1.0f;

  if (std::abs(velocity.x) > maxVelocityX) {
    velocity.x = maxVelocityX * (velocity.x < 0 ? -1.f : 1.f);
  }
}

void Model::landedY() {
  velocity.y = 0.f;
  isGrounded = true;
}


sf::Vector2f Model::getVelocity() {
  return velocity;
}