#include <utility>
#include <map>
#include <cmath>
#include <iostream>

/*
Solution for https://open.kattis.com/problems/quadrant
*/

int determineQuadrant(int x, int y)
{
	typedef std::pair<bool, bool> boolPair;
	std::map<boolPair, int> quadMap;


	boolPair p1 = std::make_pair(false, false);
	boolPair p2 = std::make_pair(true, false);
	boolPair p3 = std::make_pair(true, true);
	boolPair p4 = std::make_pair(false, true);

	std::map<boolPair,int>::iterator it = quadMap.begin();

	quadMap[p1] = 1;
	quadMap[p2] = 2;
	quadMap[p3] = 3;
	quadMap[p4] = 4;

	boolPair quadrant = std::make_pair(std::signbit(x), std::signbit(y));

	return quadMap.find(quadrant)->second;
	
}


int main()
{
	int x, y;
	std::cin >> x >> y;
	std::cout << determineQuadrant(x, y); 
}