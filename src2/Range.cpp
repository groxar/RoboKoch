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

int Range::getMin() {
	return min;
}

int Range::getMax() {
	return max;
}
