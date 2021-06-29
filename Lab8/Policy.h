#pragma once
#include <iostream>


class Policy{
public:
  virtual std::string policyName() const = 0;

private:


};

struct CachePolicy : public Policy {
    virtual void cacheValueForArgument( double arg, double val ) const = 0; // zapamietuje warosc obliczenia dla argumentu
    virtual bool hasCacheFor( double arg ) const = 0;  // zwraca true jesli w cachu znajduje sie wartosc dla argumentu
    virtual double getCached(double arg) const = 0; // zapamietana wartosc dla argumentu
};

struct VerbosityPolicy : public Policy {
    virtual void printArgAndResult( double arg, double val) const = 0; // wypisuje na stdout argument i wynik dzialania na tym argumencie
};

//klasa nie przechowująca poprzedniech obliczeń
class NoCache: virtual public CachePolicy{
public:

  void cacheValueForArgument( double arg, double val ) const {}
  bool hasCacheFor( double arg ) const { return false;}
  double getCached(double arg) const {return 0;}
  std::string policyName() const {return "NoCache";}
private:

};

//klasa opakowuje podane do niej dane 
class Verbose: virtual public VerbosityPolicy{
public:
  //wyświetla wynik funkcji dla podanego argumentu
  void printArgAndResult( double arg, double val) const {
    std::cout<<"f(" << arg << ") = "<< val << std::endl;}

  std::string policyName() const {return "Verbose";}

private:

};

// klasa ta zapemiętuje ostani argument oraz wynik dla tego argumentu
class OneCallCache: virtual public CachePolicy {
public:
  // zapamietuje wartości
  void cacheValueForArgument( double arg, double val ) const {
    _res = val;
    _arg = arg;
  }
  //sprawdza czy ostani argument nie jest równy obecnemu
  bool hasCacheFor( double arg ) const { return arg==_arg; }
  // zwraca wynik dla danego argumentu
  double getCached(double arg) const {return _res;}

  std::string policyName() const {return "OneCallCache";}

private:
  mutable double _res = 0;
  mutable double _arg = 0;
};

class Silent: virtual public VerbosityPolicy{
public:
  // klasa Silent a więc nic nie wyświetla
  void printArgAndResult( double arg, double val) const {}
    // std::cout<<"f(" << arg << ") = "<< val << std::endl;}

  std::string policyName() const {return "Silent";}
  
};

// typedef NoCache UsedCachePolicy;
// typedef Verbose UsedVerbosityPolicy;