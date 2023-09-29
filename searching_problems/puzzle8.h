/*
 * puzzle8.h
 *
 *  Created on: Dec 10, 2017
 *      Author: dani
 */
/*
 *
 *----------------->i data[i][j]
 *|1  2  3 | a b c
 *|4  0  5 | d e f
 *|6  7  8 | g h i
 *j
 */
#ifndef SCRATCH_SEARCHING_PROBLEMS_PUZZLE8_H_
#define SCRATCH_SEARCHING_PROBLEMS_PUZZLE8_H_
#include <iostream>

class puzzle8 {
public:
    puzzle8(const int a, const int b , const int c,  \
    	    const int d, const int e, const int f, \
    		const int g, const int h, const int i);
    puzzle8(puzzle8 const & other);
    bool operator==(puzzle8 const & other)const;
    const int & operator()(const size_t i, const size_t j) const;
    int & operator()(const size_t i, const size_t j);
    ~puzzle8();
    friend std::ostream& operator<<(std::ostream & output, puzzle8 const& z);
    std::pair <int,int> blank;
    static int counter;
private:
    int **data;
};

#endif /* SCRATCH_SEARCHING_PROBLEMS_PUZZLE8_H_ */
