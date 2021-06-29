
#pragma once
#include <string.h>
#include <iostream>


template <typename T>
class Node {
public:
  Node() = default;
  Node(const T& sth): _val(sth){}
  // T getVal() const { return _val; }
  // T* getNext() const { return _next; }
  void print(std::ostream& os ) {
    std::cout << _val << " ";
    if (_next) _next->print(os);
    }

  template<typename F>
  bool contains( const F& f ) {
    if (f(_val))
      return true;
    if (_next) return _next->contains(f);
       return false;
  }

public:
T _val = {};
Node* _next = nullptr;
};

template <typename T>
class List {
public:
  //friend std::ostream& operator<<(std::ostream& os,const List& x);
  List() = default;

  List(const List<T>& rhs) {
    auto current = rhs.head();
    while (current != nullptr) {
        add(current->_val);
        current = current->_next;
    }
  }

  List(List&& sth){
    _head = sth._head;
    _tail = sth._tail;
    sth._head = nullptr;
    sth._tail = nullptr;
  }

  ~List() {
      delete _head;
  }

  const Node<T>* head() const { return _head; } 

  List& add(const T& sth){
    auto nowy = new Node<T>(sth);
    if (_tail){
      _tail->_next = nowy;
      _tail = nowy;
    } 
    else {
      _head = _tail = nowy;
    }
    return *this;
    
  }

  
  bool contains(const T& el) const {
    auto temp=_head;
    while(temp->_next->_next) {
      if(el == temp->_val) return 1;
      temp=temp->_next;
    }
    return 0;
  }

  void print(std::ostream& os){
    if (_head) _head->print(os);
  }

private:
  Node<T>* _head = nullptr;
  Node<T>* _tail = nullptr;
};


template <typename T>
std::ostream& operator<<(std::ostream& os, List<T>& x){
  x.print(os);
  return os;
}
