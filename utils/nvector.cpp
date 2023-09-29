/*
 * nvector.cpp
 *
 *  Created on: Aug 4, 2017
 *      Author: dani
 */
#include "nvector.h"
#include <iostream>
#include <sstream>
void nvector::add_Element(double t){
data.push_back(t);
}

double nvector::dot(const nvector & foo) const {
	double result = 0.0;
	for (size_t i = 0; i < data.size(); i++) {
		result += data[i] * foo.data[i];
	}
	return result;
}

void nvector::print(std::ostream & os) const {
	std::stringstream message;
	message << "\n[ ";
	for (size_t i = 0; i < data.size(); i++) {
		if (!(i == (data.size() - 1)))
			message << data[i] << ", ";
		else
			message << data[i];
	}
	message << " ]";
	os << message.str();
}
