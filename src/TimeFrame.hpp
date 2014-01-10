#pragma once

#include "axiomSet.hpp"
#include "Interval.hpp"
#include <map>
#include <utility>
#include <iostream>//REMOVE BY FINISH UP
#include <set>
#include <future>
#include <vector>

using namespace std;

struct intervalPair_compare {
	bool operator() (const pair<Interval,Interval> lhs, const pair<Interval,Interval> rhs) const {
		return lhs.first.getId() < rhs.first.getId();
	}
};

class TimeFrame {
  public:
	TimeFrame();
	~TimeFrame();
	void addRelation(const Interval& lhs, const Interval& rhs, const axiomSet& rel);
	bool isConsistent();
	bool isConsistent(const Interval& a, const Interval& b) const;
	TimeFrame getCTimeFrame();
	axiomSet getCRelation(const Interval& a, const Interval& b) const;//RENAME IT
	axiomSet getRelation(const Interval& a, const Interval& b) const;
	vector<vector<Interval>> getRoutes(const Interval& start, const Interval& target) const;
	set<Interval> getNeighbours(const Interval& target) const;
	bool operator== (const TimeFrame& rhs);
	void print();

  private:
	multimap<pair<Interval,Interval>,axiomSet,intervalPair_compare> intervalRelList;

	vector<vector<Interval>> getInvRoutes(const Interval& start, const Interval& target, set<int> closed) const;
};

