#include "axiomSet.hpp"

axiomSet operator! (const axiomSet& rhs) {
	axiomSet inverted;

	axiomSet::iterator end = rhs.end();
	for (axiomSet::iterator it = rhs.begin(); it != end; ++it) {
		if (*it == eq)
			inverted.insert(eq);
		else if (*it % 2)
			inverted.insert(static_cast<axiom>((*it)+1));
		else
			inverted.insert(static_cast<axiom>((*it)-1));
	}
	return inverted;
}


axiomSet P(const axiomSet& lhs, const axiomSet& rhs) {
	axiomSet result;

	axiomSet::iterator lend = lhs.end();
	axiomSet::iterator rend = rhs.end();
	for (axiomSet::iterator lit = lhs.begin(); lit != lend; ++lit) {
		for (axiomSet::iterator rit = rhs.begin(); rit != rend; ++rit) {
			result.insert(PTable[*lit][*rit].begin(),PTable[*lit][*rit].end());
		}
	}
	return result;
}

axiomSet operator* (const axiomSet& lhs, const axiomSet& rhs) {
	axiomSet uni;

	axiomSet::iterator end = lhs.end();
	for (axiomSet::iterator it = lhs.begin(); it != end; ++it) {
		uni.insert(*it);
	}

	end = rhs.end();
	for (axiomSet::iterator it = rhs.begin(); it != end; ++it) {
		uni.insert(*it);
	}

	return uni;
}

axiomSet operator/ (const axiomSet& lhs, const axiomSet& rhs) {
	axiomSet cut;

	axiomSet::iterator end = lhs.end();
	for (axiomSet::iterator it = lhs.begin(); it != end; ++it) {
		if (rhs.find(*it)!=rhs.end())
			cut.insert(*it);
	}
	return cut;
}
ostream& operator << (ostream& os, const axiomSet& rhs) {
	axiomSet::iterator end = rhs.end();
	for (axiomSet::iterator it = rhs.begin(); it != end; ++it) {
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
