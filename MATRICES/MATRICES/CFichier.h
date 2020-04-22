/**
 * \file CFichier.h
 * \brief Gestion de fichiers
 * \author ALHABAJ Mahmod, BELDA Tom
 * \version 0.1
 * \date 22 avril 2020
 */
#pragma once

#include <iostream> 
#include <fstream>

#include "Cexception.h"

/** \class CFichier
 *  \brief Classe de gestion de fichiers.
 *
 *  Permet d'effectuer des operations simples sur les fichiers
 */

class CFichier {
private:
	std::ifstream* IFSFlux; /**             */
	bool bUtilisable; /** Etat du fichier */
public:
	/**
	 * \fn CFichier(const char* sPath)
	 * \brief Constructeur par default.
	 * \param sPath chaine de caractères representant le chemin vers le fichier a manipuler 
	 * \exception Cexception LAAAAAAAAAAAAAAAAAAAAAAAA
	 * Ouvre et prepare le fichier a etre manipulé
	 */
	CFichier(const char* sPath) throw(Cexception); ////// OU EST LEXCEPTION LA DEDANS?????

	/**
	 * \fn nextSep(char sep)
	 * \brief LAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
	 * \param sep caractere representant LAAAAAAAAAAAAAAA
	 * \exception Cexception LAAAAAAAAAAAAAAAAAAAAAAAA
	 * Ouvre et prepare le fichier a etre manipulé
	 */
	void nextSep(char sep) throw(Cexception);

	/**
	 * \fn getInt()
	 * \brief Recupere le prochain int dans le fichier
	 * \return entier l'element recupere
	 * \exception Cexception LAAAAAAAAAAAAAAAAAAAAAAAA
	 */
	int getInt() throw(Cexception);

	/**
	 * \fn getDouble()
	 * \brief Recupere le prochain Double dans le fichier
	 * \return double l'element recupere
	 * \exception Cexception LAAAAAAAAAAAAAAAAAAAAAAAA
	 */
	double getDouble() throw(Cexception);

	/**
	 * \fn getString()
	 * \brief LAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
	 * \return chaine de caracteres char* representant LAAAAAAAAAAAAAAAAA
	 */
	char* getString();  //POURQUOI PAS DE EXCEPTION ICI?

	/**
	 * \fn next()
	 * \brief LAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
	 * \return caractere representant LAAAAAAAAAAAAAAAAA
	 */
	char next();

	/**
	 * \fn utilisable()
	 * \brief Verifie si le fichier est utilisable
	 * \return boolean representant l'etat du fichier
	 */
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