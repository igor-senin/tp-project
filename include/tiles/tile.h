#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "default_tile_settings.h"

class MainTile {
 private:
  const int damaging;
  std::string path_to_texture;
 public:
  MainTile(int, std::string&);
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
