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

	if (argc != 4) {
		cout << "Dateipfade zu den foldenden Dateien werden benötigt: \nAblauf\nBeziehung\nDurchfuerung" << endl;
		return EXIT_FAILURE;
	}

	ifstream intervalFile(argv[1]);
	ifstream relationFile(argv[2]);
	ifstream timeFile(argv[3]);

	if (!intervalFile.good()) {
		cout << "Der Dateipfad zu Interval ist ungültig" << endl;
		return EXIT_FAILURE;
	}
	if (!relationFile.good()) {
		cout << "Der Dateipfad zu Beziehung ist ungültig" << endl;
		return EXIT_FAILURE;
	}
	if (!timeFile.good()) {
		cout << "Der Dateipfad zu Durchfuerung ist ungültig" << endl;
		return EXIT_FAILURE;
	}


	set<Interval> im = getIntervals(intervalFile);
	map<Interval,map<Interval,axiomSet>> irm = getRelation(relationFile,im);
	map<Interval,Range> itime = getTimeWindow(timeFile,im);

	TimeFrame tf(irm, im);
	TimeDomain td(irm,itime);

	if (!tf.isConsistent()) {
		cout << "Die Beziehungen sind inkonsitent"<< endl;
		return 1;
	}
	cout << "Die Beziehungen sind konsitent"<< endl;

	if (!td.isConsistent()) {
		cout << "Die Durchfuerung ist inkonsistent" <<endl;
		return 1;
	}
	cout << "Die Durchfuerung ist konsistent" <<endl;

	return EXIT_SUCCESS;
}
