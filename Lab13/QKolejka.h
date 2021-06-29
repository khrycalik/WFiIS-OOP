#pragma once
#include "Person.h"
#include <iostream>
#include <functional>
#include <list>
#include <initializer_list>

template<typename T>
class QKolejka{
public:
  QKolejka(std::function<int(const T&)> fun): _fun(fun){}

  void dodaj(const T& per){
    if (_lista.empty()) _lista.push_back(per);
    else {
      for (auto it = _lista.begin(); it != _lista.end();it++){
        if(_fun(per) < _fun(*it) ) {
          _lista.insert(it,per);
          return;
        }
        _lista.push_back(per);
        return;
      }
    }
  }

  void dodaj(std::initializer_list<T> lista){
    for (auto sth : lista) dodaj(sth);
  }

  using const_reverse_iterator = typename
  std::list<T>::const_reverse_iterator;
  typename
  std::list<T>::const_reverse_iterator rbegin()const { return _lista.crbegin();}
  typename
  std::list<T>::const_reverse_iterator rend()const { return _lista.crend();}
  // typename
  // std::list<T>::iterator begin() {return _lista.begin();}
  // typename
  // std::list<T>::iterator end() {return _lista.end();}

  typename
  std::list<T>::const_iterator begin() const {return _lista.cbegin();}
  typename
  std::list<T>::const_iterator end() const {return _lista.cend();}

private:
  std::list<T> _lista={};
  std::function<int(const T&)> _fun;
};

