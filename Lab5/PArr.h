#pragma once
#include "Wrapper.h"

class PArr {
public:
PArr(int roz);
PArr( PArr&& inny);
const Wrapper* operator[](int ind)const;
Wrapper*& operator[](int ind);
PArr& operator=(const PArr& inny);
~PArr();
friend std::ostream& operator<<(std::ostream& os,const PArr& tab);

private:
Wrapper** _wraptab;
int _rozmiar;
};
