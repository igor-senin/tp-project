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
  sf::Texture texture_;
  bool is_wall_;
  float scale_size;
  bool is_finish_;
  
 public:
  MainTile(int, std::string&, bool, float, bool);
  void InitTexture(int, int, int, int);  // coordinates from image (make intrect)
  int GetDamage();
  bool IsWall();
  float GetScale();
  bool IsFinish();
  sf::Texture& GetTexture();
};

class AirTile: public MainTile {
 public:
  AirTile();
};

class FinishTile: public MainTile {
 public:
  FinishTile();
};

class DamageTile: public MainTile {
 public:
  DamageTile();
};

class StoneTile: public MainTile {
 public:
  StoneTile();
};
