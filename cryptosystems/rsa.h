/*
 * rsa.h
 *
 *  Created on: Jun 23, 2018
 *      Author: dani
 */

#ifndef SCRATCH_CRYPTOSYSTEMS_RSA_H_
#define SCRATCH_CRYPTOSYSTEMS_RSA_H_
#include "cipher.h"
#include <vector>
//Boost might enable 512bits number use.
class rsa: public cipher {
public:
	rsa(std::string typecipher_, unsigned long long p_, unsigned long long q_);
	~rsa(){};
	bool multiplicativeInverse(const unsigned long long& a,  signed long long& b) const;
    unsigned long long  squareAndMultiply(unsigned long long x,unsigned long long c,unsigned long long n) const;
private:
	unsigned long long p,q;
};





#endif /* SCRATCH_CRYPTOSYSTEMS_RSA_H_ */
