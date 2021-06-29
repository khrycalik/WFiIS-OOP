#pragma once
#include <iostream>
#include <cmath>
#include "Policy.h"



#define MyCalculation(a, b, c) \
  class a: public b, public c{ \
public: \
  a() = default; \
  void eval(int arg) { \
    if (hasCacheFor(arg)){ \
      return; \
    } \
    double result = sqrt( pow(arg - 7, 2) ); \
    printArgAndResult(arg, result); \
    cacheValueForArgument(arg , result); \
  } \
}; 

// typedef NoCache UsedCachePolicy;
// typedef Verbose UsedVerbosityPolicy;
// class X : public UsedCachePolicy, public UsedVerbosityPolicy {
//   void jakiesObliczenie(double arg) {
//       // uzywamy tutaj powyzszych polityk np.
//       double result = sqrt( pow(arg - 7, 2) );
//       printArgAndResult(ar, result);
//       //....
//     }
// public:
//   void eval(double x){}
// };

// class Calc1: public NoCache, public Verbose {
// public:
//   Calc1() = default;

//   void eval(int arg) {
//     double result = sqrt( pow(arg - 7, 2) );
//     printArgAndResult(arg, result);
//   }

// };

// class Calc2: public OneCallCache, public Verbose{
// public:
//   Calc2() = default;

//   void eval(int arg) {
//     if (hasCacheFor(arg)){
//       return;
//     }
//     double result = sqrt( pow(arg - 7, 2) );
//     printArgAndResult(arg, result);
//     cacheValueForArgument(arg , result);
//   }

// };

// class Calc3: public OneCallCache, public Silent{
// public:
//   Calc3() = default;

//   void eval(int arg) {
//     double result = sqrt( pow(arg - 7, 2) );
//     printArgAndResult(arg, result);
//   }

// };