#pragma once
#include "Interval.hpp"
#include "axiomSet.hpp"
#include "Range.hpp"
#include <map>
#include <set>

#include <iostream>


class TimeDomain {
public:
	TimeDomain(map<Interval,map<Interval,axiomSet>> intervalRelationMap, map<Interval,Range> intervalRangeMap);
	TimeDomain(const TimeDomain& td);
	~TimeDomain();
	bool areIntervalsInRange();
	bool areRangesValid();
	bool testRules();
	
	map<Interval,Range> filterImpossibleRanges();
	map<Interval,Range> iram;

private:
	map<Interval,map<Interval,axiomSet>> irm;

};
