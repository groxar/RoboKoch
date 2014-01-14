#pragma once
#include "CSVIterator.hpp"
#include "Interval.hpp"
#include "axiomSet.hpp"
#include "Range.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <stdexcept>

using namespace std;

set<Interval> getIntervals(const string& intervalFilePath);
map<Interval,map<Interval,axiomSet>> getRelation(const string& relationFilePath, const set<Interval>& intervalSet);
map<Interval,pair<Range,Range>> getTimeWindow(const string& relationFilePath, const set<Interval>& intervalSet);
axiomSet stringToAxiomSet(string relation);
int stringToTime(string time);
