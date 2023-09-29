/*
 * dualdouble.h
 *
 *  Created on: Jul 20, 2018
 *      Author: dani
 */

#include "dualdouble.h"
#include <cmath>
DualDouble::DualDouble(double val_, double der_) :
val(val_), der(der_) {}


void DualDouble::operator*=(DualDouble const& B){
    der  = val*B.get_der()+der*B.get_val();
    val *= B.get_val();
}


void DualDouble::operator+=(DualDouble const& B){
    der  += B.get_der();
    val  += B.get_val();
}


void DualDouble::operator-=(DualDouble const& B){
    der  -= B.get_der();
    val  -= B.get_val();
}



void DualDouble::operator/=(DualDouble const& B){
    der  = (der*B.get_val() - val*B.get_der())/(B.get_val()*B.get_val());
    val /= B.get_val();
}


void DualDouble::operator+=(double a) {
    val+=a;
}


void DualDouble::operator*=(double a) {
    der*=a;
    val*=a;
}



void DualDouble::operator()(double a, double b) {
    val=a;
    der=b;
}

//Natural functions

DualDouble sin(const DualDouble & B){
    DualDouble c(std::sin(B.get_val()),std::cos(B.get_val())*B.get_der());
    return c;
}


DualDouble cos(const DualDouble & B){
    DualDouble c(std::cos(B.get_val()),-std::sin(B.get_val())*B.get_der());
    return c;
}


DualDouble log(const DualDouble & B){
    DualDouble c(std::log(B.get_val()),B.get_der()/(B.get_val()));
    return c;
}



DualDouble exp(const DualDouble & B){
    DualDouble c(std::exp(B.get_val()),std::exp(B.get_val())*B.get_der());
    return c;
}
//End Natural functions

const DualDouble operator*(DualDouble A, DualDouble const & B) {//multiplication
    A*=B;
    return A;
}


const DualDouble operator+(DualDouble A, DualDouble const & B) {//addittion
    A+=B;
    return A;
}


const DualDouble operator-(DualDouble A, DualDouble const & B) {//substraction
    A-=B;
    return A;
}


const DualDouble operator/(DualDouble A, DualDouble const & B) {//division
    A/=B;
    return A;
}


const DualDouble operator+(double a, DualDouble B) {//double addition
    B+=a;
    return B;
}


const DualDouble operator+(DualDouble B, double a) {//double addition
    B+=a;
    return B;
}


const DualDouble operator*(double a, DualDouble B) {//double multiplication
    B*=a;
    return B;
}


const DualDouble operator*(DualDouble B, double a) {//double multiplication
    B*=a;
    return B;
}


std::ostream& operator<<(std::ostream& output, const DualDouble & B){
    output<<"("<<B.get_val()<<", "<<B.get_der()<<")"<<std::endl;
    return output;
}