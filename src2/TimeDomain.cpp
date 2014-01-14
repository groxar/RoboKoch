#include "TimeDomain.hpp"

TimeDomain::TimeDomain(map<Interval,map<Interval,axiomSet>> intervalRelationMap, map<Interval,Range> intervalRangeMap) : irm(intervalRelationMap), iRangeMap(intervalRangeMap) {
}

TimeDomain::TimeDomain(const TimeDomain& td) : irm(td.irm), iRangeMap(td.iRangeMap) {

}

TimeDomain::~TimeDomain(){
}

bool TimeDomain::areIntervalsInBounds() {
	for(auto iRangeEle : iRangeMap) {
		if(iRangeEle.first.getDuration() < (iRangeEle.second.getMax() - iRangeEle.second.getMin()))
		{
			cout << iRangeEle.second.getMax() << " " <<  iRangeEle.second.getMin()<< endl;
			cout << iRangeEle.first.getId();
			return false;
		}
	}
	return true;
}


