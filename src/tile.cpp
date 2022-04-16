//
// Created by igor on 24.03.2022.
//

#include "tile.h"

Tile::Tile(sf::Texture& texture_sheet,
           sf::IntRect texture_rect, bool dmg): damaging(dmg) {
  sprite.setTexture(texture_sheet);
  sprite.setTextureRect(texture_rect);
}

const sf::FloatRect Tile::getGlobalBounds() const {
  return sprite.getGlobalBounds();
}

void Tile::update() {

}

void Tile::render(sf::RenderTarget& target) {
  target.draw(sprite);
}