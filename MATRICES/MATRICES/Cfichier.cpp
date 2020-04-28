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
	if (IFSFlux->is_open())//Si le fichier n'est pas ouvert
		bUtilisable = true;
	else
		bUtilisable = false;
}

Cfichier::~Cfichier()
{
	IFSFlux->close();
	delete IFSFlux;
}

int Cfichier::FIClire_int()
{
	if (IFSFlux->eof()) {
		Cexception EXCerror;
		EXCerror.EXCmodifier_valeur(FIN_FICHIER);//Fin du fichier atteinte
		throw EXCerror;
	}
	else {
		int iValeur;
		*IFSFlux >> iValeur;
		if (IFSFlux->fail()) {
			Cexception EXCerror;
			EXCerror.EXCmodifier_valeur(ERREUR_LECTURE);//La valeur en lecture n'est pas un int
			throw EXCerror;
		}
		return iValeur;
	}
}

double Cfichier::FIClire_double()
{
	if (IFSFlux->eof()) {
		Cexception EXCerror;
		EXCerror.EXCmodifier_valeur(FIN_FICHIER);//Fin du fichier atteinte
		throw EXCerror;
	}
	else {
		double dValeur;
		*IFSFlux >> dValeur;
		if (IFSFlux->fail()) {
			Cexception EXCerror;
			EXCerror.EXCmodifier_valeur(ERREUR_LECTURE);//La valeur en lecture n'est pas un double
			throw EXCerror;
		}
		return dValeur;
	}
}

void Cfichier::FIClire_mot(char* pcChaine)
{

	if (IFSFlux->eof()) {
		Cexception EXCerror;
		EXCerror.EXCmodifier_valeur(FIN_FICHIER);//Fin du fichier atteinte
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
		EXCerror.EXCmodifier_valeur(FIN_FICHIER);//Fin du fichier atteinte
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

	do {
		IFSFlux->get(cSeparateur_temporaire);
		if (IFSFlux->eof()) {
			Cexception EXCerror;
			EXCerror.EXCmodifier_valeur(FIN_FICHIER);//Fin du fichier atteinte
			throw EXCerror;
		}
	} while (cSeparateur_temporaire != cSeparateur);
	
}

bool Cfichier::FICutilisable()
{
	return bUtilisable;
}