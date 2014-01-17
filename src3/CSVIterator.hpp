#pragma once

#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class CSVReader {
  public:
	string operator[](size_t index) const;
	size_t size() const;
	void readNextLine(istream& istr);
  private:
	vector<string> lineVector;
};

istream& operator>>(istream& istr,CSVReader& reader);
/*
int main()
{
    ifstream file("testData/A_002_DurchfuerungBC.csv");

    CSVReader row;
    while(file >> row)
    {
        cout <<row[0] <<" "<<row[1] <<" "<< row[2] <<" "<< row[3] <<" "<< row [4]<< endl;
    }
}*/
