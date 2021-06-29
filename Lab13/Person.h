#pragma once

#include <iostream>

class Person{
public:
  Person(std::string name, bool plec): _name(name), _plec(plec){}
  static Person kobieta(std::string name){
    return Person(name,1);
  }
  static Person mezczyzna(std::string name){
    return Person(name,0);
  }

  std::string getName()const {return _name;}

  bool isWoman() const { return _plec; }
private:
  std::string _name;
  bool _plec = {};
};

std::ostream& operator<<(std::ostream& os, const Person& per){
  std::cout<< per.getName();
  if (per.isWoman()) std::cout << " K";
  else std::cout<< " M";
  return os;
}