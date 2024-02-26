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
	problem(const T &init, const T& goal):_init_state(init), _goal_state(goal){frontier.push_back(new nodesearch<T>(init));}
    virtual const std::vector<std::string> getActions(const T& currentState) const = 0;
    virtual ~problem(){};
    virtual bool child(const nodesearch<T> & p, std::string a) = 0;
    nodesearch<T>* get_current_node() const {return frontier.front();}
    nodesearch<T>* get_last_created_node() const {return frontier.back();}
    bool    goalTest(const T& s) const;
    void front_to_explored();
    const T& get_initial_state()const {return _init_state;}
    const T& get_goal_state()const {return _goal_state;}
    const std::deque<nodesearch<T>*>& get_frontier()const {return frontier;}
    const std::deque<nodesearch<T>*>& get_explored()const {return explored;}
private:
    T            _init_state;
    T            _goal_state;
protected:
    //Topology of the solution space
    std::deque<nodesearch<T>*> frontier;
    std::deque<nodesearch<T>*> explored;
    bool isin(nodesearch<T>* const &s, std::deque<nodesearch<T>*> const &r);
};

template<typename T>
bool problem<T>::isin(nodesearch<T>* const &s, std::deque<nodesearch<T>*> const &r) {
	bool isin = false;
	for (auto & n : r) {
		if (n->get_state() == s->get_state()) {
			isin = true;
			break;
		}
	}

	return isin;
}

template<class T>
bool problem<T>::goalTest(const T& s) const{
	bool foo;
	if (s == this->_goal_state)
		foo = true;
	else
		foo = false;
	return foo;
}


template<class T>
void problem<T>::front_to_explored() {
	// Add current frontier node to explored queue
	explored.push_back(frontier.front());
	frontier.pop_front();// removing it from the frontier
}


#endif /* SCRATCH_UTILS_PROBLEM_H_ */
