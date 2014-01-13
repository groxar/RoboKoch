#pragma once
#include "CSVIterator.hpp"
#include "intervalRelMap.hpp"
#include <fstream>
#include <iostream>
#include <map>

intervalRelMap getIntervalRelMap(const string& intervalFilePath,const string& relationFilePath){
	ifstream intervalFile(intervalFilePath); 
	ifstream relationFile(relationFilePath); 
	
	if(intervalFile.good() && relationFile.good()) {
		CSVReader intervalReader(intervalFile);
		CSVReader relationReader(relationFile);
	}

}
