#include "Wrapper.h"
#include <iostream>

class IntWrapper : public Wrapper{
public:
Wrapper* kopiowanie()const override ;
IntWrapper( int x): _liczba(x){};
void print() const override;
private:
int _liczba;

};