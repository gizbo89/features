/*
 * problem.h
 *
 *  Created on: Nov 29, 2017
 *      Author: dani
 */

#ifndef SCRATCH_UTILS_PROBLEM_H_
#define SCRATCH_UTILS_PROBLEM_H_
#include "nodesearch.h"
#include <string>
#include <vector>
#include <iostream>
#include <deque>
/*
 * A Problem should know its state space so that it can know at each state which are the successors states
 * and which is the successor state for a given action, therefore getActions() and child are pure virtual. Moreover it needs also its initial state and its goal sate.
 * By using this template class all inherited classes that fulfill an specific problem should fill this template
 * The child() function determines a new state with the previous state and the action
 */


template <typename T>
class problem{
public:
	problem(const T &init, const T& goal):_init_state(init), _goal_state(goal){};
    virtual const std::vector<std::string> getActions(const T& currentState) const = 0;
    virtual ~problem(){};
    virtual nodesearch<T>*  child(const nodesearch<T> & p, std::string a) const = 0;
    bool    goalTest(const T& s) const;
    const T& get_initial_state()const {return _init_state;}
    const T& get_goal_state()const {return _goal_state;}
private:
    T            _init_state;
    T            _goal_state;
    //Problem should know the topology of the solutions, vector of pointers to nodesearch, and then be able to deallocate
};


template<class T>
bool problem<T>::goalTest(const T& s) const{
	bool foo;
	if (s == this->_goal_state)
		foo = true;
	else
		foo = false;
	return foo;
}



#endif /* SCRATCH_UTILS_PROBLEM_H_ */
