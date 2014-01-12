#pragma once 

class Point {
	public:
		Point();
		Point(int pointInTime);
		bool defineMin(int pointInTime);
		bool defineMax(int pointInTime);

	private:
		struct{
			bool defined;
			int time;	
		} min;
		struct {
			bool defined;
			int time;	
		} max;
};
