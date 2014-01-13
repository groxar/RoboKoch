#pragma once

struct intervalPair_compare {
	bool operator() (const pair<Interval,Interval> lhs, const pair<Interval,Interval> rhs) const {
		return lhs.first< rhs.first;
	}
};

typedef multimap<pair<Interval,Interval>,axiomSet,intervalPair_compare> intervalRelMap;


