#include "List.h"


  // List& List::add(const T& sth){
  //    _roz = strlen(tekst);
  //    _napis = new T[_roz];
  //    _napis = tekst;
  //    }

// List& List::operator+=(const char* tekst){
//  List *a = new List (tekst);
//  List *temp = this;
//   while(temp->_next != nullptr){
//    temp = temp->_next;
//   }
//    temp->_next = a;
//   _roz += strlen( tekst );
//   return *this;
// }

// void List::operator +=( List inny){
//   List *a = new List();
//    a->_roz = inny._roz;
//   a->_napis = inny._napis;
//   a->_next = inny._next;
//  List *temp = this;
//   while(temp->_next != nullptr){
//    temp = temp->_next;
//   }
//    _roz = inny._roz;
//   //  _napis = new char[_roz];
//   //  _napis = inny._napis;
//    temp->_next  = a;
//    inny._napis = nullptr;
//    inny._next = nullptr;
//    inny._roz = inny.size();
//  }

// int List::fragments()const{
//    int frag = 1;
//   if ( _next != nullptr){
//     frag += _next->fragments();
//   }
//   return frag;
// }

// void List::print(std::ostream& os)const {
//   if(_napis !=nullptr){
//   os << _napis ;
//     if( _next != nullptr){
//     _next->print(os);
//   }
//   }
// }


// std::ostream& operator<<(std::ostream& os,const List<T>& x){
//   // x.print(os);
//   return os;
// }


//  List::List (  List&& inny){
//    _roz = inny._roz;
//    _napis = new char[_roz];
//    _napis = inny._napis;
//    _next  = inny._next;
//     inny._napis = nullptr;
//     inny._next = nullptr;
//     inny._roz = 0;
 
//  }

//  void List::operator=(List&& inny){
//   _roz = inny._roz;
//    _napis = new char[_roz];
//    _napis = inny._napis;
//    _next  = inny._next;
//     inny._napis = nullptr;
//     inny._next = nullptr;
//     inny._roz = 0;
//  }

//   const List& List::fragment(int x)const{
// List *temp = _next;
//     for ( int i = 0 ; i< x-1 ; i++){
// temp = temp->_next;
//     }
//     return *temp;
//   }