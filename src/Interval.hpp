#pragma once

#include <iostream>

using namespace ::std;

class Interval {
  public:
	Interval(unsigned int duration = 0);
	Interval(const Interval& interval);
	~Interval();
	unsigned int getId() const;
	unsigned int getDuration() const;
	bool operator< (const Interval& rhs) const;
	bool operator== (const Interval& rhs) const;
  private:
	unsigned int id;
	unsigned int duration;
	struct time{
		int start;
		int end;
	};
};

