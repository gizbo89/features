/*
 * nvector.h
 *
 *  Created on: Aug 4, 2017
 *      Author: dani
 */

#ifndef SCRATCH_SUBFOLDER_NVECTOR_H_
#define SCRATCH_SUBFOLDER_NVECTOR_H_
#include <iostream>
#include <vector>
class nvector{
public:
	nvector(){};
	double & operator[]( int index_columns ){return data[index_columns];}
	void add_Element(double t);
	nvector(const std::vector<double> foo):data(foo){};
	~nvector(){};
	void print(std::ostream& os=std::cout) const;
    double dot(const nvector &)const;
private:
	std::vector<double> data;

};

#endif /* SCRATCH_SUBFOLDER_NVECTOR_H_ */
