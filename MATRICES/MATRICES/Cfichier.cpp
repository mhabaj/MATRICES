/**
 * \file Cfichier.cpp
 * \brief Gestion de fichiers
 * \author ALHABAJ Mahmod, BELDA Tom
 * \version 0.1
 * \date 22 avril 2020
 */

 /*
  Modules internes : */
#include "CFichier.h"

//Definitions:
//Voir documentation dans .h

Cfichier::Cfichier(const char* pcChemin)
{
	IFSFlux = new std::ifstream(pcChemin);
	//Si le fichier n'est pas ouvert
	if (IFSFlux->is_open())
		bUtilisable = true;
	else
		bUtilisable = false;
}

Cfichier::~Cfichier()
{
	if (IFSFlux) {
		IFSFlux->close();
		delete IFSFlux;
	}
}

int Cfichier::FIClire_int()
{
	if (IFSFlux->eof()) {
		Cexception EXCerror;
		//Fin du fichier atteinte
		EXCerror.EXCmodifier_valeur(FIN_FICHIER);
		throw EXCerror;
	}
	else {
		int iValeur;
		*IFSFlux >> iValeur;
		if (IFSFlux->fail()) {
			Cexception EXCerror;
			//La valeur en lecture n'est pas un int
			EXCerror.EXCmodifier_valeur(ERREUR_LECTURE);
			throw EXCerror;
		}
		return iValeur;
	}
}

double Cfichier::FIClire_double()
{
	if (IFSFlux->eof()) {
		Cexception EXCerror;
		//Fin du fichier atteinte
		EXCerror.EXCmodifier_valeur(FIN_FICHIER);
		throw EXCerror;
	}
	else {
		double dValeur;
		*IFSFlux >> dValeur;
		if (IFSFlux->fail()) {
			Cexception EXCerror;
			//La valeur en lecture n'est pas un double
			EXCerror.EXCmodifier_valeur(ERREUR_LECTURE);
			throw EXCerror;
		}
		return dValeur;
	}
}

void Cfichier::FIClire_mot(char* pcChaine)
{

	if (IFSFlux->eof()) {
		Cexception EXCerror;
		//Fin du fichier atteinte
		EXCerror.EXCmodifier_valeur(FIN_FICHIER);
		throw EXCerror;
	}
	else {
		*IFSFlux >> pcChaine;
	}
}

char Cfichier::FIClire_un()
{
	if (IFSFlux->eof()) {
		Cexception EXCerror;
		//Fin du fichier atteinte
		EXCerror.EXCmodifier_valeur(FIN_FICHIER);
		throw EXCerror;
	}
	else {
		char cTemp;
		IFSFlux->get(cTemp);
		return cTemp;
	}
}

void Cfichier::FICprochain_separateur(char cSeparateur)
{
	char cSeparateur_temporaire;

	//On prend le prochain caractère tant qu'on a pas le separateur
	do {
		IFSFlux->get(cSeparateur_temporaire);
		if (IFSFlux->eof()) {
			Cexception EXCerror;
			//Fin du fichier atteinte
			EXCerror.EXCmodifier_valeur(FIN_FICHIER);
			throw EXCerror;
		}
	} while (cSeparateur_temporaire != cSeparateur);
	
}

bool Cfichier::FICutilisable()
{
	return bUtilisable;
}