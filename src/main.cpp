#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include "tilemap.h"

int main() {

  sf::RenderWindow window(sf::VideoMode(2000, 1000), "My window");
  window.setFramerateLimit(60);
  TileMap tilemap;
  
  while (window.isOpen()) {
    window.clear();
    tilemap.Draw(window);
    window.display();
  }

  return 0;
}
