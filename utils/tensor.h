#ifndef SCRATCH_SUBFOLDER_TENSOR_H_
#define SCRATCH_SUBFOLDER_TENSOR_H_
#include <iostream>
#include <cmath> 
#include <ctgmath>
#include <fstream>
using namespace std;

class tensor {
  public:
    double a [3][3];
    tensor () {};//constructor por defecto
    tensor (const double ,const double ,const double,const double,const double ,const double);//constructor
    tensor operator + (const tensor&);//devuelve un tensor
    tensor operator * (const tensor&) const;  //devuelve un tensor  
    
};
ostream& operator << (ostream& os, const tensor& dt);
tensor operator- (const tensor& lhs, const tensor& param);
class vector {
    public:
    double v[3];
    vector (){};
    vector (const double, const double, const double);
    double operator * (const vector&) const;  //devuelve un tensor  
};
ostream& operator << (ostream& os, const vector& dt);
vector operator* (const tensor& lhs, const vector& param);

#endif
