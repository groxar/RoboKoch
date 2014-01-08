#include "Point.hpp"

Point::Point(int time): time(time){
	static int idCounter = 0;
	id = idCounter;
	idCounter++;
}

Point::Point(const Point& point): id(point.id), time(point.time){
}

Point::~Point() {
}

int Point::getId() const{
	return id;
}

int Point::getTime() const{
	return time;
}

//only needed for sets of Points
bool Point::operator <(const Point& rhs) const{
	return this->id < rhs.id;
}
bool Point::operator==(const Point& rhs) const{
	return this->id == rhs.id;
}
