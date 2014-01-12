#pragma once

#include <iostream>
#include "Point.hpp"

using namespace ::std;

class Interval {
  public:
	Interval(int duration = 0);
	Interval(const Interval& interval);
	~Interval();
	unsigned int getId() const;
	int getDuration() const;
	bool operator< (const Interval& rhs) const;
	bool operator== (const Interval& rhs) const;
  private:
	unsigned int id;
	int duration;
};

