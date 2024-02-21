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

template<typename T>
static bool isin(T s, std::deque<T> r) {
	bool isin = false;
	for (auto & n : r) {
		if (n->get_state() == s->get_state()) {
			isin = true;
			break;
		}
	}
	return isin;
}


template <typename T>
void breadth_first(problem<T> const & problem) {

	//Create FIFO queues
	std::deque<nodesearch<T>*> frontier;
	std::deque<nodesearch<T>*> explored;


	nodesearch<T> * p1 = new nodesearch<T>(problem.get_initial_state());//assign the node an initial state

	if (problem.goalTest(p1->get_state())) {
		std::cout << "finished" << std::endl;
		return;
	}

	frontier.push_back(p1);//add initial node to the frontier

	bool go_ = true;

	while (go_) {

		// Check for killing while
		if(nodesearch<T>::counter > 300) go_=false;
		if (frontier.empty()) {
			std::cout << "Failure" << std::endl;
			break;
		}
		// Add current frontier node to explored queue.
		explored.push_back(frontier.front());

		nodesearch<T>*  node = frontier.front();

		frontier.pop_front();// removing it from the frontier

		for (auto& x : problem.getActions(node->get_state())) { //for each action in possible actions for a certain state

			nodesearch<T> * child = problem.child(*node, x);

			if (!isin<nodesearch<T> *>(child, frontier) && !isin<nodesearch<T> *>(child, explored)) {//if child state is not in frontier and explored

				if (problem.goalTest(child->get_state())) {
					std::cout << "Solution reached: " << *child << std::endl;
					go_ = false;
					frontier.push_back(child);
					break; //affects for loop
				}
				frontier.push_back(child);
			}
			else {
				delete child;
			}
		}
	}
	std::cout<<"Number of nodesearch before desallocating dynamic memory: "<<nodesearch<T>::counter<<std::endl;
	for (auto & p : frontier) {
		delete p;
	}
	for (auto & p : explored) {
		delete p;
	}
	std::cout<<"Number of nodesearch after desallocating dynamic memory: "<<nodesearch<T>::counter<<std::endl;
}

#endif /* SCRATCH_SEARCHING_PROBLEMS_SEARCHALGORITHMS_H_ */
