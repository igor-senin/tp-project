#include "../include/convert_map_file_to_matrix.h"

std::vector<std::vector<MainTile*>>& ConvertToMapFromFile::GetTileMap() {
  return tile_map;
}

int ConvertToMapFromFile::GetNumberLines() const { 
  return map.size(); 
}

int ConvertToMapFromFile::GetNumberColumns() const { 
  return map[0].size(); 
}

std::vector<std::vector<char>>& ConvertToMapFromFile::GetMap() {
  return map; 
}

void ConvertToMapFromFile::ConvertingTiles() {
  for (int i = 0; i < map.size(); ++i) {
    std::vector<MainTile*> temp;
    for (int j = 0; j < map[i].size(); ++j) {
      if (map[i][j] == default_map_settings::air_default_short_name) {
        temp.push_back(&tile::air::MainTile);
        continue;
      }
      if (map[i][j] == default_map_settings::damage_tile_default_short_name) {
        temp.push_back(&tile::damage_tile::MainTile);
        continue;
      }
      if (map[i][j] == default_map_settings::default_tile_default_short_name) {
        temp.push_back(&tile::default_tile::MainTile);
        continue;
      }
      std::cerr << "Unknown tile\n";
    }
    tile_map.push_back(temp);
  }
}
ConvertToMapFromFile::ConvertToMapFromFile(
    std::string& source_file_name, 
    char separator = default_map_settings::separator_between_lines_and_columns)
  : separator_bettween_number_lines_and_columns(separator)
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
  } while(separator != separator_bettween_number_lines_and_columns);

  source_file >> number_of_columns;
}

void ConvertToMapFromFile::ConvertingMap(
    std::istream& source_file, int number_of_lines, int number_of_columns) {
  for (int i = 0; i < number_of_lines; ++i) {
    for (int j = 0; j < number_of_columns; ++j) {
      source_file >> map[i][j];
    }
  }
}

void ConvertToMapFromFile::Converting(
    std::string& source_file_name, 
    char separator //= default_map_settings::separator_between_lines_and_columns) {
) { 
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
  map = std::vector<std::vector<char>>(number_of_lines, 
                                       std::vector<char>(number_of_columns));
  ConvertingMap(source_file, number_of_lines, number_of_columns);
  ConvertingTiles();
  source_file.close();
}

int main() {
  std::string path_to_file = "../resources/map_example.txt";
  ConvertToMapFromFile test_convert(path_to_file);
  std::vector<std::vector<char>> mapa = test_convert.GetMap();
  for (int i = 0; i < mapa.size(); ++i) {
    for (int j = 0; j < mapa[i].size(); ++j) {
      std::cout << mapa[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}

