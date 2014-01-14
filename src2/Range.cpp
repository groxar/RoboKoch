#include "Range.hpp"

Range::Range() {
}

Range::Range(int value) : min(value), max(value){
}

Range::Range(int min, int max) : min(min), max(max) {
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

Range Range::operator/ (const Range& rhs){
	return this->max >= rhs.min? Range(rhs.min, this->max) : Range(-1);
}

Range Range::operator* (const Range& rhs){
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


int Range::getMin() {
	return min;
}

int Range::getMax() {
	return max;
}
