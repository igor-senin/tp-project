#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "default_tile_settings.h"
#include <SFML/Graphics.hpp>

class MainTile {
 private:
  const int damage_;
  std::string path_to_texture_;
  sf::Texture texture;
  
 public:
  MainTile(int, std::string&);
  void InitTexture(int, int, int, int);  // coordinates from image (make intrect)
  int GetDamage();
  sf::Texture& GetTexture();
};

class Air: public MainTile {
 public:
  Air();
};

class DefaultTile: public MainTile {
 public:
  DefaultTile();
};

class DamageTile: public MainTile {
 public:
  DamageTile();
};

class StoneTile: public MainTile {
 public:
  StoneTile();
};
