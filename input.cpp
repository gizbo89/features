/*
 * input.cpp
 *
 *  Created on: Jan 7, 2018
 *      Author: dani
 */
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <bitset>
#include "input.h"
#include <stdlib.h>     /* exit, EXIT_FAILURE */
using namespace std;
void input() {
	string line;
	int result;
	result = system("rm -f junk.scratch");
	result = system("cp *.scratch junk.scratch");
	if (result == 0) { //The copy operation from os was successful
		ifstream myfile("junk.scratch");
		string reference("=");
		string leftside;
		string data, type, subtype, settings;
		if (myfile.is_open()) {
			while (getline(myfile, line)) {
				//IN HERE IT GOES THE BIG WORK
				size_t found = line.find(reference);
				if (found != string::npos) {

					leftside = line.substr(0, found);
					if (leftside == "data") {
						data = line.substr(found + 1);
						cout << "data= " << data << endl;
						for (std::size_t i = 0; i < data.size(); ++i)
						  {
						      cout << bitset<8>(data.c_str()[i]) << endl;
						  }
					} else if (leftside == "subtype") {
						subtype = line.substr(found + 1);
						cout << "subtype= " << subtype << endl;
					} else if (leftside == "type") {
						type = line.substr(found + 1);
						cout << "type= " << type << endl;
					} else if (leftside == "settings") {
						type = line.substr(found + 1);
						cout << "settings= " << type << endl;
					}
					else cout<<"Wrong input for "<<leftside<<endl;
				} else
					cout << "Line << " << line<< ">> has no the correct structure." << endl;
			}
			myfile.close();
		} else
			cout << "Unable to open file";
	} else {
		cout << "No input data .scratch" << endl;
		exit(EXIT_SUCCESS);
	}
	result = system("rm junk.scratch");
}

