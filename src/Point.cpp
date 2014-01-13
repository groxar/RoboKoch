#include "Point.hpp"

Point::Point() {
	min.defined = false;
	max.defined = false;
}

Point::Point(int pointInTime) {
	min.defined = true;
	max.defined = true;
	min.time = pointInTime;
	max.time = pointInTime;
}

//min max convolute algorithm to one function
bool Point::defineMin(int pointInTime) {
	if (min.defined == false) {
		min.defined = true;
		min.time = pointInTime;
		return true;
	} else {
		if (pointInTime >= min.time && (!max.defined || pointInTime <= max.time)) {
			min.time = pointInTime;
			return true;
		} else {
			return false;
		}
	}
}

bool Point::defineMax(int pointInTime) {
	if (min.defined == false) {
		max.defined = true;
		max.time = pointInTime;
		return true;
	} else {
		if (pointInTime <= max.time && (!min.defined || pointInTime >= min.time)) {
			max.time = pointInTime;
			return true;
		} else {
			return false;
		}
	}
}

