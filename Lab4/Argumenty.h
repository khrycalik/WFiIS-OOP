#pragma once
#include <iostream>

class Argumenty {
public:
  Argumenty() = default;
  Argumenty(int dlg);
  Argumenty(const Argumenty& arg);
  Argumenty& operator()(int indeks, double value);
  ~Argumenty();
  void print(std::string tekst, std::ostream& str = std::cout)const;
  int getDlg()const;
  double getVal(int indeks)const;
  static Argumenty pojedynczy (double x); 
  float operator[](int x)const {return _vals[x];}
  Argumenty& operator =(const Argumenty& jakis);
protected:
int _dlugosc;
double* _vals;
};

std::ostream& operator<<(std::ostream& os, const Argumenty& arg );