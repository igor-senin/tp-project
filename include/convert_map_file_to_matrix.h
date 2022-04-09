#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "default_map_settings.h"
#include "initialization_of_tiles.h"
#include "../include/tiles/tile.h"

class ConvertToMapFromFile {
 public:

  ConvertToMapFromFile(std::string&, char);
  void Converting(std::string&,
		  char separator = default_map_settings::separator_between_lines_and_columns);

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
