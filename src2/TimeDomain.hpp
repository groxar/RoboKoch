#pragma once
#include "Interval.hpp"
#include "axiomSet.hpp"
#include "Point.hpp"
#include <map>
#include <set>

typedef map<Interval,Point> intervalPOMap; // Interval Pair<PointId,offset>

class TimeDomain {
public:
	TimeDomain(map<Interval,Point> intervalPointMap);
	TimeDomain(const TimeDomain& td);
	~TimeDomain();
	bool addPoint(const Interval& newInterval, const Interval& reference, const axiom ax);

private:
	intervalPOMap ipm;
};
