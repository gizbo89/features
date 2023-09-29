/*
 * SPN.h
 *
 *  Created on: Jan 11, 2018
 *      Author: dani
 */

#ifndef SCRATCH_CRYPTOSYSTEMS_SPN_H_
#define SCRATCH_CRYPTOSYSTEMS_SPN_H_
#include <vector>
#include "cipher.h"
class SPN: public cipher {
public:
    SPN(std::string typecipher_,std::vector<bool> key_,std::string plaintext,size_t Nr_,int m_,int l_);
    SPN(std::string typecipher_,std::vector<bool> key_,std::vector<bool> ciphertext_,size_t Nr_,int m_,int l_);
    ~SPN(){};
private:
    std::vector<bool> string_to_bits(std::string plaintext) const;
    std::vector<bool> SPN_cipher(const std::vector<bool>& x, const std::vector<int>& PI_s, const std::vector<int>& PI_p, const std::vector<bool>& key_);
    void              sum(std::vector<bool>& w, const std::vector<bool>& k_) const;
    std::vector<int>  generate_permutation(int l, int m=1);
    std::vector<bool> convertTobit(int x) const;
    int               convertToint(const std::vector<bool>& t) const;
    std::vector<bool> substitution(std::vector<bool>& x, const std::vector<int>& PI_s) const;
    std::vector<bool> permutation(std::vector<bool>& x, const std::vector<int>& PI_p) const;
    size_t Nr;
    std::vector<bool> key;
    int m,l;
};




#endif /* SCRATCH_CRYPTOSYSTEMS_SPN_H_ */
