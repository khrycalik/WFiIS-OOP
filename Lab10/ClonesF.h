#pragma once

#include <iostream>
#include <vector>


class NodeInterface{
public:

// domyślny konstruktor obejktu typu NodeInterface
  NodeInterface() = default;

// virtualny domyślny destruktor obejktu typu NodeInterface
  virtual ~NodeInterface()  = default;
};


template<typename T>
class Node: public NodeInterface{
public:

//konstruktor klasy Node przyjmujący obiekt typu T do przechowania
  Node(const T& sth) : _object(sth){}

// domyślny destruktor obejktu typu NodeInterface
  ~Node() = default;

// funkcja zwracająca przechowywany obiekt
  const T& getVal() const { return _object;}

private:
  T _object;
};


class ClonesF{
public:

//funkcja dodająca objekt typu T na koniec kontenera 
  template<typename T>
  const void add(const T& sth) 
  {
    auto newObj = new Node<T>(sth);
    _arr.push_back(newObj);
  }

//funkcja zwracająca klon obiektu typu T
  template<typename T>
  const T& clone() const
  {
    for (unsigned int i = 0 ; i < _arr.size() ; i++){
      Node<T>* cast = dynamic_cast<Node<T>*>(_arr.at(i));
      if (cast != nullptr) return cast->getVal();
      // return dynamic_cast<Node<T>*>(i)->getVal();
    }
  }

//funkcja wynieniająca przchowywaną wartość typu T na przekazaną do funkcji, musi być zgodność typów
  template<typename T>
  void replace(const T& obj)
  {
    for (unsigned int i = 0 ; i < _arr.size() ; i++){
      Node<T>* cast = dynamic_cast<Node<T>*>(_arr.at(i));
      if (cast){
        delete _arr.at(i);
        _arr.at(i) = new Node<T>(obj);
      }
    }
  }

//destruktor klasy czyszczący wszystkie obiekty zawarte w kontenerze
  ~ClonesF(){
    for ( auto i : _arr) 
      delete i;
  }

private:
  std::vector<NodeInterface*> _arr = {};  
};

