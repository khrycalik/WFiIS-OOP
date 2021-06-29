#include "StringWrapper.h"

void StringWrapper::print() const {
std::cout<<_napis<< " ";
}

Wrapper* StringWrapper::kopiowanie()const{
  return new StringWrapper(_napis);
}