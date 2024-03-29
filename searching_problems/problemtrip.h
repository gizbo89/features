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

class problemtrip: public problem<std::string> {
public:
	problemtrip(std::string init, std::string goal, const mapped_net& mn) :
			problem(init, goal), net(mn) {
	}
	~problemtrip(){};
	const std::vector<std::string> getActions(const std::string & currentState) const;
    bool child(const nodesearch<std::string> & p, std::string a);
private:
	mapped_net net;
};



const std::vector<std::string> problemtrip::getActions(
		const std::string & currentState) const {
	return net.at(currentState);
}


bool problemtrip::child(const nodesearch<std::string> & p,
		std::string a) {
//This function gives a new nodesearch object from a parent nodeserch p and an action.

//Check that the action is feasible for the parent state
	std::string parent_state = p.get_state();
	assert(
			std::find(getActions(parent_state).begin(),
					getActions(parent_state).end(), a)
					!= getActions(parent_state).end());
	//If the action belongs to the set of actions of p, then return a new nodesearch that has as state
	//the action, and points to p.
	nodesearch<std::string>* aux = new nodesearch<std::string>(a, p, a);

	if (!problem<std::string>::isin(aux, frontier) && !problem<std::string>::isin(aux, explored)){
		frontier.push_back(aux);
		return true;
	}
	else{
		delete aux;
		return false;
	}
}

#endif /* SCRATCH_SEARCHING_PROBLEMS_PROBLEMTRIP_H_ */
