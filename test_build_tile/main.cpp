#include "tilemap.h"
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


int main() {
  TileMap t;
  std::vector<std::vector<MainTile*>> v = t.GetTileMap();
  for (int i = 0; i < v.size(); ++i) {
    for (int j = 0; j < v[i].size(); ++j) {
      std::cout.width(3);
      std::cout << v[i][j]->GetDamage() << ' ';
    }
    std::cout << '\n';
  }

  sf::RenderWindow window (sf::VideoMode(800, 600), "My window");

  while (window.isOpen()) {

    sf::Event event;
    
    while (window.pollEvent(event)) {
      
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      window.clear(sf::Color::Black);

      window.display();

    }
  }
}
