#pragma once

#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class CSVReader
{
    public:
        string operator[](size_t index) const
        {
			if(index < lineVector.size())
            	return lineVector[index];
			else
				return "";
        }
        size_t size() const
        {
            return lineVector.size();
        }
        void readNextLine(istream& istr)
        {
            string line;
            getline(istr,line);

            stringstream lineStream(line);
            string cell;

            lineVector.clear();
            while(getline(lineStream,cell,';'))
            {
                lineVector.push_back(cell);
            }
        }
    private:
        vector<string> lineVector;
};

istream& operator>>(istream& istr,CSVReader& reader)
{
    reader.readNextLine(istr);
    return istr;
}   
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
