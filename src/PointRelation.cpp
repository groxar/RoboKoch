#include "PointRelation.hpp"

PointRelation::PointRelation(axiomSet relation, int duration) : relation(relation), duration(duration) {
}

PointRelation::~PointRelation() {

}

PointRelation& PointRelation::operator= (const PointRelation rhs) {
	relation = rhs.relation;
	duration = rhs.duration;
	return *this;
}

PointRelation PointRelation::operator! () {
	axiomSet inverted;

	axiomSet::iterator end = relation.end();
	for (axiomSet::iterator it = relation.begin(); it != end; ++it) {
		if (*it == 0)
			inverted.insert(eq);
		else if (*it % 2)
			inverted.insert(static_cast<axiom>((*it)+1));
		else
			inverted.insert(static_cast<axiom>((*it)-1));
	}
	return PointRelation(inverted,this->duration);
}

int PointRelation::getDuration() {
	return duration;
}

PointRelation P(const PointRelation lhs, const PointRelation rhs) {
	axiomSet result;

	axiomSet::iterator lend = lhs.relation.end();
	axiomSet::iterator rend = rhs.relation.end();
	for (axiomSet::iterator lit = lhs.relation.begin(); lit != lend; ++lit) {
		for (axiomSet::iterator rit = rhs.relation.begin(); rit != rend; ++rit) {
			result.insert(PTable[*lit][*rit].begin(),PTable[*lit][*rit].end());
		}
	}
	return PointRelation(result);
}

PointRelation operator* (const PointRelation lhs, const PointRelation rhs) {
	axiomSet uni;

	axiomSet::iterator end = lhs.relation.end();
	for (axiomSet::iterator it = lhs.relation.begin(); it != end; ++it) {
		uni.insert(*it);
	}

	end = rhs.relation.end();
	for (axiomSet::iterator it = rhs.relation.begin(); it != end; ++it) {
		uni.insert(*it);
	}

	return PointRelation(uni);//TODO duration calculation
}

PointRelation operator/ (const PointRelation lhs, const PointRelation rhs) {
	axiomSet cut;

	axiomSet::iterator end = lhs.relation.end();
	for (axiomSet::iterator it = lhs.relation.begin(); it != end; ++it) {
		if (rhs.relation.find(*it)!=rhs.relation.end())
			cut.insert(*it);
	}
	return PointRelation(cut);//TODO duration calcutlation
}
ostream& operator << (ostream& os, const PointRelation& rhs) {
	axiomSet::iterator end = rhs.relation.end();
	for (axiomSet::iterator it = rhs.relation.begin(); it != end; ++it) {
		switch (*it) {
		case gt:
			os << "gt ";
			break;
		case st:
			os << "st ";
			break;
		case eq:
			os << "eq ";
			break;
		case m:
			os << "m " ;
			break;
		case mi:
			os << "mi ";
			break;
		case o:
			os << "o " ;
			break;
		case oi:
			os << "oi ";
			break;
		case d:
			os << "d " ;
			break;
		case di:
			os << "di ";
			break;
		case s:
			os << "s " ;
			break;
		case si:
			os << "si ";
			break;
		case f:
			os << "f " ;
			break;
		case fi:
			os << "fi ";
			break;
		}
	}
	return os;
}
