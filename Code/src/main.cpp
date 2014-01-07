#include "Point.hpp"
#include "PointRelation.hpp"
#include "TimeFrame.hpp"
#include <iostream>
#include <vector>

using namespace std;


int main(int argc, const char *argv[]) {
	Point a(0);
	Point b(0);
	Point c(0);
	Point e(0);
	Point lonePoint(0);
	Point z(0);
	PointRelation ab( axiomSet({d,di}) );
	PointRelation ac( axiomSet({f,fi}) );
	PointRelation bc( axiomSet({di,d }) );
	PointRelation be( axiomSet({oi}) ); 
	PointRelation ec( axiomSet({s,si}) );
	PointRelation ea( axiomSet({s,si}) );
	PointRelation a_lonePoint( axiomSet({s,si}) );
	PointRelation pr = ab;

	//simple operation test
	cout <<"Id: "<<  a.getId()<< " Time: "<< a.getTime() << endl;
	cout <<"Id: "<<  b.getId()<< " Time: "<< b.getTime() << endl;
	cout <<"pr: "<<  pr << endl;
	cout <<"!pr: "<< !pr << endl;
	cout <<"pr * !pr: "<< pr * !pr << endl;	
	cout <<"pr / !pr: "<< pr / !pr << endl;	
	cout <<"P(pr,pr): "<< P(pr,pr) << endl;	
	cout <<"P(pr,!pr): "<< P(pr,!pr) << endl;	
	cout <<"P({d},{si}): "<< P( PointRelation(axiomSet({d})),PointRelation(axiomSet({si}))) << endl;	

	//simple timeframe tests
	TimeFrame tf;
	tf.addRelation(a,b,ab);
	tf.addRelation(a,c,ac);
	tf.addRelation(b,c,bc);
	tf.addRelation(b,e,be);
	tf.addRelation(e,c,ec);
	tf.addRelation(e,a,ea);
	tf.addRelation(a,lonePoint,a_lonePoint);
	tf.print();

	cout <<"relation b e: "<< tf.getRelation(b,e)<< endl;
	cout <<"relation e b: "<< tf.getRelation(e,b)<< endl;
	cout <<"relation e z: "<< tf.getRelation(e,z)<< endl;
	cout <<"relation a e: "<< tf.getRelation(a,e)<< endl;
	cout <<"Crelation a e: "<< tf.getCRelation(a,e)<< endl;
	cout <<"axiomSet({}).size() "<< axiomSet({}).size()<< endl;

	cout << "isConsitent lonePoint: " << tf.isConsistent(b,lonePoint) << endl;
	set<Point> ps = tf.getNeighbours(a);
	for( Point p : ps)
	{
		cout << p.getId() << " ";
	}
	cout << endl;
	cout << endl;

	//route finder
	cout << "Route test" << endl;
	vector<vector<Point>> vvp = tf.getRoutes(a,e);
	for (auto route : vvp)
	{
		for(Point p : route)
			cout << p.getId() << " ";
		cout << endl;
	}
	return 0;
}

