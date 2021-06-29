#include "IntWrapper.h"

void IntWrapper::print() const{
   std::cout<< _liczba<< " ";
}

Wrapper* IntWrapper::kopiowanie()const{
  return new IntWrapper(_liczba);
}