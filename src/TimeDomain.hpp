#pragma once
#include "Interval.hpp"
#include "Point.hpp"
#include "axiomSet.hpp"
#include <map>
#include <set>

typedef map<Interval,pair<int,int>> intervalPOMap; // Interval Pair<PointId,offset>

class TimeDomain {
public:
	TimeDomain(set<Interval> intervalSet);
	~TimeDomain();
	bool TimeDomain::addPoint(const Interval& newInterval, const Interval& reference, const axiom ax) {

private:
	intervalPOMap intervalPointMap;
	map<int,Point> idPointMap;
};
