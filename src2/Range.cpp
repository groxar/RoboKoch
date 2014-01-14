#include "Range.hpp"

Range::Range() {
}

Range::Range(int value) : min(value), max(value){
}

Range::Range(int min, int max) : min(min), max(max) {
	if(min > max)
		cout << "error at Range Initialisation"<< endl;
}

//min max convolute algorithm to one function
bool Range::defineMin(int value) {

	if (value >= min &&  value <= max) {
		min = value;
		return true;
	} else {
		return false;
	}

}

bool Range::defineMax(int value) {
	if (value <= max && value >= min) {
		max = value;
		return true;
	} else {
		return false;
	}
	
}

Range Range::operator/ (const Range& rhs){ // range that is enclosed range both
	if(this->max >= rhs.min && rhs.min >= this->min && rhs.max >= this->min)
		return Range(rhs.min, this->max);
	else if(rhs.max >= this->min && this->min >= rhs.min && this->max >= rhs.min)
		return Range(this->min, rhs.max);
	else
		return Range(-1);
}

Range Range::operator* (const Range& rhs){ // both ranges combined, if combineable
	return this->max >= rhs.min? Range(this->min, rhs.max): Range(-1);
}

bool Range::operator< (const Range& rhs){
	return this->max < rhs.min;
}

bool Range::operator> (const Range& rhs){
	return this->min > rhs.max;
}

bool Range::operator== (const Range& rhs){
	return this->min == rhs.min && this->max == rhs.max;
}

Range Range::operator+ (int value) {
	return Range(this->min + value, this->max+value);
}

Range Range::operator- (int value) {
	return ((*this)+ (value* -1));
}


int Range::getMin() const{
	return min;
}

int Range::getMax() const{
	return max;
}

ostream& operator << (ostream& os, const Range& rhs) {
	os << "<"<<  rhs.getMin() << "," << rhs.getMax() << ">";
	return os;
}
