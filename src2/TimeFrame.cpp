#include "TimeFrame.hpp"

TimeFrame::TimeFrame() {
}

TimeFrame::TimeFrame(intervalRelMap irm) : irm(irm) {
}

TimeFrame::~TimeFrame() {
}

void TimeFrame::print() {
	for (auto x : irm) {
		for(auto y : x.second)
			cout << x.first.getId() << "->" << y.first.getID() << " : " << y.second();
	}
}

set<Interval> TimeFrame::getNeighbours(const Interval& target) const {
	set<Interval> result;
	for (auto x : irm) {
		if (x.first == target)
			result.insert(x.second.first.begin(),x.second.first.end());// does it WÖRK?
	}
	return result;
}


bool TimeFrame::isConsistent(const Interval& a, const Interval& b) const {
	return getCRelation(a,b).size()!=0;
}

TimeFrame TimeFrame::getCTimeFrame() {
	TimeFrame result;
	axiomSet consistentRel;

	for (auto intervalRel : this->irm) {
		consistentRel = this->getCRelation(intervalRel.first.first,intervalRel.first.second);
		if (consistentRel.size()==0) {
			cout << "throw inconsistency found"<< endl;
			return TimeFrame();
		}
		result.addRelation(intervalRel.first.first,intervalRel.first.second,consistentRel);
	}
	if ((*this) == result)
		return result;//no change was detected -> final result

	return result.getCTimeFrame();
}

axiomSet TimeFrame::getCRelation(const Interval& a, const Interval&b) const {
	auto routes = getRoutes(a,b);
	Interval crntPos;
	axiomSet temp;
	axiomSet result(axiomSet({eq,st,gt,d,di,o,oi,s,si,f,fi}));

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

axiomSet TimeFrame::getRelation(const Interval& a, const Interval&b) const {
	for (auto pr : irm) {
		if (pr.first.first == a && pr.first.second == b)
			return pr.second;
		else if (pr.first.first == b && pr.first.second == a)
			return !(pr.second);
	}
	return axiomSet({});
}

vector<vector<Interval>> TimeFrame::getRoutes(const Interval& start, const Interval& target) const {
	return getInvRoutes(target,start,set<int>());
}

vector<vector<Interval>> TimeFrame::getInvRoutes(const Interval& current, const Interval& target, set<int> closed) const {
	vector<future<vector<vector<Interval>>>> futureRoutes;
	vector<vector<Interval>> result;
	vector<Interval> route;
	closed.insert(current.getId());

	if (current == target) {
		route.push_back(current);
		result.push_back(route);
		return result;
	}

	set<Interval> n = this->getNeighbours(current);
	for (const Interval p : n) {
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

set<Interval> TimeFrame::getIntervals() const {
	return intervalSet;
}

bool isConsitent() {
	return false;
}

bool TimeFrame::operator== (const TimeFrame& rhs) {
	if ((this->irm.size() != rhs.irm.size()))
		return false;

	axiomSet temp;
	for (auto intervalRel: irm) {
		temp = rhs.getRelation(intervalRel.first.first,intervalRel.first.second);
		if (!((axiomSet)intervalRel.second == temp))
			return false;
	}
	return true;
}
