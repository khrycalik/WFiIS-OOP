#pragma once 
#include "Wrapper.h"
#include <iostream>

class FloatWrapper: public Wrapper{
public:
FloatWrapper(float x): _liczba(x){}
void print()const override;
Wrapper* kopiowanie() const override;
private:
float _liczba;

};