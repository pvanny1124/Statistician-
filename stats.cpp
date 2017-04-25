//Name: Patrick Vanegas//Email: vanegas.patrick@yahoo.com//*used the same header file that was given*
//FILE: stats.cpp//CLASS IMPLEMENTED: statistician (see stats.h for documentation)

#include "stats.h"
#include <iostream>
#include <cassert>
#include <float.h>
using namespace main_savitch_2C;

namespace main_savitch_2C{ statistician::statistician() { total = 0; largest = -DBL_MAX; tinyest = DBL_MAX; count = 0; } 
void statistician::next(double r) { count++; total += r;
 if (r < tinyest) tinyest = r;  if (largest < r) largest = r;  }
 void statistician::reset() { count = 0; total = 0; tinyest = DBL_MAX; largest = -DBL_MAX;
 }
 int statistician::length() const { return count; }
 double statistician::sum() const {  return total; }
 double statistician::mean() const {  return total / count; }
 double statistician::minimum() const { assert(count > 0); return tinyest;  }
 double statistician::maximum() const { assert(count > 0); return largest; }
 bool operator==(const statistician& s1, const statistician& s2) { if (s1.sum() == s2.sum() && s1.length() == s2.length()) return true; else return false; }
 statistician operator*(double scale, const statistician& s) {
 //friend of statistician class statistician s2;  
 /*double a =  scale*s.largest; double b = scale*s.tinyest; s2.next(a); s2.next(b);*/  
 
 if (scale < 0) { s2.tinyest = scale*s.largest; s2.largest = scale*s.tinyest; s2.total = scale*s.total; }
 else{
 s2.tinyest = scale*s.tinyest; s2.largest = scale*s.largest; s2.total = scale*s.total;  }  s2.count = s.count; return s2;
 }

    statistician operator+(const statistician& s1, const statistician& s2) {
    //friend of statistician class  statistician s3; 
    //best case if (s1.count == 0 && s2.count == 0) return s3; 
    //AVERAGE CASES if (s1.tinyest < s2.tinyest) s3.tinyest = s1.tinyest; else s3.tinyest = s2.tinyest; 
    if (s1.largest < s2.largest) s3.largest = s2.largest;
    else s3.largest = s1.largest; 
    s3.count = s1.count + s2.count; 
    s3.total = s1.total + s2.total;
   return s3;
 }
 
 }
