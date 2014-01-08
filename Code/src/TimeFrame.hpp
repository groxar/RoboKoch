#pragma once

#include "PointRelation.hpp"
#include "Point.hpp"
#include <map>
#include <utility>
#include <iostream>//REMOVE TO FINISH UP
#include <set>
#include <future>
#include <vector>

using namespace std;

struct pointPair_compare {
	bool operator() (const pair<Point,Point> lhs, const pair<Point,Point> rhs) const{
		return lhs.first.getId() < rhs.first.getId(); 
	}
};

class TimeFrame{
	public:
		TimeFrame();
		~TimeFrame();
		void addRelation(const Point& lhs, const Point& rhs, const PointRelation& rel);
		bool isConsistent();
		bool isConsistent(const Point& a, const Point& b) const;
        TimeFrame getCTimeFrame();
		PointRelation getCRelation(const Point& a, const Point& b) const;//RENAME IT
		PointRelation getRelation(const Point& a, const Point& b) const;
		vector<vector<Point>> getRoutes(const Point& start, const Point& target) const;
		set<Point> getNeighbours(const Point& target) const;
        bool operator ==(const TimeFrame& rhs);
		void print();

	private:
		multimap<pair<Point,Point>,PointRelation,pointPair_compare> pointRelList;

		vector<vector<Point>> getInvRoutes(const Point& start, const Point& target, set<int> closed) const;
};

