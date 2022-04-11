#include "character/control.h"

Control::Control(Model* ptr): model(ptr) {
  jumpReleased.restart();
}

void Control::updateMovement() {
  model->updatePreviousCondition();

  if (model->getState() == JUMPING) {
    if (jumpReleased.getElapsedTime().asSeconds() < 0.5f)
      return;
    if (!model->isGrounded) {
      model->setState(FALLING);
      return;
    }
  }

  if (!model->isGrounded) {
    model->setState(FALLING);
    return;
  }

  model->setState(IDLE);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
    if (!model->touchesLeftWall)
      model->changeVelocity(-1.f, 0.f);
    model->setState(MOVING_LEFT);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
    if (!model->touchesRightWall)
      model->changeVelocity(1.f, 0.f);
    model->setState(MOVING_RIGHT);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)
      and model->isGrounded) {
    jumpReleased.restart();
    model->isGrounded = false;
    model->changeVelocity(0.f, -20.f);
    model->setState(JUMPING);
  }
}