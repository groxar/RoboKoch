#include "Interval.hpp"

Interval::Interval(int duration): duration(duration) {
}

Interval::Interval(const Interval& interval): duration(interval.duration) {
}

Interval::~Interval() {
}


int Interval::getDuration() const {
	return duration;
}
