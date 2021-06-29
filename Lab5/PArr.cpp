#include <iostream>
#include "PArr.h"

PArr::PArr(int roz){
  _rozmiar = roz;
  _wraptab = new Wrapper*[_rozmiar];
}

PArr::PArr( PArr&& inny){
  _rozmiar = inny._rozmiar;
  _wraptab = inny._wraptab;

  inny._rozmiar = 0;
  inny._wraptab = nullptr;
}

const Wrapper* PArr::operator[](int ind)const{
return _wraptab[ind];
}

PArr& PArr::operator=(const PArr& inny){
if (&inny == this) return *this;

for (int i = 0 ; i < _rozmiar ; i++) delete _wraptab[i];

delete [] _wraptab;
_wraptab = new Wrapper*[inny._rozmiar];
_rozmiar = inny._rozmiar;
for (int i = 0 ; i < inny._rozmiar ; i++)
 _wraptab[i] = inny._wraptab[i]->kopiowanie();
return*this;
}


Wrapper*& PArr::operator[](int ind){
return _wraptab[ind];

}


std::ostream& operator<<(std::ostream& os,const PArr& tab){
  for (int i = 0 ; i < tab._rozmiar ; i++){
    tab[i]->print();
  }
  return os;
}

PArr::~PArr(){
for ( int i = 0 ; i < _rozmiar ; i++) delete _wraptab[i];
delete [] _wraptab;
}