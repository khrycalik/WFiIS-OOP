#pragma once
#include <vector>

//klasa, która powinna być odziedziczona przy tworzeniu nowyvh obserwatorów
class Obserwator {
public:
  //fuknckja przetwarzająca dane 
  virtual void zrob(int x) = 0;

  virtual ~Obserwator() = default;
};

//obserwator zliczający wszystkie dane, w celu ich wyświetlania należy wywołać funckję suma. funkcja zrob przetwarza dane, aby móc z nich skorzystać później
class ObserwatorLicznik: public Obserwator {
public:

  int suma()
    {
    int sum = 0;
    for ( auto i : _danee ) {
        sum+=i;
      }
    return sum;
    }

  //funkcja dodająca dane do kontenera, w celu ich przechowania 
  void zrob(int x) override { _danee.push_back( x ); }

private:
  std::vector<int> _danee;

};

//klasa mająca na celu wyświetlenie otrzymanych danych, realizuje to funkcja zrob
class ObserwatorWypisywacz: public Obserwator {
public:

  void zrob(int x) override { std::cout<<x<<" "; } 

};