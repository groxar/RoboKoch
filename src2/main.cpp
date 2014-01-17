#include "Interval.hpp"
#include "axiomSet.hpp"
#include "Util.hpp"
#include "TimeFrame.hpp"
#include "TimeDomain.hpp"
#include "Range.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main(int argc, char** argv) {

	if(argc != 4){
		cout << "Dateipfade zu den foldenden Dateien werden benötigt: \nAblauf\nBeziehung\nDurchfuerung" << endl;
		return EXIT_FAILURE;
	}

	ifstream intervalFile(argv[1]);
	ifstream relationFile(argv[2]);
	ifstream timeFile(argv[3]);

	if(!intervalFile.good()){
		cout << "Der Dateipfad zu Interval ist ungültig" << endl;
		return EXIT_FAILURE;
	}
	if(!relationFile.good()){
		cout << "Der Dateipfad zu Beziehung ist ungültig" << endl;
		return EXIT_FAILURE;
	}
	if(!timeFile.good()){
		cout << "Der Dateipfad zu Durchfuerung ist ungültig" << endl;
		return EXIT_FAILURE;
	}


	set<Interval> im = getIntervals(intervalFile);
	map<Interval,map<Interval,axiomSet>> irm = getRelation(relationFile,im);
	map<Interval,Range> itime = getTimeWindow(timeFile,im);

	TimeFrame tf(irm, im);
	
	if(!tf.isConsistent()){
		cout << "Die Beziehungen sind inkonsitent"<< endl;
		return EXIT_FAILURE;
	}
	cout << "Die Beziehungen sind konsitent"<< endl;


/* 
	tf.print();
	cout << tf.getRelation(Interval(2),Interval(3)) << endl;
	cout << tf.getRelation(Interval(3),Interval(2)) << endl;
	cout <<tf.getCRelation(Interval(2),Interval(3)) << endl;
	vector<vector<Interval>> vvi =tf.getRoutes(Interval(2),Interval(3));
	auto sn = tf.getNeighbours(Interval(2));
	cout << "getNeighbours: ";
	for(auto n: sn)
	{
		cout << n.getId() << " ";
	}
	cout << endl;
	cout << "route count: "<< vvi.size()<< endl;
	for(auto vi: vvi)
	{
		for(auto v: vi)
		{
			cout << v.getId()<< " ";
		}
		cout << endl;
	}
	tf.getCTimeFrame().print();

	
	 for(auto i :itime)
	{
		cout << i.first.getId() <<" " << i.second.getMin()/60 <<":"<<i.second.getMin()%60 << " "<< i.second.getMax()/60 <<":"<<i.second.getMax()%60 << endl;
	}*/
	
	/*TimeDomain td(irm,itime);
	cout << "Intervals in Range: " << td.areIntervalsInRange() << endl;
	cout << "Ranges valid: " << td.areRangesValid() << endl;
	cout << td.testRules() << endl;
	
	//Range test
	cout << Range(0,100)/ Range(50,150) << endl;
	cout << Range(0,10)/ Range(10,15) << endl;
	cout << Range(0,10)/ Range(11,15) << endl;
	cout << Range(5,15)/ Range(0,10) << endl;
	Range tRange(5,15);
	Range tRange2(20,232);
	cout << (tRange+5)/tRange2 << endl;
	cout << tRange << endl;

	cout << "Filtered Range"<<endl;
	printIRAM(td.filterImpossibleRanges());
	

*/
	return EXIT_SUCCESS;
}
