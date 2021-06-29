#pragma once
#include <iostream>

class File{
public:
File(const std::string name): _nazwa(name){}
virtual void print(int ile) const;
std::string getName() const {return _nazwa;}
virtual ~File() = default;
private:
std::string _nazwa;

};