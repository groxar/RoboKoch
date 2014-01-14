#pragma once

class Range {
  public:
	Range();
	Range(int value);
	Range(int min, int max);
	bool defineMin(int value);
	bool defineMax(int value);
	Range operator/ (const Range& rhs);
	Range operator* (const Range& rhs);
	bool operator< (const Range& rhs);
	bool operator> (const Range& rhs);
	bool operator== (const Range& rhs);
	int getMin();
	int getMax();

  private:
	int min;
	int max;
};
