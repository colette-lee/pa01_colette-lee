// stats.cpp - implements statistician class as defined in stats.h
// Colette Lee 

#include <cassert>  // provides assert
#include "stats.h"  // defines what must be implemented
#include <iostream>

using namespace std;

statistician::statistician(){
  reset();
}

void statistician::next(double r){
  theLength+=1;
  theSum+= r;
  if (theLength==1){
    min = r;
    max = r;
  } else {
    if (r<min) min = r;
    if (r>max) max = r;
  }
}
void statistician::reset( ){
  theLength = 0;
  theSum = 0;
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
  if (theLength==0) return 0;
  return theSum/theLength;
}
double statistician::minimum( ) const{
  return min;
}
double statistician::maximum( ) const{
  return max;
}
bool operator ==(const statistician& s1, const statistician& s2){
  if (s1.length() != s2.length()) return false;
  if (s1.sum() != s2.sum()) return false;
  if (s1.mean() != s2.mean()) return false;
  if (s1.minimum() != s2.minimum()) return false;
  if (s1.maximum() != s2.maximum()) return false;
  return true;
}
statistician operator + (const statistician& s1, const statistician& s2){
  statistician n;
  if (s1.length()==0) return s2;
  if (s2.length()==0) return s1;
  double newMax;
  double newMin;
  if (s1.maximum()>s2.maximum()) {
    newMax = s1.maximum();
  } else {
    newMax = s2.maximum();
  }
  if (s1.minimum()<s2.minimum()){
    newMin = s1.minimum();
  }else {
    newMin = s2.minimum();
  }
  n.next(newMax);
  n.next(newMin);
  double x =((s1.sum()+s2.sum()) - (newMax+newMin))/((s1.length()+s2.length())-2);
  for (int i=3; i <= s1.length()+s2.length(); i++){
    n.next(x);
  }
  return n;
}
statistician operator * (double scale, const statistician& s){
  statistician n;
  double newMin;
  double newMax;
  if (s.length()==0) return s;
  if (scale>0){
    newMin = s.minimum()*scale;
    newMax = s.maximum()*scale;
  }else {
    newMin = s.maximum()*scale;
    newMax = s.minimum()*scale;
  }
    
  n.next(newMin);
  n.next(newMax);
  double x =( s.sum()*scale - (newMin+newMax))/(s.length()-2);
  for (int i=3; i <= s.length(); i++){
    n.next(x);
  }
  return n;
}

