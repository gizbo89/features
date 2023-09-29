/*
 * puzzle8.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: dani
 */
/*
 * puzzle8.cpp
 *
 *  Created on: Aug 31, 2017
 *      Author: dani
 */
#include "puzzle8.h"
using namespace std;
int puzzle8::counter(0);
puzzle8::puzzle8(const int a, const int b, const int c, const int d,
		const int e, const int f, const int g, const int h, const int i) {
	int rows(3);
	int columns(3);
	++counter;
	data = new int*[rows];
	int * foo = new int[rows * columns];
	for (int i = 0; i < rows; i++) {
		data[i] = foo + columns * i;
	}
	data[0][0] = a;
	data[1][0] = b;
	data[2][0] = c;
	data[0][1] = d;
	data[1][1] = e;
	data[2][1] = f;
	data[0][2] = g;
	data[1][2] = h;
	data[2][2] = i;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			if (data[i][j] == 0) {
				blank.first = i;
				blank.second = j;
			}
		}
	}
}

puzzle8::puzzle8(puzzle8 const & other) {
	int rows(3);
	++counter;
	int columns(3);
	data = new int*[rows];
	int * foo = new int[rows * columns];
	for (int i = 0; i < rows; i++) {
		data[i] = foo + columns * i;
	}
	blank = other.blank;
	data[0][0] = other.data[0][0];
	data[1][0] = other.data[1][0];
	data[2][0] = other.data[2][0];
	data[0][1] = other.data[0][1];
	data[1][1] = other.data[1][1];
	data[2][1] = other.data[2][1];
	data[0][2] = other.data[0][2];
	data[1][2] = other.data[1][2];
	data[2][2] = other.data[2][2];
}

const int & puzzle8::operator()(size_t i, size_t j) const {
	return data[i][j];
}

bool puzzle8::operator==(puzzle8 const & other) const {
	bool equal = true;
	for (size_t i=0; i < 3; i++) {
		for (size_t j=0; j < 3; j++) {
			if (!(data[i][j] == other.data[i][j])) {
				equal = false;
				i = 3;
				j = 3;
			}
		}
	}
	return equal;
}

int & puzzle8::operator()(size_t i, size_t j) {
	return data[i][j];
}

puzzle8::~puzzle8() {
	--counter;
	delete[] data[0];
	delete[] data;

}

std::ostream& operator<<(std::ostream & output, puzzle8 const& z) {
	output<<"\n";
	for (size_t j = 0; j < 3; j++) {
		output << "\n";
		for (size_t i = 0; i < 3; i++) {
			output << z(i, j) << " ";
		}
	}
	return output;
}

