#pragma once
#include "Interval.hpp"
#include "axiomSet.hpp"
#include "Range.hpp"
#include <map>
#include <set>

#include <iostream>


class TimeDomain {
public:
	TimeDomain(map<Interval,map<Interval,axiomSet>> intervalRelationMap, map<Interval,pair<Range,Range>> intervalRangeMap);
	TimeDomain(const TimeDomain& td);
	~TimeDomain();
	bool areIntervalsInRange();
	bool testRules();

private:
	map<Interval,map<Interval,axiomSet>> irm;
	map<Interval,pair<Range,Range>> iram;
};
