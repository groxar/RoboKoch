#include "TimeDomain.hpp"

TimeDomain::TimeDomain(set<Interval> intervalSet){
	for(Interval i: intervalSet) {
		intervalPointMap.insert(make_pair(i,make_pair(Point(),0)));
	}
}

TimeDomain::TimeDomain(const TimeDomain& td) : intervalPointMap(td.intervalPointMap){

}

TimeDomain::~TimeDomain(){
	//free the Point*
}

bool TimeDomain::addPoint(const Interval& newInterval ,const Interval& reference,const axiom ax) {
	Point temp;
	switch(ax){
		case eq: intervalPointMap[newInterval] = intervalPointMap[reference];
				 break;
		case st: intervalPointMap[newInterval] = intervalPointMap[reference];
				 intervalPointMap[newInterval].first -= (newInterval.getDuration()+1);
				 break;  
		
	}

	return false;
}

