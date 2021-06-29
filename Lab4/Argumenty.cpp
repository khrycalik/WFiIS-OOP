#include "Argumenty.h"

Argumenty::Argumenty(int dlg){
  _dlugosc = dlg;
  _vals = new double[dlg];
}

Argumenty& Argumenty::operator()(int indeks, double value){
  _vals[indeks] = value;
  return *this;
}

void Argumenty::print(std::string tekst, std::ostream& str)const{
str <<tekst;
//std::cout<< tekst;
for( int i = 0 ; i<_dlugosc; i++){
    str << " ";
    str << _vals[i];
  }
  str<< std::endl;
}

int Argumenty::getDlg()const{
return _dlugosc;
}

double Argumenty::getVal(int indeks)const{
return _vals[indeks];
}

Argumenty::~Argumenty(){
  delete [] _vals;
}

std::ostream& operator<<(std::ostream& os, const Argumenty& arg )
{
  arg.print("");
  return os;
}

  Argumenty Argumenty::pojedynczy(double x){
    return Argumenty(1)(0,x);
  }

Argumenty::Argumenty(const Argumenty& arg){
  _dlugosc = arg.getDlg();
  _vals = new double[_dlugosc];
  for (int i = 0 ; i < _dlugosc; i++){
     _vals[i] = arg.getVal(i);
  }
}

Argumenty& Argumenty::operator =(const Argumenty& jakis){
  if (_vals == jakis._vals) return *this;
  delete [] _vals;
  _vals = new double[jakis._dlugosc];
  _dlugosc = jakis._dlugosc;
   for (int i = 0 ; i<_dlugosc ; i++)
   _vals[i] = jakis._vals[i];
   return *this;
}