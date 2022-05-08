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

std::pair<sf::Vector2f, sf::Vector2f> Player::getCorners() const {
  return {getPosition(),
    sf::Vector2f(getPosition().x + getGlobalBounds().width,
      getPosition().y + getGlobalBounds().height)};
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

      auto corners = getCorners();
      auto chr_t = corners.first.y;
      auto chr_f = corners.second.y;
      auto chr_l = corners.first.x;
      auto chr_r = corners.second.x;

      auto sprite_info = tile_map->GetSpriteMap()[i][j].getGlobalBounds();
      auto spr_t = sprite_info.top;
      auto spr_f = spr_t + sprite_info.height;
      auto spr_l = sprite_info.left;
      auto spr_r = spr_l + sprite_info.width;


      if (!intersects(spr_l, spr_r, chr_l, chr_r) or !intersects(spr_t, spr_f, chr_t, chr_f)) continue;
      if (chr_f > spr_t and chr_t < spr_t) { floor = true; floor_c = spr_t; }

      if (floor) {
        landedY();
        setPosition(getPosition().x, floor_c - getGlobalBounds().height);
      }
      
      corners = getCorners();
      chr_t = corners.first.y;
      chr_f = corners.second.y;
      chr_l = corners.first.x;
      chr_r = corners.second.x;
      sprite_info = tile_map->GetSpriteMap()[i][j].getGlobalBounds();
      spr_t = sprite_info.top;
      spr_f = spr_t + sprite_info.height;
      spr_l = sprite_info.left;
      spr_r = spr_l + sprite_info.width;
      

      if (!intersects(spr_l, spr_r, chr_l, chr_r) or !intersects(spr_t, spr_f, chr_t, chr_f)) continue;
      if (chr_l < spr_r and chr_r > spr_r) { left = true; left_c = spr_r; } 
      if (left) {
        setVelocity(0.f, model.getVelocity().y);
        setPosition(left_c, getPosition().y);
      }
      corners = getCorners();
      chr_t = corners.first.y;
      chr_f = corners.second.y;
      chr_l = corners.first.x;
      chr_r = corners.second.x;
      sprite_info = tile_map->GetSpriteMap()[i][j].getGlobalBounds();
      spr_t = sprite_info.top;
      spr_f = spr_t + sprite_info.height;
      spr_l = sprite_info.left;
      spr_r = spr_l + sprite_info.width;

      if (!intersects(spr_l, spr_r, chr_l, chr_r) or !intersects(spr_t, spr_f, chr_t, chr_f)) continue;
      if (chr_r > spr_l and chr_l < spr_l) { right = true; right_c = spr_l; }
      if (right) {
        setVelocity(0.f, model.getVelocity().y);
        setPosition(right_c - getGlobalBounds().width, getPosition().y);
      }

      corners = getCorners();
      chr_t = corners.first.y;
      chr_f = corners.second.y;
      chr_l = corners.first.x;
      chr_r = corners.second.x;
      sprite_info = tile_map->GetSpriteMap()[i][j].getGlobalBounds();
      spr_t = sprite_info.top;
      spr_f = spr_t + sprite_info.height;
      spr_l = sprite_info.left;
      spr_r = spr_l + sprite_info.width;

      if (!intersects(spr_l, spr_r, chr_l, chr_r) or !intersects(spr_t, spr_f, chr_t, chr_f)) continue;
      if (chr_t < spr_f and chr_f > spr_f) { top = true; top_c = spr_f; } 
      if (top) {
        setVelocity(model.getVelocity().x, 0.f);
        setPosition(getPosition().x, top_c);
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
