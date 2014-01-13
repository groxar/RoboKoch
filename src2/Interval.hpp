#pragma once

#include <iostream>
#include "Point.hpp"

using namespace ::std;

class Interval {
  public:
	Interval(int duration = 0);
	Interval(const Interval& interval);
	~Interval();
	int getDuration() const;
  private:
	int duration;
};

