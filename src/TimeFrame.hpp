#pragma once

#include "axiomSet.hpp"
#include "Interval.hpp"
#include "TimeDomain.hpp"
#include "intervalRelMap.hpp"
#include <map>
#include <utility>
#include <iostream>//REMOVE BY FINISH UP
#include <set>
#include <future>
#include <vector>

using namespace std;

class TimeFrame {
  public:
	TimeFrame();
	TimeFrame(intervalRelMap irm);
	~TimeFrame();
	void addRelation(const Interval& lhs, const Interval& rhs, const axiomSet& rel);
	bool isConsistent();
	bool isConsistent(const Interval& a, const Interval& b) const;
	TimeFrame getCTimeFrame();
	axiomSet getCRelation(const Interval& a, const Interval& b) const;//RENAME IT
	axiomSet getRelation(const Interval& a, const Interval& b) const;
	vector<vector<Interval>> getRoutes(const Interval& start, const Interval& target) const;
	set<Interval> getIntervals() const;
	set<Interval> getNeighbours(const Interval& target) const;
	bool operator== (const TimeFrame& rhs);
	void print();

	vector<intervalRelMap> splitOnRel(intervalRelMap::const_iterator it) const;
	vector<intervalRelMap> splitOnRel() const;

  private:
	intervalRelMap irm;
	vector<TimeDomain> tdv;

	vector<vector<Interval>> getInvRoutes(const Interval& start, const Interval& target, set<int> closed) const;
};
