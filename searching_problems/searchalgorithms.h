/*
 * searchalgorithms.h
 *
 *  Created on: Dec 8, 2017
 *      Author: dani
 */

#ifndef SCRATCH_SEARCHING_PROBLEMS_SEARCHALGORITHMS_H_
#define SCRATCH_SEARCHING_PROBLEMS_SEARCHALGORITHMS_H_
#include "problem.h"
#include "puzzle8.h"
#include <iostream>
#include <deque>
template <typename T>
void breadth_first(problem<T> const & problem);



template <typename T>
void breadth_first(problem<T> & problem) {

	if (problem.goalTest(problem.get_initial_state())) {
		std::cout << "finished" << std::endl;
		return;
	}

	bool go_ = true;
	nodesearch<T>*  current = NULL;
	nodesearch<T>*  lc = NULL;

	while (go_) {


		// Check for killing while
		if(nodesearch<T>::counter > 300) go_=false;

		current = problem.get_current_node();

		problem.front_to_explored();


		for (auto& x : problem.getActions(current->get_state())) { //for each action in possible actions for a certain state
			if (problem.child(*current, x)) {//if child state is not in frontier and explored
				lc = problem.get_last_created_node();//last created node
				if (problem.goalTest(lc->get_state())) {
					std::cout << "Solution reached: " << *lc << std::endl;
					go_ = false;
					break; //affects for loop
				}
			}
		}
	}
}

#endif /* SCRATCH_SEARCHING_PROBLEMS_SEARCHALGORITHMS_H_ */
