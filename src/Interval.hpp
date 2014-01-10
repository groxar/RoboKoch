#pragma once

#include <iostream>

using namespace ::std;

class Interval {
  public:
	Interval(int duration = -1);
	Interval(const Interval& point);
	~Interval();
	int getId() const;
	int getDuration() const;
	bool operator< (const Interval& rhs) const;
	bool operator== (const Interval& rhs) const;
  private:
	int id;
	int duration;
};

