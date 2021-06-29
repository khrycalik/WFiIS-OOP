#include "FloatWrapper.h"

void FloatWrapper::print() const{
   std::cout << _liczba << " ";
}

Wrapper* FloatWrapper::kopiowanie()const{
return new FloatWrapper(_liczba);
}