#include "character/control.h"

Control::Control(Model* ptr): model(ptr) {
  jumpReleased.restart();
}

void Control::updateMovement() {
  bool keyHold = false;
  model->updatePreviousCondition();

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
    keyHold = true;

    if (!model->touchesLeftWall)
      model->changeVelocity(-1.f, 0.f);
    if (model->isGrounded)
      model->state = MOVING;
    model->looksRight = false;
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
    keyHold = true;

    if (!model->touchesRightWall)
      model->changeVelocity(1.f, 0.f);
    if (model->isGrounded)
      model->state = MOVING;
    model->looksRight = true;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
    keyHold = true;

    if (model->isGrounded) {
      jumpReleased.restart();
      model->state = JUMPING;
      model->isGrounded = false;
      model->changeVelocity(0.f, -15.f);
      return;
    }
  }

  if (!model->isGrounded
  and jumpReleased.getElapsedTime().asSeconds() >= 0.5f) {
    model->state = FALLING;
    return;
  }

  if (model->isGrounded and !keyHold) {
    model->state = IDLE;
  }

}

