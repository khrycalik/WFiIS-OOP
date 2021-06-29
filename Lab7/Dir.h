#pragma once 
#include <iostream>
#include "File.h"

class Dir: public File{
public:
  Dir(const std::string& napis): File(napis){}
  void operator +=(File* katalog);
  friend std::ostream& operator<<(std::ostream& os , const File& jakis );
  void print( int ile) const;
  Dir* findDir(const std::string& nazwa);
  void add(File* jakis) ;
  File* get(const std::string& tekst) const;
  ~Dir();
protected:
  File*  _katalogi[10];
  int _ilosc = 0;
};

std::ostream& operator<<(std::ostream& os , const File& jakis );