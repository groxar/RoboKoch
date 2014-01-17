#include "axiomSet.hpp"

axiomSet operator! (const axiomSet& rhs) {
	axiomSet inverted;

	for (axiom a : rhs) {
		if (a == eq)
			inverted.insert(eq);
		else if (a % 2)
			inverted.insert(static_cast<axiom>((a)+1));
		else
			inverted.insert(static_cast<axiom>((a)-1));
	}
	return inverted;
}


axiomSet P(const axiomSet& lhs, const axiomSet& rhs) {
	axiomSet result;

	for (axiom l : lhs) {
		for (axiom r : rhs) {
			result.insert(PTable[l][r].begin(),PTable[l][r].end());
		}
	}
	return result;
}

axiomSet operator* (const axiomSet& lhs, const axiomSet& rhs) {
	axiomSet uni;

	for (axiom a : lhs) {
		uni.insert(a);
	}

	for (axiom a : rhs) {
		uni.insert(a);
	}

	return uni;
}

axiomSet operator/ (const axiomSet& lhs, const axiomSet& rhs) {
	axiomSet cut;

	for (axiom l : lhs) {
		if (rhs.find(l)!=rhs.end())
			cut.insert(l);
	}
	return cut;
}

ostream& operator << (ostream& os, const axiomSet& rhs) {
	for (axiom a : rhs) {
		os << a << " ";
	}
	return os;
}

ostream& operator << (ostream& os, const axiom rhs) {
	switch (rhs) {
	case gt:
		os << "gt";
		break;
	case st:
		os << "st";
		break;
	case eq:
		os << "eq";
		break;
	case m:
		os << "m" ;
		break;
	case mi:
		os << "mi";
		break;
	case o:
		os << "o" ;
		break;
	case oi:
		os << "oi";
		break;
	case d:
		os << "d" ;
		break;
	case di:
		os << "di";
		break;
	case s:
		os << "s" ;
		break;
	case si:
		os << "si";
		break;
	case f:
		os << "f" ;
		break;
	case fi:
		os << "fi";
		break;
	}
	return os;
}


