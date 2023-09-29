/*
 * problemtrip.h
 *
 *  Created on: Nov 29, 2017
 *      Author: dani
 */

#ifndef SCRATCH_SEARCHING_PROBLEMS_PROBLEMTRIP_H_
#define SCRATCH_SEARCHING_PROBLEMS_PROBLEMTRIP_H_
#include "problem.h"
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <assert.h>
#include <string>
typedef std::map<std::string, std::vector<std::string> > mapped_net;

template <typename T>
class problemtrip: public problem<T> {
public:
	problemtrip(std::string init, std::string goal, const mapped_net& mn) :
			problem<T>(init, goal), net(mn) {
	}
	~problemtrip(){};
	const std::vector<std::string> getActions(const std::string & currentState) const;
    nodesearch<std::string>* child(const nodesearch<std::string> & p, std::string a) const;
private:
	mapped_net net;
};



template <typename T>
const std::vector<std::string> problemtrip<T>::getActions(
		const std::string & currentState) const {
	return net.at(currentState);
}


template <typename T>
nodesearch<std::string>* problemtrip<T>::child(const nodesearch<std::string> & p,
		std::string a) const {
//This function gives a new nodesearch object from a parent nodeserch p and an action.

//Check that the action is feasible for the parent state
	std::string parent_state = p.get_state();
	assert(
			std::find(getActions(parent_state).begin(),
					getActions(parent_state).end(), a)
					!= getActions(parent_state).end());
//If the action belongs to the set of actions of p, then return a new nodesearch that has as state
	//the action, and points to p.
	return new nodesearch<std::string>(a, p, a);
}

#endif /* SCRATCH_SEARCHING_PROBLEMS_PROBLEMTRIP_H_ */
