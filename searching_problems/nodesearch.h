/*
 * nodesearch.h
 *
 *  Created on: Nov 27, 2017
 *      Author: dani
 *      nodesearch is a class that stores a state T of any data structure
 */

#ifndef SCRATCH_UTILS_NODESEARCH_H_
#define SCRATCH_UTILS_NODESEARCH_H_
#include <string>
#include <iostream>
#include <ostream>

template<typename T>
class nodesearch;

template<class T>
std::ostream& operator<<(std::ostream& os, nodesearch<T> const & L);

template<typename T>
class nodesearch {
public:

	friend std::ostream & operator<<<>(std::ostream& output,
			nodesearch const & z);
	nodesearch(nodesearch const &) = delete; //We cannot copy nodesearch
	~nodesearch() {--counter;}
	nodesearch(const T &t) :
			state(t), parent_node(NULL), path_cost(0), action("none") {++counter;}
	nodesearch(const T &t, const nodesearch &parent, std::string a) :
			state(t), parent_node(&parent), path_cost(0), action(a) {++counter;}
	const T& get_state() const {
		return state;
	}
	static int counter;
private:
	T state;
	const nodesearch * parent_node;
	int path_cost;
	std::string action;
};




template<typename T>
int nodesearch<T>::counter(0);



template<typename T>
std::ostream& operator<<(std::ostream& output, nodesearch<T> const & z) {
	if (!(z.parent_node == NULL)) {
		output << z.state<<" -> "<< *(z.parent_node);
		return output;
	}
	else{
		output<<z.state;
		return output;
	}


}

#endif /* SCRATCH_UTILS_NODESEARCH_H_ */
