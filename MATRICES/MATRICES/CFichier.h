#pragma once

#include <iostream> 
#include <fstream>

class CFichier {
private:
	std::ifstream* IFSFlux;
public:
	CFichier(const char* sPath);
	void nextSep(char sep);
	int getInt();
	double getDouble();
	char* getString();
	char next();
};

CFichier::CFichier(const char* sPath)
{
	IFSFlux = new std::ifstream(sPath);
}

int CFichier::getInt()
{
	int iValue;
	*IFSFlux >> iValue;
	return iValue;
}

double CFichier::getDouble()
{
	double dValue;
	*IFSFlux >> dValue;
	return dValue;
}

char* CFichier::getString()
{
	char cValue[255];
	*IFSFlux >> cValue;
	return cValue;
}

char CFichier::next()
{
	char cTemp;
	IFSFlux->get(cTemp);
	return cTemp;
}

void CFichier::nextSep(char cSep)
{
	char cTempSep;

	do {
		IFSFlux->get(cTempSep);
	}
	while (cTempSep != '=');
}