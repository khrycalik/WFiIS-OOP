#pragma once 
#include <iostream>
#include <string>

//klasa bazowa, przechowuje napis, dostarcza metody dostepowej, a podczas destrukcji wypisuje przechowywany napis.
class X{
public:
  X() = default;
  X(std::string napis): _napis(napis){}
  virtual std::string GetStr() { return _napis;}

  virtual ~X() {std::cout << "deleting X " << _napis << std::endl;}
private:
  std::string _napis; 

};

// klasa pochodna klasy X realizująca dokładnie te same funkcje, różni się jedynie wypisaniem w momencie wypisania destruktora
class Y: public X{
public: 
  Y(std::string napis): X(napis){}
  ~Y() {std::cout << "deleting Y " << this->GetStr() << std::endl;}
private:
};

std::ostream& operator<< (std::ostream& os ,  X& xClass){
  return (os << xClass.GetStr());
}

std::ostream& operator<< (std::ostream& os ,  Y& yClass){
  return (os << yClass.GetStr());
}

