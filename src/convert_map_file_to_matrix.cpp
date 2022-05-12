#include "convert_map_file_to_matrix.h"

std::vector<std::vector<MainTile*>>& ConvertToMapFromFile::GetTileMap() {
  return tile_map_;
}

int ConvertToMapFromFile::GetNumberLines() const { 
  return map_.size(); 
}

int ConvertToMapFromFile::GetNumberColumns() const { 
  return map_[0].size(); 
}

std::vector<std::vector<char>>& ConvertToMapFromFile::GetMap() {
  return map_; 
}

void ConvertToMapFromFile::ConvertingTiles() {
  for (int i = 0; i < map_.size(); ++i) {
    std::vector<MainTile*> temp;
    for (int j = 0; j < map_[i].size(); ++j) {
      if (map_[i][j] == default_tile_settings::air_tile_default_short_name) {
        temp.push_back(reinterpret_cast<MainTile*>(&tile::air_tile));
        continue;
      }
      if (map_[i][j] == default_tile_settings::damage_tile_default_short_name) {
        temp.push_back(reinterpret_cast<MainTile*>(&tile::damage_tile));
        continue;
      }
      if (map_[i][j] == default_tile_settings::finish_tile_default_short_name) {
        temp.push_back(reinterpret_cast<MainTile*>(&tile::finish_tile));
        continue;
      }
      if (map_[i][j] == default_tile_settings::stone_tile_default_short_name) {
        temp.push_back(reinterpret_cast<MainTile*>(&tile::stone_tile));
        continue;
      }
      std::cerr << "Unknown tile\n";
    }
    tile_map_.push_back(temp);
  }
}

ConvertToMapFromFile::ConvertToMapFromFile(std::string& source_file_name, 
                                           char separator)
  : separator_bettween_number_lines_and_columns_(separator)
{
  Converting(source_file_name, separator);
}

void ConvertToMapFromFile::ConvertingNumberStringAndColumns(
    std::istream& source_file, 
    int& number_of_lines, int& number_of_columns) {

  source_file >> number_of_lines;

  char separator;
  do {
    source_file >> separator;
  } while(separator != separator_bettween_number_lines_and_columns_);

  source_file >> number_of_columns;
}

void ConvertToMapFromFile::ConvertingMap(
    std::istream& source_file, int number_of_lines, int number_of_columns) {
  for (int i = 0; i < number_of_lines; ++i) {
    for (int j = 0; j < number_of_columns; ++j) {
      source_file >> map_[i][j];
    }
  }
}

void ConvertToMapFromFile::Converting(std::string& source_file_name, 
                                      char separator) { 
  std::ifstream source_file;
  source_file.open(source_file_name);

  if (source_file.is_open()) {
    std::cout << "Open map file completed\n";  
  } else {
    std::cout << "Can't open map file\n";  
    return;
  }
  int number_of_lines;
  int number_of_columns;
  ConvertingNumberStringAndColumns(
      source_file, number_of_lines, number_of_columns);
  map_ = std::vector<std::vector<char>>(number_of_lines, 
                                       std::vector<char>(number_of_columns));
  ConvertingMap(source_file, number_of_lines, number_of_columns);
  ConvertingTiles();
  source_file.close();
}
