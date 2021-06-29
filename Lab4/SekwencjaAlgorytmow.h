#pragma once
#include <functional>
#include <vector>
#include <iostream>
#include "Argumenty.h"


class SekwencjaAlgorytmow {
  public:
 SekwencjaAlgorytmow() = default;
  void add(const std::function< Argumenty (const Argumenty& )> arg);
 Argumenty procesuj(const Argumenty& arg);
 

 private:
 std::vector <std::function< Argumenty(const Argumenty&)>> _wek = {};
};