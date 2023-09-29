/*
 * problempuzzle8.h
 *
 *  Created on: Dec 10, 2017
 *      Author: dani
 */

#ifndef SCRATCH_SEARCHING_PROBLEMS_PROBLEMPUZZLE8_H_
#define SCRATCH_SEARCHING_PROBLEMS_PROBLEMPUZZLE8_H_
#include "problem.h"
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <assert.h>
#include <string>
#include "puzzle8.h"
template <typename T>
class problempuzzle8: public problem<T> {
public:
	problempuzzle8(const puzzle8 &init, const puzzle8 &goal) :
			problem<T>(init, goal) {
	}
	~problempuzzle8() {
	}
	const std::vector<std::string> getActions(const puzzle8 & currentState) const;
	nodesearch<puzzle8>* child(const nodesearch<puzzle8> & p,std::string a) const;
};
//the problem knows the successors for a given state, puzzle8 has only the information of the state

template<class T>
const std::vector<std::string> problempuzzle8<T>::getActions(
		const puzzle8 & currentState) const {
	std::vector<std::string> foo;
	if (currentState.blank.first == 0 && currentState.blank.second == 0) {
		foo.push_back("right");
		foo.push_back("down");
	}
	if (currentState.blank.first == 1 && currentState.blank.second == 0) {
		foo.push_back("right");
		foo.push_back("down");
		foo.push_back("left");
	}
	if (currentState.blank.first == 2 && currentState.blank.second == 0) {
		foo.push_back("left");
		foo.push_back("down");
	}
	if (currentState.blank.first == 0 && currentState.blank.second == 1) {
		foo.push_back("right");
		foo.push_back("down");
		foo.push_back("up");
	}
	if (currentState.blank.first == 1 && currentState.blank.second == 1) {
		foo.push_back("right");
		foo.push_back("down");
		foo.push_back("up");
		foo.push_back("left");
	}
	if (currentState.blank.first == 2 && currentState.blank.second == 1) {
		foo.push_back("left");
		foo.push_back("up");
		foo.push_back("down");
	}
	if (currentState.blank.first == 0 && currentState.blank.second == 2) {
		foo.push_back("right");
		foo.push_back("up");
	}
	if (currentState.blank.first == 1 && currentState.blank.second == 2) {
		foo.push_back("right");
		foo.push_back("up");
		foo.push_back("left");
	}
	if (currentState.blank.first == 2 && currentState.blank.second == 2) {
		foo.push_back("left");
		foo.push_back("up");
	}

	return foo;
}


template<class T>
nodesearch<puzzle8>* problempuzzle8<T>::child(const nodesearch<puzzle8> & p,
		std::string a) const {
//This function gives a new nodesearch object from a parent nodesearch p and an action.

//Check that the action is feasible for the parent state
	assert(
			std::find(getActions(p.get_state()).begin(),
					getActions(p.get_state()).end(), a)
					!= getActions(p.get_state()).end());
//In this case the successor has to be returned from the state of "p" and the action "a" applied to it
	puzzle8 foo(p.get_state());
	if (a == "up") {
		const int aux = foo(foo.blank.first, foo.blank.second - 1);
		foo(foo.blank.first, foo.blank.second) = aux;
		foo(foo.blank.first, foo.blank.second - 1) = 0;
		foo.blank.second--;
	} else if (a == "down") {
		const int aux = foo(foo.blank.first, foo.blank.second + 1);
		foo(foo.blank.first, foo.blank.second) = aux;
		foo(foo.blank.first, foo.blank.second + 1) = 0;
		foo.blank.second++;
	} else if (a == "right") {
		const int aux = foo(foo.blank.first + 1, foo.blank.second);
		foo(foo.blank.first, foo.blank.second) = aux;
		foo(foo.blank.first + 1, foo.blank.second) = 0;
		foo.blank.first++;
	} else if (a == "left") {
		const int aux = foo(foo.blank.first - 1, foo.blank.second);
		foo(foo.blank.first, foo.blank.second) = aux;
		foo(foo.blank.first - 1, foo.blank.second) = 0;
		foo.blank.first--;
	}
	return new nodesearch<puzzle8>(foo, p, a);
}


#endif /* SCRATCH_SEARCHING_PROBLEMS_PROBLEMPUZZLE8_H_ */
