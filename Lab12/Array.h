#pragma once 
#include <vector>
#include <iostream>
#include "X.h"

//szablon klasy będącej kontenerem o podanym rozmiarze oraz o podanym typie
template<int size ,typename T>
class Array{
public:
  Array(){}
  ~Array(){}

  T& operator[] (const int ind) {return _arr[ind];}

private:
  T _arr[size];
};

// specjalny konstruktor dla  dla 7 elementowego kontenera typu int
template<>
Array<7,int>::Array(){
  for (int i = 0 ; i < 7 ; i++)
    _arr[i]=0;
}

// specjalny konstruktor dla  dla 5 elementowego kontenera zawierającego elementy będącę wskaźnikiem na obiekt klasy X
template<>
Array<5, X*>::Array(){
  for (int i = 0 ; i < 5 ; i++)
    _arr[i] = nullptr;
}

// specjalny destruktor dla  dla 5 elementowego kontenera zawierającego elementy będącę wskaźnikiem na obiekt klasy X
template<>
Array<5, X*>::~Array(){
  for ( int i = 0 ; i < 5 ; i++){
    // if (_arr[i] != nullptr)
      delete _arr[i];
  }
}

//operator << dla kontenera zawierającego elementy, których typ nie jest wskaźnikiem 
template<int x, typename T>
std::ostream& operator<< (std::ostream& os, Array<x, T>& arr){
  for (int i = 0 ; i < x ; i++)
    os<< arr[i]<<" ";
  return os;
}

// specjalny operator << dla 5 elementowego kontenera zawierającego elementy będącę wskaźnikiem na obiekt klasy X
std::ostream& operator<< (std::ostream& os, Array<5, X*>& arr){
  for (int i = 0 ; i < 5 ; i++)
  if (arr[i] != nullptr)
    std::cout<< *arr[i]<<" ";
  return os;
}