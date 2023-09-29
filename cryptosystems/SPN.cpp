/*
 * SPN.cpp
 *
 *  Created on: Jan 11, 2018
 *      Author: dani
 */
#include <bitset>
#include <math.h>
#include "SPN.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <random>       // std::default_random_engine
#include <algorithm>    // std::shuffle
#include <assert.h>
using namespace std;
SPN::SPN(std::string typecipher_, std::vector<bool> key_,
		std::string plaintext_, size_t Nr_, int m_, int l_) :
		cipher(typecipher_), Nr(Nr_), m(m_), l(l_), key(key_) {
	plaintext = string_to_bits(plaintext_); //Now we have a plaintext as 0's and 1's
	std::vector<int> PI_S = generate_permutation(l);
	std::vector<int> PI_P = generate_permutation(l, m);
	ciphertext = SPN_cipher(plaintext, PI_S, PI_P, key);
}

SPN::SPN(std::string typecipher_, std::vector<bool> key_,
		std::vector<bool> ciphertext_, size_t Nr_, int m_, int l_) :
		cipher(typecipher_), Nr(Nr_), m(m_), l(l_), key(key_) {

	//do something
}

vector<bool> SPN::convertTobit(int i) const {
	std::vector<bool> vec;
	std::bitset<8> b(i);
	assert(l <= 8); //in-built limit
	for (int j = l - 1; j >= 0; --j) {
		vec.push_back((bool) b[j]);
	}
	return vec;
}

int SPN::convertToint(const std::vector<bool>& bits) const {
	int result = 0;
	int base = 1;

	//Supposing the MSB is at the begin of the bits vector:
	for (int j = l - 1; j >= 0; --j) {
		result += bits[j] * base;
		base *= 2;
	}
	return result;
}

std::vector<int> SPN::generate_permutation(int l, int m) {
	std::vector<int> foo;
	int value;
	if (m == 1) { //generate substitution
		//value = (int) pow(2.0, (double) l);
		//for (int i = 0; i < value; i++) {
		//	foo.push_back(i);
		//}
		foo.push_back(3);
		foo.push_back(2);
		foo.push_back(1);
				foo.push_back(0);
	} else { //generate permutation
	//	value = m * l;
		//for (int i = 0; i < (m * l); i++) {
			//foo.push_back(i);
		//}
		foo.push_back(3);
				foo.push_back(2);
				foo.push_back(4);
						foo.push_back(5);
						foo.push_back(0);
												foo.push_back(1);
	}
	unsigned seed = 4.7;
	//shuffle(foo.begin(), foo.end(), std::default_random_engine(seed));
	return foo;
}

std::vector<bool> SPN::permutation(std::vector<bool>& x,
		const std::vector<int>& PI_p) const {
	std::vector<bool>::iterator foo = x.begin();
	std::vector<bool>::iterator foo1 = foo + m*l;
	while (foo != x.end()) {
		vector<bool> b(foo, foo1);
		vector<bool> v(foo, foo1);
		for (int i=0; i<m*l;i++){
			b[i] = v[PI_p[i]];
		}
		std::copy(b.begin(), b.end(), foo);

		foo = foo + m*l;
		foo1 = foo1 + m*l;
	}
	return x;
}

std::vector<bool> SPN::string_to_bits(std::string plaintext) const {//checked
	std::vector<bool> foo;
	for (std::size_t i = 0; i < plaintext.size(); ++i) {
		for (int j = 7; j >= 0; --j) {
			foo.push_back((bool) bitset<8>(plaintext.c_str()[i])[j]);
		}
	}
	int r = 8 * (int) plaintext.size() % (m * l);
	int extrazeros = m * l - r;
	for (int j = 0; j < extrazeros; ++j)
		foo.push_back(false);
	return foo;
}

std::vector<bool> SPN::SPN_cipher(const std::vector<bool>& x,
		const std::vector<int>& PI_s, const std::vector<int>& PI_p,
		const std::vector<bool>& key_) {
	std::vector<bool> w = x;
    ///LOOP
	for (size_t r = 0; r < Nr; r++) {
		sum(w, key_);
		substitution(w, PI_s);
		permutation(w, PI_p);
	}
    //END_LOOP
    sum(w, key_);
    substitution(w, PI_s);
    sum(w, key_);
    return w;
}

std::vector<bool> SPN::substitution(std::vector<bool>& x,//checked
		const std::vector<int>& PI_s) const {
	std::vector<bool>::iterator foo = x.begin();
	std::vector<bool>::iterator foo1 = foo + l;
	while (foo != x.end()) {
		vector<bool> b(foo, foo1);
		b = convertTobit(PI_s[convertToint(b)]);

		std::copy(b.begin(), b.end(), foo);

		foo = foo + l;
		foo1 = foo1 + l;
	}
	return x;
}

void SPN::sum(std::vector<bool>& w, const std::vector<bool>& k_) const {//CHECKED
	for (int i = 0; i < (int) w.size() / (m * l); i++) {
		for (int j = 0; j < m * l; j++) {
			w[j + i * (m * l)] = w[j + i * (m * l)] ^ k_[j];
		}
	}
}
