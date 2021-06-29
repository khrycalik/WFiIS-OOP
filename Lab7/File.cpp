#include "File.h"

void File::print(int ile) const {
  for (int i = 0 ; i< ile; i++){
    std::cout << " ";
  }
  std::cout<< _nazwa << " (File)" << std::endl;
}