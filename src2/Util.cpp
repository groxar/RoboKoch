#include "Util.hpp"


set<Interval> getIntervals(const string& intervalFilePath){
	ifstream intervalFile(intervalFilePath); 
	set<Interval> result;
	CSVReader csvRow;
	int duration;
	int id;

	while(intervalFile >> csvRow)
	{
		try{
			id = stoi(csvRow[0]);
			duration = stoi(csvRow[2]);
			result.insert(Interval(id, duration));
		} 
		catch(const invalid_argument& ex) {
		//	cout << "invalid Line "<< csvRow[0] << " " << csvRow[1] << " " << csvRow[2] << endl;
		}
	}
	return result;
}

map<Interval,map<Interval,axiomSet>> getRelation(const string& timeFilePath, const set<Interval>& intervalSet){

	ifstream timeFile(timeFilePath); 
	map<Interval,map<Interval,axiomSet>> result;
	CSVReader csvRow;
	Interval firstInterval(-1);
	Interval secondInterval(-1);
	string relation;

	while(timeFile >> csvRow)
	{
		try{
			firstInterval = *intervalSet.find(Interval(stoi(csvRow[0])));
			secondInterval = *intervalSet.find(Interval(stoi(csvRow[1])));
			relation = csvRow[2];
			result[firstInterval][secondInterval] = stringToAxiomSet(relation);
			result[secondInterval][firstInterval] = !stringToAxiomSet(relation); //insert inverse
		} 
		catch(const invalid_argument& ex) {
		//	cout << "invalid Line "<< csvRow[0] << " " << csvRow[1] << " " << csvRow[2] << endl;
		}
	}
	return result;
}

map<Interval,Range> getTimeWindow(const string& relationFilePath, const set<Interval>& intervalSet){

	ifstream relationFile(relationFilePath); 
	map<Interval,pair<int,int>> temp;
	map<Interval,Range> result;
	CSVReader csvRow;
	Interval interval(-1);
	string relation;
	int time = 0;
	int prevTime = 0;
	unsigned int dayCounter =0;

	while(relationFile >> csvRow)
	{
		try{
			interval = *intervalSet.find(Interval(stoi(csvRow[0])));
			relation = csvRow[1];

			prevTime = time;
			time = stringToTime(csvRow[2]) + (dayCounter * 24 * 60);
			if(prevTime > time)
			{
				dayCounter++;
				time += dayCounter * 24 * 60;
			}

			if(relation.compare("Ende")==0)
				temp[interval].second = time;
			else if (relation.compare("Beginn")==0)
				temp[interval].first = time; 
		} 
		catch(const invalid_argument& ex) {
			//cout << "invalid Line "<< csvRow[0] << " " << csvRow[1] << " " << csvRow[2] << endl;
		}
	}
	for(auto ipp : temp)
	{
		result[ipp.first] = Range(ipp.second.first,ipp.second.second);
	}

	return result;
}
int stringToTime(string time){

	vector<int> timeVector;
	stringstream timeStream(time);
	string cell;

	while(getline(timeStream,cell,':'))
	{
		try{
			timeVector.push_back(stoi(cell));
		}
		catch(const invalid_argument& ex) {
			cout << "stringToTime"<<endl;
		}
	}
	if(timeVector.size()==2)
		return timeVector[0]*60+timeVector[1];
	else
		return 0;

}

axiomSet stringToAxiomSet(string relation) {
	vector<string> relationVector; 
	vector<string> tokenVector({"direkt vor","direkt anschliessend","vor","nach","angrenzend","ueberlappend"});
	vector<axiomSet> axiomVector({axiomSet({m}),axiomSet({mi}),axiomSet({st}),axiomSet({gt}),axiomSet({m,mi}),axiomSet({o,oi})});
	axiomSet result;
	size_t pos;

	for(size_t i = 0; i < tokenVector.size();++i){
		while ((pos = relation.find(tokenVector[i])) != std::string::npos) {
			result.insert(axiomVector[i].begin(),axiomVector[i].end());
			relation.erase(pos, pos + tokenVector[i].length());
		}
	}
	return result;
}
