#include "TimeDomain.hpp"

TimeDomain::TimeDomain(map<Interval,map<Interval,axiomSet>> intervalRelationMap, map<Interval,Range> intervalRangeMap) : irm(intervalRelationMap), iram(intervalRangeMap) {
}

TimeDomain::TimeDomain(const TimeDomain& td) : irm(td.irm), iram(td.iram) {

}

TimeDomain::~TimeDomain() {
}

map<Interval,Range> TimeDomain::filterImpossibleRanges() {
	map<Interval,Range> result(iram.begin(),iram.end());
	Range tempRa;
	Interval x(-1);
	Interval y(-1);

	for (auto xm: irm) {
		x = xm.first;
		for (auto ym: xm.second) {
			y = ym.first;
			for (auto ax :ym.second) {
				switch (ax) {
				case eq:
					if (x.getDuration() == y.getDuration()) {
						tempRa = result[x] / result[y];
						result[x]= result[x]/ tempRa;
						result[y]= result[y]/ tempRa;
					} else {
						result[x] = Range(-1);
						result[y] = Range(-1);
					}
					break;
				case st:
					if (result[x].getMax() + x.getDuration() + 1  >= result[y].getMax())
						result[x].defineMax(result[y].getMax()-1);
					if (result[y].getMin() >= result[x].getMin() + x.getDuration() + 1)
						result[y].defineMin(result[x].getMin() +x.getDuration() +1);
					break;
				case gt:
					if (result[y].getMax() + y.getDuration() + 1  >= result[x].getMax())
						result[y].defineMax(result[x].getMax()-1);
					if (result[x].getMin() >= result[y].getMin() + y.getDuration() + 1)
						result[x].defineMin(result[y].getMin() + y.getDuration() +1);
				case d:
					if (result[x].getMin() <= result[y].getMin())
						result[x].defineMin(result[y].getMin()+1);
					if (result[x].getMax() >= result[y].getMax())
						result[x].defineMin(result[y].getMax()-1);
					break;
				case di:
					if (result[y].getMin() <= result[x].getMin())
						result[y].defineMin(result[x].getMin()+1);
					if (result[y].getMax() >= result[x].getMax())
						result[y].defineMin(result[x].getMax()-1);
					break;
				case o:
					if (result[x].getMax() >= result[y].getMax())
						result[x].defineMax(result[y].getMax()-1);
					break;
				case oi:
					if (result[y].getMax() >= result[x].getMax())
						result[y].defineMax(result[x].getMax()-1);
					break;
				case m:
					tempRa = (result[x] + x.getDuration()) / result[y];
					result[x] = tempRa - x.getDuration();
					result[y] = tempRa;
					//cout << result[x] + x.getDuration()<<" "<< result[y]<< " "<< tempRa << endl;
					break;
				case mi:
					tempRa = (result[y] + y.getDuration()) / result[x];
					result[y] = tempRa - y.getDuration();
					result[x] = tempRa;
					break;
				case f:
					tempRa = (result[x] + x.getDuration()) / (result[y] + y.getDuration());
					result[x] = tempRa - x.getDuration();
					result[y] = tempRa - y.getDuration();
					break;
				case fi:
					tempRa = (result[x] + x.getDuration()) / (result[y] + y.getDuration());
					result[x] = tempRa - x.getDuration();
					result[y] = tempRa - y.getDuration();
					break;
				case s:
					tempRa = result[x] / result[y];
					result[x] = tempRa - x.getDuration();
					result[y] = tempRa - y.getDuration();
					break;
				case si:
					tempRa = result[x] / result[y];
					result[x] = tempRa - x.getDuration();
					result[y] = tempRa - y.getDuration();
					break;
				}
			}
		}
	}
	return result;
}

bool TimeDomain::areIntervalsInRange() {
	for (auto ira : iram) {
		if (ira.second.size() < 0)
			return false;
	}
	return true;
}

bool TimeDomain::areRangesValid() {
	for (auto ira :iram) {
		if (ira.second.getMin() < 0)
			return false;
	}
	return true;
}

bool TimeDomain::areRulesValid() {
	bool temp;
	Interval x(-1);
	Interval y(-1);

	for (auto xm: irm) {
		x = xm.first;
		for (auto ym: xm.second) {
			y = ym.first;
			temp = false;
			for (axiom a: ym.second) {
				switch (a) {
				case eq:
					(iram[x]/ iram[y]).getMin() != -1 ?
					temp=true:0;
					break;
				case st:
					iram[x] + x.getDuration() < iram[y] ?
					temp=true:0;
					break;
				case gt:
					iram[x] > iram[y]+ y.getDuration()?
					temp=true:0;
					break;
				case d:
					iram[x] < iram[y] && iram[x] > iram[y] ? // rework from here
					temp=true:0;
					break;
				case di:
					iram[y] < iram[x] && iram[y] > iram[x] ?
					temp=true:0;
					break;
				case o:
					iram[x] < iram[y]
					&& iram[y] < iram[x]
					&& iram[x] < iram[y] ?
					temp=true:0;
					break;
				case oi:
					iram[y] < iram[x]
					&& iram[x] < iram[y]
					&& iram[y] < iram[x] ?
					temp=true:0;
					break;
				case m:
					iram[x] + x.getDuration() == iram[y] ?
					temp=true:0;
					break;
				case mi:
					iram[y] + y.getDuration() == iram[x] ?
					temp=true:0;
					break;
				case f:
					iram[x] + x.getDuration() == iram[y] + y.getDuration() &&
					iram[x] < iram[y]?
					temp=true:0;
					break;
				case fi:
					iram[y] + y.getDuration() == iram[x] + x.getDuration() &&
					iram[y] < iram[x]?
					temp=true:0;
					break;
				case s:
					iram[x] == iram[y] &&
					iram[x] + x.getDuration() < iram[y] + y.getDuration()?
					temp=true:0;
					break;
				case si:
					iram[y] == iram[x] &&
					iram[y] + y.getDuration() < iram[x] + x.getDuration()?
					temp=true:0;
					break;
				}
			}
			if (!temp) {
				//cout << "failed: " <<x.getId() << " -> " << y.getId()<< endl;
				return false;
			}
		}
	}
	return true;
}




bool TimeDomain::isConsistent() {
	if (!areIntervalsInRange())
		return false;
	TimeDomain temp(irm,filterImpossibleRanges());

	if (!temp.areRangesValid())
		return false;

	if (!temp.areRulesValid())
		return false;

	return true;
}

