#include "player.h"

void Player::update() {
  control.updateMovement();
  view.updateAnimations();
  model.updatePhysics();

  updateCollision();
}

Player::Player(TileMap* tile_map, sf::Vector2u window_sizes):
model(Model()), control(Control(&model)), view(View(&model)),
tile_map(tile_map), window_sizes(window_sizes) {}

sf::FloatRect Player::getGlobalBounds() const {
  return view.getGlobalBounds();
}

void Player::setPosition(float x, float y) {
  view.setPosition(x, y);
}

void Player::landedY() {
  model.landedY();
}

void Player::updateCollision() {
  // bottom of screen
  if (getPosition().y + getGlobalBounds().height > window_sizes.y) {
    landedY();
    setPosition(getPosition().x, window_sizes.y - getGlobalBounds().height);
  }

/*  bool floor, top, right, left;
  floor = top = right = left = false;
  for (std::size_t i = 0; i < tile_map->GetTileMap().size(); ++i) {
    for (std::size_t j = 0; j < tile_map->GetTileMap()[i].size(); ++j) {
      if (!tile_map->GetTileMap()[i][j]->IsWall()) {
        continue;
      }

      if (tile_map->GetTileMap()[i][j].)
    }
  }*/

  // floor

  // top

  // right

  // left

}

sf::Vector2f Player::getPosition() const {
  return view.getPosition();
}

void Player::render(sf::RenderTarget& target) {
  view.render(target);
}