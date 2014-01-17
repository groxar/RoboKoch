#pragma once

#include "axiomSet.hpp"
#include "Interval.hpp"
#include "TimeDomain.hpp"
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
	TimeFrame(map<Interval,map<Interval,axiomSet>> intervalRelationMap, set<Interval> intervalMap);
	~TimeFrame();
	void addRelation(const Interval& x, const Interval& y, const axiomSet& ax);
	bool isConsistent() const;
	TimeFrame getCTimeFrame() const;
	axiomSet getCRelation(const Interval& a, const Interval& b) const;
	axiomSet getRelation(const Interval& a, const Interval& b) const;
	vector<vector<Interval>> getRoutes(const Interval& start, const Interval& target) const;
	set<Interval> getIntervals() const;
	set<Interval> getNeighbours(const Interval& target) const;
	bool operator== (const TimeFrame& rhs) const;
	void print();

	vector<map<Interval,map<Interval,axiom>>> splitRelation() const;
	vector<map<Interval,axiom>> splitInnerRelation(map<Interval,axiomSet> iaxsm) const;
	vector<axiom> splitAxiom(const axiomSet& axs) const;

  private:
	map<Interval,map<Interval,axiomSet>> irm;
	set<Interval> im;

	vector<TimeDomain> tdv;

	vector<vector<Interval>> getInvRoutes(const Interval& start, const Interval& target, set<int> closed) const;
};
