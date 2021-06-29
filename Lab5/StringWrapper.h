#include "Wrapper.h"
#include <iostream>

class StringWrapper : public Wrapper{
public:
StringWrapper(const char* tekst){strcpy(_napis,tekst);}
Wrapper* kopiowanie()const override;
void print()const override;

private:
char _napis[80];
} ;