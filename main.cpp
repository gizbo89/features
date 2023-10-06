#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <ctime>
#include "searching_problems/searchalgorithms.h"
#include "searching_problems/problempuzzle8.h"
#include "searching_problems/problemtrip.h"
#include "searching_problems/problem.h"
#include "searching_problems/puzzle8.h"
#include "cryptosystems/rsa.h"
#include <algorithm>// std::reverse
#include <thread>
#include <Eigen/Dense>
using Eigen::MatrixXd;
using namespace std;
//****************************************************************************80

int main() {
	MatrixXd m(2,2);
	m(0,0) = 3;
	m(1,0) = 2.5;
	m(0,1) = -1;
	m(1,1) = m(1,0) + m(0,1);
	cout << m << endl;
	puzzle8 init(1,2,0,4,7,3,6,8,5);
	puzzle8 goal(1,2,3,4,0,5,6,7,8);
	problempuzzle8 p(init,goal);
	breadth_first(p);

	map<std::string, std::vector<std::string>> mapa;      // empty map container
		//Creating mapping for A
		std::vector<std::string> destA;
		destA.push_back("B");
		destA.push_back("C");
		mapa.insert(pair<std::string, std::vector<std::string>>("A", destA));

		//Creating mapping for B
		std::vector<std::string> destB;
		destB.push_back("A");
		destB.push_back("D");
		mapa.insert(pair<std::string, std::vector<std::string>>("B", destB));

		//Creating mapping for C
		std::vector<std::string> destC;
		destC.push_back("A");
		destC.push_back("E");
		mapa.insert(pair<std::string, std::vector<std::string>>("C", destC));

		//Creating mapping for D
		std::vector<std::string> destD;
		destD.push_back("B");
		destD.push_back("F");
		mapa.insert(pair<std::string, std::vector<std::string>>("D", destD));

		//Creating mapping for E
		std::vector<std::string> destE;
		destE.push_back("C");
		destE.push_back("F");
		mapa.insert(pair<std::string, std::vector<std::string>>("E", destE));

		//Creating mapping for F
		std::vector<std::string> destF;
		destF.push_back("D");
		destF.push_back("E");
		destF.push_back("G");
		destF.push_back("H");
		mapa.insert(pair<std::string, std::vector<std::string>>("F", destF));

		//Creating mapping for G
		std::vector<std::string> destG;
		destG.push_back("F");
		destG.push_back("J");
		mapa.insert(pair<std::string, std::vector<std::string>>("G", destG));

		//Creating mapping for H
		std::vector<std::string> destH;
		destH.push_back("F");
		destH.push_back("J");
		destH.push_back("I");
		mapa.insert(pair<std::string, std::vector<std::string>>("H", destH));

		//Creating mapping for I
		std::vector<std::string> destI;
		destI.push_back("H");
		destI.push_back("L");
		mapa.insert(pair<std::string, std::vector<std::string>>("I", destI));

		//Creating mapping for J
		std::vector<std::string> destJ;
		destJ.push_back("G");
		destJ.push_back("K");
		destJ.push_back("H");
		mapa.insert(pair<std::string, std::vector<std::string>>("J", destJ));

		//Creating mapping for K
		std::vector<std::string> destK;
		destK.push_back("J");
		mapa.insert(pair<std::string, std::vector<std::string>>("K", destK));

		//Creating mapping for L
		std::vector<std::string> destL;
		destL.push_back("M");
		destL.push_back("I");
		mapa.insert(pair<std::string, std::vector<std::string>>("L", destL));

		problemtrip b("A", "M", mapa);

		breadth_first(b);
}
//****************************************************************************80
