#pragma once

#include <iostream> 
#include <fstream>

#include "Cexception.h"

class CFichier {
private:
	std::ifstream* IFSFlux;
	bool bUtilisable;
public:
	CFichier(const char* sPath) throw(Cexception);
	void nextSep(char sep) throw(Cexception);
	int getInt() throw(Cexception);
	double getDouble() throw(Cexception);
	char* getString();
	char next();
	bool utilisable();
};

CFichier::CFichier(const char* sPath)
{
	IFSFlux = new std::ifstream(sPath);
	if (IFSFlux->is_open())
		bUtilisable = true;
	else
		bUtilisable = false;
}

int CFichier::getInt() throw(Cexception)
{
	int iValue;
	*IFSFlux >> iValue;
	if (IFSFlux->fail()) {
		Cexception error;
		error.EXCmodifier_valeur(ERREUR_LECTURE);
		throw error;
	}
	return iValue;
}

double CFichier::getDouble() throw(Cexception)
{
	double dValue;
	*IFSFlux >> dValue;
	if (IFSFlux->fail()) {
		Cexception error;
		error.EXCmodifier_valeur(ERREUR_LECTURE);
		throw error;
	}
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

void CFichier::nextSep(char cSep) throw(Cexception)
{
	char cTempSep;

	do {
		IFSFlux->get(cTempSep);
		if (IFSFlux->eof()) {
			Cexception error;
			error.EXCmodifier_valeur(FIN_FICHIER);
			throw error;
		}
	}
	while (cTempSep != '=');
}

bool CFichier::utilisable()
{
	return bUtilisable;
}