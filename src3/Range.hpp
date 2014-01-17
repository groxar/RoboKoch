#pragma once

#include <iostream>

using namespace std;

class Range {
  public:
	Range();
	Range(int value);
	Range(int min, int max);
	bool defineMin(int value);
	bool defineMax(int value);
	Range operator/ (const Range& rhs) const;
	Range operator* (const Range& rhs);
	bool operator< (const Range& rhs);
	bool operator> (const Range& rhs);
	bool operator== (const Range& rhs);
	Range& operator= (const Range& rhs);
	Range operator+ (int value);
	Range operator- (int value);
	int getMin() const;
	int getMax() const;
	int size() const;

  private:
	int min;
	int max;
};
ostream& operator << (ostream& os, const Range& rhs);
