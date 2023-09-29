/*
 * cipher.h
 *
 *  Created on: Jan 11, 2018
 *      Author: dani
 */

#ifndef SCRATCH_CRYPTOSYSTEMS_CIPHER_H_
#define SCRATCH_CRYPTOSYSTEMS_CIPHER_H_
#include <vector>
#include <string>
class cipher {
public:
	cipher(std::string cipher_type_) :cipher_type(cipher_type_){}
	std::vector<bool> get_ciphertext() {return ciphertext;}
	virtual ~cipher() {}
	std::vector<bool> get_plaintext() {return plaintext;}
protected:
	std::string       cipher_type;
	std::vector<bool> plaintext;
	std::vector<bool> ciphertext;
};

#endif /* SCRATCH_CRYPTOSYSTEMS_CIPHER_H_ */
