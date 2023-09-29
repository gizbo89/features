/*
 * rsa.cpp
 *
 *  Created on: Jun 23, 2018
 *      Author: dani
 */
#include "rsa.h"
#include <stdlib.h>     /* div, div_t */
#include <math.h>

#include <string>
#include <algorithm>
#include <iostream>

static int countBits(unsigned long long number);
static std::string binary_reversed(unsigned long long x);


rsa::rsa(std::string typecipher_,unsigned long long p_, unsigned long long q_):
cipher(typecipher_), p(p_), q(q_){
    //Need to add more private variables, n, totient, ...
    
}


bool rsa::multiplicativeInverse(const unsigned long long& a, signed long long& b) const{
    //computes inverse of b modulo a
    unsigned long long a0(a);
    unsigned long long b0(b);
    bool ret(false);
    unsigned long long t0(0);
    unsigned long long t(1);
    div_t divresult;
    //divresult = div (a0,b0);
    unsigned long long q = divresult.quot;
    unsigned long long r = divresult.rem;
    unsigned long long temp(0);
    while (r>0){
        temp =(t0-q*t)%a;
        t0   = t;
        t    = temp;
        a0   = b0;
        b0   = r;
        //divresult = div (a0,b0);
        q = divresult.quot;
        r = divresult.rem;
    }
    if (b0==1){
        ret = true;
        b   = t;
        if (b<0)b+=a;
    }
    
    return ret;
}

unsigned long long rsa::squareAndMultiply(unsigned long long x, unsigned long long c, unsigned long long n) const{
    unsigned long long z(1);
    int l(countBits(c));
    std::string c_binary=binary_reversed(c);
    for(int i=l-1;i >= 0; --i){
        z=(z*z)%n;
        if (c_binary[i]=='1') z=(z*x)%n;
    }
    
    return z;
}




std::string binary_reversed(unsigned long long x)
{
    std::string s;
    do
    {
        s.push_back('0' + (x & 1));
    } while (x >>= 1);
    //std::reverse(s.begin(), s.end());
    return s;
}



int countBits(unsigned long long number){
    return (int) log2(number)+1;
}

