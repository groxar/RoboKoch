#pragma once
#include "CSVIterator.hpp"
#include "Interval.hpp"
#include "axiomSet.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stdexcept>

using namespace std;


map<int,Interval> getIntervals(const string& intervalFilePath){
	ifstream intervalFile(intervalFilePath); 
	map<int,Interval> result;
	CSVReader csvRow;
	int duration;
	int id;

	while(intervalFile >> csvRow)
	{
		try{
			id = stoi(csvRow[0]);
			duration = stoi(csvRow[2]);
			result.insert(make_pair(id,Interval(duration)));
		} 
		catch(const invalid_argument& ex) {
		//	cout << "invalid Line "<< csvRow[0] << " " << csvRow[1] << " " << csvRow[2] << endl;
		}
	}
	return result;
}

vector<pair<pair<int,int>,axiomSet>> getRelation(const string& relationFilePath){

	ifstream relationFile(relationFilePath); 
	vector<pair<pair<int,int>,axiomSet>> result;
	CSVReader csvRow;
	int firstId;
	int secondId;

	while(relationFile >> csvRow)
	{
		try{
			firstId = stoi(csvRow[0]);
			secondId = stoi(csvRow[0]);
			result.insert(make_pair(make_pair(firstId,secondId),axiomSet({di})));
		} 
		catch(const invalid_argument& ex) {
		//	cout << "invalid Line "<< csvRow[0] << " " << csvRow[1] << " " << csvRow[2] << endl;
		}
	}
	return result;
}
