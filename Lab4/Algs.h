#pragma once
#include "Argumenty.h"
#include <iostream>
#include <cmath>

Argumenty minimum(const Argumenty& arg){
  float min = arg[0];
for (int i = 0 ; i < arg.getDlg(); i++){
if (min > arg[i]) min = arg[i];
}
  return Argumenty::pojedynczy(min);
}

Argumenty sum(const Argumenty& arg){
  double sum = 0;
for (int i = 0 ; i < arg.getDlg(); i++){
 sum+= arg.getVal(i);
}
  return Argumenty::pojedynczy(sum);
}

Argumenty sq(const Argumenty& arg){
  double x = sqrt(arg[0]);
  return Argumenty::pojedynczy(x);
}
