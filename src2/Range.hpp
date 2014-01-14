#pragma once

class Range {
  public:
	Range();
	Range(int value);
	Range(int min, int max);
	bool defineMin(int value);
	bool defineMax(int value);
	int getMin();
	int getMax();

  private:
	int min;
	int max;
};
