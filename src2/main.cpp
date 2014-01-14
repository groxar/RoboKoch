#include "Interval.hpp"
#include "axiomSet.hpp"
#include "Util.hpp"
#include "TimeDomain.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main() {
	set<Interval> im = getIntervals("testData/A_002_Ablauf_Bsp.csv");
	map<Interval,map<Interval,axiomSet>> iia = getRelation("testData/A_002_Beziehungen_Bsp.csv",im);
	map<Interval,pair<Range,Range>> itime = getTimeWindow("testData/A_002_DurchfuerungBC.csv",im);
	/* for(auto i :itime)
	{
		cout << i.first.getId() <<" " << i.second.getMin()/60 <<":"<<i.second.getMin()%60 << " "<< i.second.getMax()/60 <<":"<<i.second.getMax()%60 << endl;
	}*/
	TimeDomain td(iia,itime);
	cout << td.areIntervalsInRange() << endl;
	cout << td.testRules() << endl;

	


	return 0;
}
