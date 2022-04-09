#pragma once
#include <SFML/Graphics.hpp>

class MainTile {
 private:
  const int damaging;
  std::string path_to_texture;
  //sfml some
 public:
  MainTile(int, std::string&);
};

class Air: public MainTile {
  Air(int, std::string&);
};

class DefaultTile: public MainTile {
  DefaultTile(int, std::string&);
};

class DamageTile: public MainTile {
  DamageTile(int, std::string&);
};
