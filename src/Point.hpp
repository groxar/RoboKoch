#pragma once

#include <iostream>

using namespace ::std;

class Point {
  public:
	Point(int time = -1);
	Point(const Point& point);
	~Point();
	int getId() const;
	int getTime() const;
	bool operator< (const Point& rhs) const;
	bool operator== (const Point& rhs) const;
  private:
	int id;
	int time;
};

