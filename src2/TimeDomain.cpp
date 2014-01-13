#include "TimeDomain.hpp"

TimeDomain::TimeDomain(map<Interval,Point> intervalPointMap) : ipm(intervalPointMap) {
}

TimeDomain::TimeDomain(const TimeDomain& td) : ipm(td.ipm) {

}

TimeDomain::~TimeDomain(){
	//free the Point*
}

bool TimeDomain::addPoint(const Interval& newInterval ,const Interval& reference,const axiom ax) {
	Point temp;

	return false;
}

