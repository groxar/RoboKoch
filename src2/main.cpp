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
	map<Interval,Range> itime = getTimeWindow("testData/A_002_DurchfuerungAC.csv",im);
	TimeDomain td(iia,itime);
	cout << td.areIntervalsInBounds() << endl;
	


	return 0;
}
