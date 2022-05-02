#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "tile.h"
#include "initialization_of_tiles.h"

class ConvertToMapFromFile {
 public:

  ConvertToMapFromFile(std::string&, char separator);
  void Converting(std::string&, char separator);

  int GetNumberLines() const;                       
  int GetNumberColumns() const;
  std::vector<std::vector<MainTile*>>& GetTileMap();
  std::vector<std::vector<char>>& GetMap();

 private:                                                                  

  void ConvertingNumberStringAndColumns(std::istream& source_file, int&, int&);
  void ConvertingMap(std::istream& source_file, int, int);
  void ConvertingTiles();

 private:                                                                  

  char separator_bettween_number_lines_and_columns;                        
  std::vector<std::vector<char>> map;                                      
  std::vector<std::vector<MainTile*>> tile_map;
};
