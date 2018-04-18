// stats.cpp - implements statistician class as defined in stats.h
// YOUR NAME(S), DATE

#include <cassert>  // provides assert
#include "stats.h"  // defines what must be implemented
#include <iostream>

using namespace std;

void statistician::next(double r){
  theLength+=1;
  theSum+= r;
  average = theSum/theLength;
  if (r<min) min = r;
  if (r>max) max = r;
}
void statistician::reset( ){
  theLength = 0;
  theSum = 0;
  average = 0;
  min = 0;
  max = 0;
}

    // CONSTANT MEMBER FUNCTIONS
int statistician::length( ) const{
  return theLength;
}
double statistician::sum( ) const{
  return theSum;
}
double statistician::mean( ) const{
  return average;
}
double statistician::minimum( ) const{
  return min;
}
double statistician::maximum( ) const{
  return max;
}
