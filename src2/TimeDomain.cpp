#include "TimeDomain.hpp"

TimeDomain::TimeDomain(map<Interval,map<Interval,axiomSet>> intervalRelationMap, map<Interval,pair<Range,Range>> intervalRangeMap) : irm(intervalRelationMap), iram(intervalRangeMap) {
}

TimeDomain::TimeDomain(const TimeDomain& td) : irm(td.irm), iram(td.iram) {

}

TimeDomain::~TimeDomain(){
}

bool TimeDomain::areIntervalsInRange() {
	for(auto iRangeEle : iram) {
		if(iRangeEle.first.getDuration() > (iRangeEle.second.first.getMax() - iRangeEle.second.first.getMin()))
			return false;
	}
	return true;
}

#define tempAssign temp=true:temp=false
bool TimeDomain::testRules(){
	bool temp;
	Interval x(-1);
	Interval y(-1);

	for(auto xm: irm)
	{
		x = xm.first;
		for(auto ym: xm.second)
		{
			y = ym.first;
			for(axiom a: ym.second)
			{
				switch(a)
				{
					case eq:  (iram[x].first / iram[y].first).getMin() != -1 ?
							  	tempAssign;
							 break;
					case st: iram[x].second < iram[y].first ?
							 	tempAssign;
							 break;
					case gt: iram[x].first > iram[y].first ?
								tempAssign;
							 break;
					case d: iram[x].first < iram[y].first && iram[x].second > iram[y].second ?
								tempAssign;
							break;
					case di: iram[y].first < iram[x].first && iram[y].second > iram[x].second ?
							 	tempAssign;
							 break;
					case o: iram[x].first < iram[y].first 
							&& iram[y].first < iram[x].second 
							&& iram[x].second < iram[y].second ?
								tempAssign;
							break;
					case oi: iram[y].first < iram[x].first 
							&& iram[x].first < iram[y].second 
							&& iram[y].second < iram[x].second ?
								tempAssign;
							break;
					case m: iram[x].second == iram[y].first ?
								tempAssign;
							break;
					case mi: iram[y].second == iram[x].first ?
								tempAssign;
							break;
					case f:
					case fi:
					case s:
					case si:
							break;
				}
			}
			if (!temp)
			{
				cout << "failed: " <<x.getId() << " -> " << y.getId()<< endl;
				return false;
			}
		}
	}
	return true;
}


