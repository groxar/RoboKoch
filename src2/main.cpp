#include "Interval.hpp"
#include "axiomSet.hpp"
#include "Util.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	map<int,Interval> im= getIntervals("testData/A_002_Ablauf_Bsp.csv");
	
	for(auto i: im)
	{
		cout << i.first << " " << i.second.getDuration()<<endl;
	}
	
	return 0;
}
