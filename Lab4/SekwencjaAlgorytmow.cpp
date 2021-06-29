#include "SekwencjaAlgorytmow.h"

void SekwencjaAlgorytmow::add(const std::function< Argumenty (const Argumenty& )> arg){
  _wek.push_back(arg);
}

 Argumenty SekwencjaAlgorytmow::procesuj(const Argumenty& arg){
   Argumenty nowe(arg);
   for (auto i : _wek){
     nowe = i(nowe);
   }
   return nowe;
 }