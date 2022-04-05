#include "convert_map_file_to_matrix.h"

// need ConvertingTiles
int ConvertToMapFromFile::GetNumberLines() const { 
  return map.size(); 
}

int ConvertToMapFromFile::GetNumberColumns() const { 
  return map[0].size(); 
}

const std::vector<std::vector<char>>& ConvertToMapFromFile::GetMap() { 
  return map; 
}

ConvertToMapFromFile::ConvertToMapFromFile(
    std::string& source_file_name, char separator = '*')
  : separator_bettween_number_lines_and_columns(separator)
{
  Converting(source_file_name);
}

void ConvertingNumberStringAndColumns(std::istream& source_file, 
    int& number_of_lines, int& number_of_columns) {

  sources_file >> number_of_lines;
  char separator;
  do {
    source_file >> separator;
  } while(separator != separator_bettween_number_lines_and_columns);
  source_file >> number_of_columns;
}

void ConvertingMap(std::istream& source_file) {
  for (int i = 0; i < number_of_lines; ++i) {
    for (int j = 0; j < number_of_columns; ++j) {
      source_file >> map[i][j];
    }
  }
}

void ConvertToMapFromFile::Converting(std::string& source_file_name) {
  
  ifstream source_file;
  sources_file.open(file_name);

  if (sources_file.is_open()) {
    std::cout << "Open map file completed\n";  
  } else {
    std::cout << "Can't open map file\n";  
    return;
  }
  int number_of_lines;
  int number_of_columns;
  ConvertingNumberStringAndColumns(source_file, number_of_lines, 
                                   number_of_columns);
  map = std::vector<std::vector<char>>(number_of_lines, 
                                       std::vector<char>(number_of_columns));
  ConvertingMap(source_file);
  ConvertingTiles(source_file);
  sources.close();
}

