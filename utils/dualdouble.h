/*
 * dualdouble.h
 *
 *  Created on: Jul 20, 2018
 *      Author: dani
 */

#ifndef SCRATCH_UTILS_DUALDOUBLE_H_
#define SCRATCH_UTILS_DUALDOUBLE_H_
#include <vector>
#include <iostream>

class DualDouble {
public:
    DualDouble(double val_, double der_=1.0);
    ~DualDouble(){};
    void       operator*=(DualDouble const& B);
    void       operator+=(DualDouble const& B);
    void       operator-=(DualDouble const& B);
    void       operator/=(DualDouble const& B);
    void       operator+=(double a);
    void       operator*=(double a);
    void       operator()(double a, double b);
    double get_val() const {return val;}
    double get_der() const {return der;}
    
private:
    DualDouble();//Should be non-existent?
    double val;
    double der;
    
};

DualDouble sin(const DualDouble & B);
DualDouble cos(const DualDouble & B);
DualDouble log(const DualDouble & B);
DualDouble exp(const DualDouble & B);

const DualDouble operator*(DualDouble A, DualDouble const & B);
const DualDouble operator+(DualDouble A, DualDouble const & B);
const DualDouble operator-(DualDouble A, DualDouble const & B);
const DualDouble operator/(DualDouble A, DualDouble const & B);

const DualDouble operator+(double a, DualDouble B);
const DualDouble operator+(DualDouble B, double a);

const DualDouble operator*(double a, DualDouble B);
const DualDouble operator*(DualDouble B, double a);

std::ostream&   operator<<(std::ostream&, const DualDouble&);
#endif