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

set<Interval> getIntervals( istream& intervalFile);
map<Interval,map<Interval,axiomSet>> getRelation( istream& relationFile, const set<Interval>& intervalSet);
map<Interval,Range> getTimeWindow( istream& relationFile, const set<Interval>& intervalSet);
axiomSet stringToAxiomSet(string relation);
int stringToTime(string time);
void printIRAM(map<Interval,Range> iram);
