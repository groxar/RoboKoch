#include "CSVIterator.hpp"

string CSVReader::operator[](size_t index) const
{
	if(index < lineVector.size())
		return lineVector[index];
	else
		return "";
}

size_t CSVReader::size() const
{
	return lineVector.size();
}

void CSVReader::readNextLine(istream& istr)
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


istream& operator>>(istream& istr,CSVReader& reader)
{
    reader.readNextLine(istr);
    return istr;
} 
