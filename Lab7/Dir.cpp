#include "Dir.h"

void Dir::operator +=( File* katalog){
  _katalogi[_ilosc] = katalog;
  _ilosc++;
  // std::cout<<_ilosc;
}

void Dir::print( int ile) const{
  for (int i = 0; i < ile; i++){
    std::cout << " ";
  }
  std::cout << getName() << " (Dir)" << std::endl;
  for (int i = 0; i < _ilosc; i++){
    _katalogi[i]->print(ile+1);
  }
}


std::ostream& operator<<(std::ostream& os , const File& jakis ) {
  jakis.print(0);
  return os;
}

void Dir::add(File* jakis) {
  // _ilosc++;
  *this += jakis;
 }

Dir* Dir::findDir(const std::string& nazwa){
  for (int i = 0 ; i< _ilosc ; i++){
     
     if ( _katalogi[i]->getName() == nazwa){
     return dynamic_cast<Dir*> (_katalogi[i]);
     } else {
      return dynamic_cast<Dir*> (_katalogi[i])->findDir(nazwa);
     }
  }
  return nullptr;
}

File* Dir::get(const std::string& tekst) const{
  // for (int i = 0 ; i< _ilosc ; i++){
  //   if ( _katalogi[i]->getName() == tekst){
    return dynamic_cast<Dir*>(_katalogi[0]);
    //} else {
    //  return dynamic_cast<Dir*>(_katalogi[i])->get(tekst);
    // }
  //}
  // return nullptr;
}

Dir::~Dir(){
  std::cout << "Deleting Dir: " <<getName() << std::endl;
  for (int i = 0 ; i < _ilosc ; i++){
   std::cout << "About to delete " << _katalogi[i]->getName() << std::endl;
   delete _katalogi[i];
  }
}