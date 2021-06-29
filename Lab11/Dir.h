#pragma once
#include <list>
#include <iostream>



class File{
public:
File(const std::string name): _nazwa(name){}
virtual void print(int ile) const{
    for (int i = 0 ; i< ile; i++){
    std::cout << " ";
  }
  std::cout<< _nazwa << " (File)" << std::endl;
}

std::string getName() const {return _nazwa;}
virtual ~File() = default;
private:
std::string _nazwa;

};


class Dir: public File{
public:
  Dir(const std::string& napis): File(napis){}
  void operator +=(std::shared_ptr<Dir> katalog);
  friend std::ostream& operator<<(std::ostream& os , const File& jakis );
  void print( int ile) const;
  std::shared_ptr<Dir> findDir(const std::string nazwa);
  void add(std::shared_ptr<Dir> jakis) ;

  void rem(std::string nazwa){
   for (auto it = _katalogi.begin(); it != _katalogi.end(); ) {
        if ((*it)->getName()  == nazwa) {
            it = _katalogi.erase(it);
        }
        it++;
    }
  }


  ~Dir() {
    std::cout<< "Deleting Dir: " << getName()<<std::endl;
  }
protected:
  std::list<std::shared_ptr<Dir>>  _katalogi;
  int _ilosc = 0;
};

std::ostream& operator<<(std::ostream& os , const File& jakis );


void Dir::operator +=( std::shared_ptr<Dir> katalog){
  _katalogi.push_back(katalog);
}

void Dir::print( int ile) const{
  for (int i = 0; i < ile; i++){
    std::cout << " ";
  }
  std::cout << getName() << std::endl;
  for (auto i : _katalogi){
    i->print(ile+1);
  }
}


std::ostream& operator<<(std::ostream& os , const File& jakis ) {
  jakis.print(0);
  return os;
}

void Dir::add(std::shared_ptr<Dir> jakis) {
  // auto nowy = std::shared_ptr<Dir>(new Dir(jakis->getName()));
 _katalogi.push_back(jakis);
 }

std::shared_ptr<Dir> Dir::findDir(const std::string nazwa){
  for (auto i : _katalogi){
     if ( i->getName() == nazwa){
     return i;
     } else {
       if(i->findDir(nazwa) != nullptr)
      return i->findDir(nazwa);
     }
  }
  return nullptr;
}
