#include "Interval.hpp"
#include "axiomSet.hpp"
#include "Util.hpp"
#include "TimeDomain.hpp"
#include "Range.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main() {
	set<Interval> im = getIntervals("testData/A_002_Ablauf_Bsp.csv");
	map<Interval,map<Interval,axiomSet>> iia = getRelation("testData/A_002_Beziehungen_Bsp.csv",im);
	map<Interval,Range> itime = getTimeWindow("testData/A_002_DurchfuerungAC.csv",im);
	/* for(auto i :itime)
	{
		cout << i.first.getId() <<" " << i.second.getMin()/60 <<":"<<i.second.getMin()%60 << " "<< i.second.getMax()/60 <<":"<<i.second.getMax()%60 << endl;
	}*/
	TimeDomain td(iia,itime);
	cout << "Intervals in Range: " << td.areIntervalsInRange() << endl;
	cout << "Ranges valid: " << td.areRangesValid() << endl;
	cout << td.testRules() << endl;
	
	//Range test
	cout << Range(0,100)/ Range(50,150) << endl;
	cout << Range(0,10)/ Range(10,15) << endl;
	cout << Range(0,10)/ Range(11,15) << endl;
	cout << Range(5,15)/ Range(0,10) << endl;
	Range tRange(5,15);
	Range tRange2(20,232);
	cout << (tRange+5)/tRange2 << endl;
	cout << tRange << endl;

	cout << "Interval Range"<< endl;
	printIRAM(td.iram);
	cout << "Filtered Range"<<endl;
	printIRAM(td.filterImpossibleRanges());
	


	return 0;
}
