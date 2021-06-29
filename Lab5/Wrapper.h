#pragma once
#include <cstring>

class Wrapper{
public:
Wrapper() = default;
virtual ~Wrapper() = default;
virtual void print()const = 0;
virtual Wrapper* kopiowanie() const = 0;
private:

};