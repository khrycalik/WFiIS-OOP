#include "MyString.h"


  MyString::MyString (const char* tekst){
     _roz = strlen(tekst);
     _napis = new char[_roz];
     _napis = tekst;
     }

MyString& MyString::operator+=(const char* tekst){
 MyString *a = new MyString (tekst);
 MyString *temp = this;
  while(temp->_next != nullptr){
   temp = temp->_next;
  }
   temp->_next = a;
  _roz += strlen( tekst );
  return *this;
}

void MyString::operator +=( MyString inny){
  MyString *a = new MyString();
   a->_roz = inny._roz;
  a->_napis = inny._napis;
  a->_next = inny._next;
 MyString *temp = this;
  while(temp->_next != nullptr){
   temp = temp->_next;
  }
   _roz = inny._roz;
  //  _napis = new char[_roz];
  //  _napis = inny._napis;
   temp->_next  = a;
   inny._napis = nullptr;
   inny._next = nullptr;
   inny._roz = inny.size();
 }

int MyString::fragments()const{
   int frag = 1;
  if ( _next != nullptr){
    frag += _next->fragments();
  }
  return frag;
}

void MyString::print(std::ostream& os)const {
  if(_napis !=nullptr){
  os << _napis ;
    if( _next != nullptr){
    _next->print(os);
  }
  }
}


std::ostream& operator<<(std::ostream& os,const MyString& x){
  x.print(os);
  return os;
}


 MyString::MyString (  MyString&& inny){
   _roz = inny._roz;
   _napis = new char[_roz];
   _napis = inny._napis;
   _next  = inny._next;
    inny._napis = nullptr;
    inny._next = nullptr;
    inny._roz = 0;
 
 }

 void MyString::operator=(MyString&& inny){
  _roz = inny._roz;
   _napis = new char[_roz];
   _napis = inny._napis;
   _next  = inny._next;
    inny._napis = nullptr;
    inny._next = nullptr;
    inny._roz = 0;
 }

  const MyString& MyString::fragment(int x)const{
MyString *temp = _next;
    for ( int i = 0 ; i< x-1 ; i++){
temp = temp->_next;
    }
    return *temp;
  }