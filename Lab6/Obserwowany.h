#pragma once
#include "Obserwator.h"
#include <iostream>
#include <vector>

//klasa przechowująca wszystkich przekazanych do niej obserwatorów. realizuje również przekazanie danych otrzymanych do każdego z przechowywanych obserwatorów
class Obserwowany {
public:

  //funkcja która przekazuje dane do każdego przesłanego wcześniej typu Obserwatora
  void noweDaneNadeszly(int x) 
  {
    for( auto i : _obs){
      i->zrob(x);
    }
  }

  //funkcja dodająca obserwatora, aby umożliwić przekazanie mu później danych 
  void dodajObserwatora(Obserwator* jakis) {_obs.push_back(jakis);}

protected:
  std::vector<Obserwator*> _obs;
}; 