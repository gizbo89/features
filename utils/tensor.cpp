// overloading operators example
#include "tensor.h"
vector::vector(const double a1,const double a2,const double a3){

	v[0]=a1;
	v[1]=a2;
	v[2]=a3;
	
}

ostream& operator << (ostream& os, const vector& dt)
{
os <<"[" << dt.v[0]<< "]" << endl;
os <<"[" << dt.v[1]<< "]" <<endl;
os <<"[" << dt.v[2]<< "]" <<endl;


return os;
}

double vector::operator*  ( const vector& param) const {

  double temp = v[0]*param.v[0]+ v[1]*param.v[1]+ v[2]*param.v[2];
 
  return temp;
}
///////////////////////////////////////////////////////////////////////

ostream& operator << (ostream& os, const tensor& dt)
{
os <<"\n[" << dt.a[0][0]<< " "<< dt.a[0][1] <<" " << dt.a[0][2] << "]" << endl;
os <<"[" << dt.a[1][0]<<" "  << dt.a[1][1]<<" "  << dt.a[1][2] << "]" <<endl;
os <<"[" << dt.a[2][0]<<" "  << dt.a[2][1]<<" "  << dt.a[2][2] << "]";


return os;
}
tensor::tensor(const double a1,const double a2,const double a3,const double a4,const double a5,const double a6){

	a[0][0]=a1;
	a[1][1]=a2;
	a[2][2]=a3;
	a[1][2]=a4;
	a[2][1]=a4;
	a[0][2]=a5;
	a[2][0]=a5;
	a[0][1]=a6;
	a[1][0]=a6;
}

tensor tensor::operator+ (const tensor& param) {
  tensor temp;
  temp.a[0][0] = a[0][0] + param.a[0][0];
  temp.a[1][1] = a[1][1] + param.a[1][1];
  temp.a[2][2] = a[2][2] + param.a[2][2];
  temp.a[1][2] = a[1][2] + param.a[1][2];
  temp.a[2][1] = a[2][1] + param.a[2][1];
  temp.a[0][2] = a[0][2] + param.a[0][2];
  temp.a[2][0] = a[2][0] + param.a[2][0];
  temp.a[0][1] = a[0][1] + param.a[0][1];
  temp.a[1][0] = a[1][0] + param.a[1][0];
  return temp;
}

tensor tensor::operator*  ( const tensor& param) const {
  tensor temp {0.0,0.0,0.0,0.0,0.0,0.0};
  int ndm(3);
  int  i, j, k;
  for ( i=0 ; i<ndm ; ++i )
  {
    for( j=0; j<ndm ; ++j )
     {
       for( k=0; k<ndm ; ++k )
      {
       
       temp.a[i][j] += a[i][k] * param.a[k][j];
       
      }
     }
  }
  
  return temp;
}
//non-member functions
tensor operator- (const tensor& lhs, const tensor& param) {
   tensor temp;
  temp.a[0][0] = lhs.a[0][0] - param.a[0][0];
  temp.a[1][1] = lhs.a[1][1] - param.a[1][1];
  temp.a[2][2] = lhs.a[2][2] - param.a[2][2];
  temp.a[1][2] = lhs.a[1][2] - param.a[1][2];
  temp.a[2][1] = lhs.a[2][1] - param.a[2][1];
  temp.a[0][2] = lhs.a[0][2] - param.a[0][2];
  temp.a[2][0] = lhs.a[2][0] - param.a[2][0];
  temp.a[0][1] = lhs.a[0][1] - param.a[0][1];
  temp.a[1][0] = lhs.a[1][0] - param.a[1][0];
  return temp;
}


vector operator* (const tensor& lhs, const vector& param) {
  vector temp {0.0,0.0,0.0};
   int ndm(3);
  int  i, k;
  for ( i=0 ; i<ndm ; ++i )
  {
    
       for( k=0; k<ndm ; ++k )
      {
       
       temp.v[i] += lhs.a[i][k] * param.v[k];
       
      }
     
  }
  
  return temp;
}
