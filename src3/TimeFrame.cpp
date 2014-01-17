#include "TimeFrame.hpp"

TimeFrame::TimeFrame() {
}

TimeFrame::TimeFrame(map<Interval,map<Interval,axiomSet>> intervalRelationMap, set<Interval> intervalMap) : irm(intervalRelationMap), im(intervalMap) {
}

TimeFrame::~TimeFrame() {
}

void TimeFrame::addRelation(const Interval& x, const Interval& y, const axiomSet& ax){
	irm[x][y] = ax;
}

void TimeFrame::print() {
	for (auto x : irm) {
		for(auto y : x.second)
			cout << x.first.getId() << "->" << y.first.getId() << " : " << y.second<< endl;
	}
}

set<Interval> TimeFrame::getNeighbours(const Interval& target) const {
	set<Interval> result;
	Interval x(-1);
	Interval y(-1);
	for (auto xm : irm) {
		x = xm.first;
		for(auto ym : xm.second){
			y = ym.first;

			if (x == target)
				result.insert(y);
			if (y == target)
				result.insert(x);
		}
	}
	return result;
}


bool TimeFrame::isConsistent() const {

	Interval x(-1);
	Interval y(-1);
	for (auto xm : irm) {
		x = xm.first;
		for(auto ym : xm.second){
			y = ym.first;

			if (getCRelation(x,y)==axiomSet({})) // inkonsistent Relation found
				return false;
		}
	}


	return true;
}

TimeFrame TimeFrame::getCTimeFrame() const{
	TimeFrame result;
	axiomSet consistentRel;
	Interval x(-1);
	Interval y(-1);
	for (auto xm : irm) {
		x = xm.first;
		for(auto ym : xm.second){
			y = ym.first;

			consistentRel = this->getCRelation(x,y);
			if (consistentRel.size()==0) {
				cout << x.getId() << " " << y.getId() << endl; 
				cout << "throw inconsistency found"<< endl;
				return TimeFrame();
			}
			result.addRelation(x, y, consistentRel);
		}
	}
	if ((*this) == result)
		return result;//no change was detected -> final result

	return result.getCTimeFrame();
}

axiomSet TimeFrame::getCRelation(const Interval& a, const Interval&b) const {
	Interval crntPos(-1);
	axiomSet temp;
	axiomSet result(axiomSet({eq,st,gt,d,di,o,oi,s,si,f,fi,m,mi}));
	
	auto routes = getRoutes(a,b);
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
	Interval x(-1);
	Interval y(-1);
	for (auto xm : irm) {
		x = xm.first;
		for(auto ym : xm.second){
			y = ym.first;

			if (x == a && y == b)
				return ym.second;
			else if (x == b && y == a)
				return !(ym.second);
		}
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
	return im;
}

bool TimeFrame::operator== (const TimeFrame& rhs) const{
	if ((this->irm.size() != rhs.irm.size()))
		return false;
	Interval x(-1);
	Interval y(-1);
	for (auto xm : irm) {
		x = xm.first;
		if(xm.second.size() != (*rhs.irm.find(x)).second.size())
			return false;
		for(auto ym : xm.second){
			y = ym.first;

			if(!(this->getRelation(x,y) == rhs.getRelation(x,y)))
				return false;
		}
	}
	return true;
}


