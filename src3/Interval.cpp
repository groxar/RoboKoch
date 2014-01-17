#include "Interval.hpp"

Interval::Interval(int id, int duration): id(id), duration(duration) {
}

Interval::Interval(const Interval& interval): id(interval.id), duration(interval.duration) {
}

Interval::~Interval() {
}

int Interval::getId() const {
	return id;
}

int Interval::getDuration() const {
	return duration;
}

//only needed for sets of Intervals
bool Interval::operator< (const Interval& rhs) const {
	return this->id < rhs.id;
}
bool Interval::operator== (const Interval& rhs) const {
	return this->id == rhs.id;
}
