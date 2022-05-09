#include <tuple>

#include "player.h"
#include "tilemap.h"

#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

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

void Player::setVelocity(float x, float y) {
  model.setVelocity(x, y);
}

void Player::landedY() {
  model.landedY();
}

std::tuple<float, float, float, float> Player::getCorners() const {
  return std::make_tuple(getPosition().x, getPosition().y,
    getPosition().x + getGlobalBounds().width,
    getPosition().y + getGlobalBounds().height);
}

std::tuple<float, float, float, float>
Player::getTileCorners(std::size_t i, std::size_t j) const {
  auto tile_info = tile_map->GetSpriteMap()[i][j].getGlobalBounds();
  return std::make_tuple(tile_info.left, tile_info.top,
    tile_info.left + tile_info.width,
    tile_info.top + tile_info.height);
}

bool intersects(float x1, float x2, float y1, float y2) {
  return (x1 < y2 and x1 > y1)
      or (x2 < y2 and x2 > y1)
      or (y1 < x2 and y1 > x1)
      or (y2 < x2 and y2 > x1);
}

void Player::updateCollision() {
  bool top, floor, left, right;
  float top_c, floor_c, left_c, right_c;

  for (std::size_t i = 0; i < tile_map->GetTileMap().size(); ++i) {
    for (std::size_t j = 0; j < tile_map->GetTileMap()[i].size(); ++j) {

      top = floor = left = right = false;

      if (!tile_map->GetTileMap()[i][j]->IsWall()) { continue; }

      auto [spr_l, spr_t, spr_r, spr_f] = getTileCorners(i, j);
      {
      auto [chr_l, chr_t, chr_r, chr_f] = getCorners();

      if (!intersects(spr_l, spr_r, chr_l, chr_r) or !intersects(spr_t, spr_f, chr_t, chr_f)) continue;
      if (chr_f > spr_t and chr_t < spr_t) { floor = true; floor_c = spr_t; }

      if (floor) {
        landedY();
        setPosition(getPosition().x, floor_c - getGlobalBounds().height);
      }
      }
     
      {
      auto [chr_l, chr_t, chr_r, chr_f] = getCorners();

      if (!intersects(spr_l, spr_r, chr_l, chr_r) or !intersects(spr_t, spr_f, chr_t, chr_f)) continue;
      if (chr_l < spr_r and chr_r > spr_r) { left = true; left_c = spr_r; } 
      if (left) {
        setVelocity(0.f, model.getVelocity().y);
        setPosition(left_c, getPosition().y);
      }
      }

      {
      auto [chr_l, chr_t, chr_r, chr_f] = getCorners();

      if (!intersects(spr_l, spr_r, chr_l, chr_r) or !intersects(spr_t, spr_f, chr_t, chr_f)) continue;
      if (chr_r > spr_l and chr_l < spr_l) { right = true; right_c = spr_l; }
      if (right) {
        setVelocity(0.f, model.getVelocity().y);
        setPosition(right_c - getGlobalBounds().width, getPosition().y);
      }
      }

      {
      auto [chr_l, chr_t, chr_r, chr_f] = getCorners();

      if (!intersects(spr_l, spr_r, chr_l, chr_r) or !intersects(spr_t, spr_f, chr_t, chr_f)) continue;
      if (chr_t < spr_f and chr_f > spr_f) { top = true; top_c = spr_f; } 
      if (top) {
        setVelocity(model.getVelocity().x, 0.f);
        setPosition(getPosition().x, top_c);
      }
      }
 
    }
  }
}

sf::Vector2f Player::getPosition() const {
  return view.getPosition();
}

void Player::render(sf::RenderTarget& target) {
  view.render(target);
}
