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
 *  Permet de gerer de maniere simple des fichiers
 */

class CFichier {
private:
	std::ifstream* IFSFlux; /** flux de donnees   */
	bool bUtilisable; /** Etat du fichier */
public:
	/**
	 * \fn CFichier(const char* sPath)
	 * \brief Constructeur par default.
	 * \param sPath chaine de caractères representant le chemin vers le fichier a manipuler
	 * Ouvre et prepare le fichier a etre manipulé
	 */
	CFichier(const char* sPath); 

	/**
	 * \fn nextSep(char sep)
	 * \brief Saute jusqu'au prochain separateur dans le fichier
	 * \param sep caractere representant le separateur
	 * \exception FIN_FICHIER le separateur n'existe pas
	 * Ouvre et prepare le fichier a etre manipulé
	 */
	void nextSep(char sep) throw(Cexception);

	/**
	 * \fn getInt()
	 * \brief Recupere le prochain int dans le fichier
	 * \return entier l'element recupere
	 * \exception ERREUR_LECTURE mauvais type en lecture
	 */
	int getInt() throw(Cexception);

	/**
	 * \fn getDouble()
	 * \brief Recupere le prochain Double dans le fichier
	 * \return double l'element recupere
	 * \exception ERREUR_LECTURE mauvais type en lecture
	 */
	double getDouble() throw(Cexception);

	/**
	 * \fn getString()
	 * \brief Recupere la prochaine chaine de caracteres 
	 * \return chaine de caracteres char*
	 */
	void getString(char* sTab);

	/**
	 * \fn next()
	 * \brief saute un caractere
	 * \return caractere 
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
	if (IFSFlux->is_open())//Si le fichier n'est pas ouvert
		bUtilisable = true;
	else
		bUtilisable = false;
}

int CFichier::getInt() throw(Cexception)
{
	if (IFSFlux->eof()) {
		Cexception error;
		error.EXCmodifier_valeur(FIN_FICHIER);//Fin du fichier atteinte
		throw error;
	}
	else {
		int iValue;
		*IFSFlux >> iValue;
		if (IFSFlux->fail()) {
			Cexception error;
			error.EXCmodifier_valeur(ERREUR_LECTURE);//La valeur en lecture n'est pas un int
			throw error;
		}
		return iValue;
	}
}

double CFichier::getDouble() throw(Cexception)
{
	if (IFSFlux->eof()) {
		Cexception error;
		error.EXCmodifier_valeur(FIN_FICHIER);//Fin du fichier atteinte
		throw error;
	}
	else {
		double dValue;
		*IFSFlux >> dValue;
		if (IFSFlux->fail()) {
			Cexception error;
			error.EXCmodifier_valeur(ERREUR_LECTURE);//La valeur en lecture n'est pas un double
			throw error;
		}
		return dValue;
	}
}

void CFichier::getString(char* sTab)//L'utilisateur doit gerer le tableau en param
{
	
	if (IFSFlux->eof()) {
		Cexception error;
		error.EXCmodifier_valeur(FIN_FICHIER);//Fin du fichier atteinte
		throw error;
	}
	else {
		*IFSFlux >> sTab;
	}
}

char CFichier::next()
{
	if (IFSFlux->eof()) {
		Cexception error;
		error.EXCmodifier_valeur(FIN_FICHIER);//Fin du fichier atteinte
		throw error;
	}
	else {
		char cTemp;
		IFSFlux->get(cTemp);
		return cTemp;
	}
}

void CFichier::nextSep(char cSep) throw(Cexception)
{
	char cTempSep;

	do {
		IFSFlux->get(cTempSep);
		if (IFSFlux->eof()) {
			Cexception error;
			error.EXCmodifier_valeur(FIN_FICHIER);//Fin du fichier atteinte
			throw error;
		}
	}
	while (cTempSep != '=');
}

bool CFichier::utilisable()
{
	return bUtilisable;
}