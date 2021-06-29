#pragma once
#include <string.h>
#include <iostream>

class MyString {
public:
  //friend std::ostream& operator<<(std::ostream& os,const MyString& x);
  MyString()=default;
  MyString (const char* tekst);
  MyString ( MyString&& inny);
  MyString& operator+=(const char* tekst);
  void operator +=(MyString inny);
  int size()const { return _roz; };
  int fragments()const;
  void print(std::ostream& os)const ;
  const MyString& fragment(int x)const;
  const char* str()const {return _napis;}
  void operator=(MyString&& inny);
  ~MyString() = default;
private:
const char* _napis = nullptr;
MyString* _next = nullptr;
int _roz = 0;
};

std::ostream& operator<<(std::ostream& os,const MyString& x);