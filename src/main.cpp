#include "Interval.hpp"
#include "axiomSet.hpp"
#include "TimeFrame.hpp"
#include <iostream>
#include <vector>

using namespace std;


int main() {
	Interval a;
	Interval b;
	Interval c;
	Interval e;
	Interval loneInterval;
	Interval z;
	axiomSet ab({d,di});
	axiomSet ac({f,fi});
	axiomSet bc({di,d});
	axiomSet be({oi});
	axiomSet ec({s,si});
	axiomSet ea({s,si});
	axiomSet a_loneInterval({s,si});
	axiomSet emptyRel;
	axiomSet pr({oi,eq});

	//interval test
	cout <<"a == b "<< (a == b) << endl;
	cout <<"a == a "<< (a == a) << endl;

	//axiomSet test
	cout <<"axiomSet({}).size() "<< axiomSet({}).size()<< endl;
	cout <<"eq axiomSet "<< (axiomSet({di,si}) == axiomSet({di,si})) << endl;
	cout <<"!eq axiomSet "<< (axiomSet({di,s}) == axiomSet({di,si})) << endl;
	cout <<"!eq axiomSet "<< (axiomSet({di,si,fi}) == axiomSet({di,si})) << endl;

	//relation test
	cout <<"Id: "<<  a.getId()<< " Duration: "<< a.getDuration() << endl;
	cout <<"Id: "<<  b.getId()<< " Duration: "<< b.getDuration() << endl;
	cout <<"pr: "<<  pr << endl;
	cout <<"!pr: "<< !pr << endl;
	cout <<"pr * !pr: "<< pr * !pr << endl;
	cout <<"pr / !pr: "<< pr / !pr << endl;
	cout <<"P(pr,pr): "<< P(pr,pr) << endl;
	cout <<"P(pr,!pr): "<< P(pr,!pr) << endl;
	cout <<"P({d},{si}): "<< P( axiomSet({d}),axiomSet({si})) << endl;
	cout <<"empty relation size     " << emptyRel.size()<<endl;

	//timeframe test
	//inconsistent timeframe test
	TimeFrame tf;
	tf.addRelation(a,b,ab);
	tf.addRelation(a,b,ab);//should throw error
	tf.addRelation(a,c,ac);
	tf.addRelation(b,c,bc);
	tf.addRelation(b,e,be);
	tf.addRelation(e,c,ec);
	tf.addRelation(e,a,ea);
	tf.addRelation(a,loneInterval,a_loneInterval);
	tf.print();
	cout <<"relation b e: " << tf.getRelation(b,e)<< endl;
	cout <<"relation e b: " << tf.getRelation(e,b)<< endl;
	cout <<"relation e z: " << tf.getRelation(e,z)<< endl;
	cout <<"relation a e: " << tf.getRelation(a,e)<< endl;
	cout <<"Crelation a e: "<< tf.getCRelation(a,e)<< endl;
	cout << endl;
	//consistent timeframe test
	TimeFrame ctf;
	ctf.addRelation(a,b,ab);
	ctf.addRelation(a,c,ac);
	ctf.addRelation(b,e,be);
	ctf.print();
	cout << "relation a e: " << ctf.getRelation(a,e)<< endl;
	cout << "Crelation a e: "<< ctf.getCRelation(a,e)<< endl;
	cout << "inconsistent TimeFrame"<<endl;
	tf.getCTimeFrame().print();
	cout << "consistent TimeFrame"<<endl;
	ctf.getCTimeFrame().print();
	cout << endl;
	//equal timeframe
	cout << "tf == tf  " <<  (tf == tf) << endl;
	cout << "ctf == tf " << (ctf == tf) << endl;


	cout << "isConsitent loneInterval: " << tf.isConsistent(b,loneInterval) << endl;
	set<Interval> ps = tf.getNeighbours(a);
	cout << "getNeighbours(a) ";
	for ( Interval p : ps) {
		cout << p.getId() << " ";
	}
	cout << endl;
	cout << endl;

	//route finder
	cout << "Route test" << endl;
	vector<vector<Interval>> vvp = tf.getRoutes(a,e);
	for (auto route : vvp) {
		for (Interval p : route)
			cout << p.getId() << " ";
		cout << endl;
	}
	return 0;
}

