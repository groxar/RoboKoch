#include "TimeFrame.hpp"

TimeFrame::TimeFrame() {
}

TimeFrame::~TimeFrame() {
}

void TimeFrame::addRelation(const Point& lhs,const Point& rhs,const PointRelation& rel) {
	if (this->getRelation(lhs,rhs).relation.size()==0) {
		pointRelList.insert(make_pair(make_pair(lhs,rhs),rel));
	} else {
		//throw
		cout<< "the points already have a relation"<<endl;
	}
}

void TimeFrame::print() {
	for (auto pr : pointRelList) {
		cout << pr.first.first.getId() << " -> " << pr.first.second.getId()<<": "<< pr.second << endl;
	}
}

set<Point> TimeFrame::getNeighbours(const Point& target) const {
	set<Point> result;
	for (auto pr : pointRelList) {
		if (pr.first.first == target)
			result.insert(pr.first.second);
		else if (pr.first.second == target)
			result.insert(pr.first.first);
	}
	return result;
}


bool TimeFrame::isConsistent(const Point& a, const Point& b) const {
	return getCRelation(a,b).relation.size()!=0;
}

TimeFrame TimeFrame::getCTimeFrame() {
	TimeFrame result;
	PointRelation consistentRel;

	for (auto pointRel : this->pointRelList) {
		consistentRel = this->getCRelation(pointRel.first.first,pointRel.first.second);
		if (consistentRel.relation.size()==0) {
			cout << "throw inconsistency found"<< endl;
			return TimeFrame();
		}
		result.addRelation(pointRel.first.first,pointRel.first.second,consistentRel);
	}
	if ((*this) == result)
		return result;

	return result.getCTimeFrame();
}

PointRelation TimeFrame::getCRelation(const Point& a, const Point&b) const {
	auto routes = getRoutes(a,b);
	Point crntPos;
	PointRelation temp;
	PointRelation result(axiomSet({eq,st,gt,d,di,o,oi,s,si,f,fi}));

	if (routes.size() == 0) {
		return temp;//empty Relationset
	}

	for (auto route : routes) {
		auto end = route.end();
		auto it = route.begin();
		crntPos = *(it+1);
		temp = getRelation(*it,crntPos);
		it+=2;
		for (; it<end; ++it) {
			temp = P(temp,getRelation(crntPos,*it));
			crntPos = *it;
		}
		result = result / temp;
	}
	return result;
}

PointRelation TimeFrame::getRelation(const Point& a, const Point&b) const {
	for (auto pr : pointRelList) {
		if (pr.first.first == a && pr.first.second == b)
			return pr.second;
		else if (pr.first.first == b && pr.first.second == a)
			return !(pr.second);
	}
	return PointRelation(axiomSet({}));
}

vector<vector<Point>> TimeFrame::getRoutes(const Point& start, const Point& target) const {
	return getInvRoutes(target,start,set<int>());
}


vector<vector<Point>> TimeFrame::getInvRoutes(const Point& current, const Point& target, set<int> closed) const {
	vector<future<vector<vector<Point>>>> futureRoutes;
	vector<vector<Point>> result;
	vector<Point> route;
	set<Point> n = this->getNeighbours(current);
	closed.insert(current.getId());

	if (current == target) {
		route.push_back(current);
		result.push_back(route);
		return result;
	}

	for (const Point p : n) {
		if (closed.find(p.getId()) == closed.end())
			futureRoutes.push_back(std::async(&TimeFrame::getInvRoutes,this,p,target,set<int>(closed)));
	}

	if (futureRoutes.size() == 0)
		return result; //empty vector
	else {
		auto end = futureRoutes.end();
		for (auto it = futureRoutes.begin(); it!= end; ++it) {
			auto routes = it->get();
			for (auto route : routes) {
				if (route.size() != 0) {
					route.push_back(current);
					result.push_back(route);
				}
			}
		}
	}
	return result;
}

bool TimeFrame::operator== (const TimeFrame& rhs) {
	if ((this->pointRelList.size() != rhs.pointRelList.size()))
		return false;

	PointRelation temp;
	for (auto pointRel: pointRelList) {
		temp = rhs.getRelation(pointRel.first.first,pointRel.first.second);
		if (!((axiomSet)pointRel.second.relation == temp.relation))
			return false;
	}
	return true;
}
