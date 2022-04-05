#include <vector>
#include <fstream>
#include <iostream>

class ConvertToMapFromFile {
 public:                                                                            
                                                                                    
  ConvertToMapFromFile(std::string&);
  void Converting(std::string&, char separator = '*');
                                                                                    
  int GetNumberLines() const;                                
  int GetNumberColumns() const;
  const std::vector<std::vector<char>>& GetMap();
                                                                                    
 private:                                                                           
                                                                                    
  void ConvertingNumberStringAndColumns(std::istream& source_file, int&, int&);     
  void ConvertingMap(std::istream& source_file);                                    
  void ConvertingTiles(std::istream& source_file);                                  
                                                                                    
 private:                                                                           
                                                                                    
  char separator_bettween_number_lines_and_columns;                                 
  std::vector<std::vector<char>> map;                                               
};
