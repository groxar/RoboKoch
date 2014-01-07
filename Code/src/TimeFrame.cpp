#include "TimeFrame.hpp"

TimeFrame::TimeFrame() {
}

TimeFrame::~TimeFrame() {
}

void TimeFrame::addRelation(const Point& lhs,const Point& rhs,const PointRelation& rel) {
	pointRelList.insert(make_pair(make_pair(lhs,rhs),rel));	
}

void TimeFrame::print() {
	for(auto pr : pointRelList)
	{
		cout << pr.first.first.getId() << " -> " << pr.first.second.getId()<<": "<< pr.second << endl;
	}
}

set<Point> TimeFrame::getNeighbours(const Point& target) const{
	set<Point> result;
	for(auto pr : pointRelList)
	{
		if(pr.first.first.getId() == target.getId())
			result.insert(pr.first.second);
		else if(pr.first.second.getId() == target.getId())
			result.insert(pr.first.first);
	}
	return result;
}


bool TimeFrame::isConsistent(const Point& a, const Point& b) const{
	return getCRelation(a,b).relation.size()!=0;
}

//TODO rework
PointRelation TimeFrame::getCRelation(const Point& a, const Point&b) const{
	auto routes = getRoutes(a,b);
	Point crntPos;
	PointRelation temp(axiomSet({}));
	PointRelation result(axiomSet({eq,st,gt,d,di,o,oi,s,si,f,fi}));

	if(routes.size() == 0)
	{
		return temp;
	}

	for(auto route : routes){
		auto end = route.end();
		auto it = route.begin();
		crntPos = *(it+1);
		result = getRelation(*it,crntPos);
		it+=2;
		for(; it!=end; ++it){
			temp = P(temp,getRelation(crntPos,*it));
			crntPos = *it;
		}
		result = result / temp;	
	}
	return temp;
}

PointRelation TimeFrame::getRelation(const Point& a, const Point&b) const{
	for(auto pr : pointRelList){
		if(pr.first.first.getId() == a.getId() && pr.first.second.getId() == b.getId())
			return pr.second; 
		else if(pr.first.first.getId() == b.getId() && pr.first.second.getId() == a.getId())
			return !(pr.second);
	}
	return axiomSet({});
}

vector<vector<Point>> TimeFrame::getRoutes(const Point& start, const Point& target) const{
	return getInvRoutes(target,start,set<int>());
}


vector<vector<Point>> TimeFrame::getInvRoutes(const Point& current, const Point& target, set<int> closed) const{
	vector<future<vector<vector<Point>>>> futureRoutes;
	vector<vector<Point>> result;
	vector<Point> route;
	set<Point> n = this->getNeighbours(current);	
	closed.insert(current.getId());

	if (current.getId() == target.getId()){
		route.push_back(current);
		result.push_back(route);
		return result; 
	}

	for (const Point p : n){
		if(closed.find(p.getId()) == closed.end())
			futureRoutes.push_back(std::async(&TimeFrame::getInvRoutes,this,p,target,set<int>(closed)));
	}

	if (futureRoutes.size() == 0)
		return result; //empty vector
	else {
		auto end = futureRoutes.end();
		for (auto it = futureRoutes.begin(); it!= end; ++it) {
			auto routes = it->get();
			for (auto route : routes) {
				if (route.size() != 0){
					route.push_back(current);
					result.push_back(route);
				}
			}
		}
	}
	return result;
}
