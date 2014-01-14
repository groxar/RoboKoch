#pragma once

#include <iostream>
#include "Range.hpp"

using namespace ::std;

class Interval {
  public:
	Interval(int id, int duration = 0);
	Interval(const Interval& interval);
	~Interval();
	int getId() const;
	int getDuration() const;
	bool operator< (const Interval& rhs) const;
	bool operator== (const Interval& rhs) const;
  private:
	int id;
	int duration;
};

