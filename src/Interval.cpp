#include "Interval.hpp"

Interval::Interval(int duration): duration(duration) {
	static int idCounter = 0;
	id = idCounter;
	idCounter++;
}

Interval::Interval(const Interval& point): id(point.id), duration(point.duration) {
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
bool Interval::operator <(const Interval& rhs) const {
	return this->id < rhs.id;
}
bool Interval::operator==(const Interval& rhs) const {
	return this->id == rhs.id;
}
