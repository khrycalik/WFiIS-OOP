#pragma once
#include <iostream>

class Msg;
class DoUndoAction{};


class KeepInt{
public:
  KeepInt() = default;
  KeepInt( int val): _val(val) , _ad(&val){}
private:
  int *_ad;
 int _val;
};


class DoUndo: public DoUndoAction{
public:
  DoUndo(Msg ms): _m(ms){}
  DoUndo(KeepInt val): _k(val){}
private:
  Msg _m;
  KeepInt _k;

};

