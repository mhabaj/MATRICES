/**
 * \file Cfichier.h
 * \brief Gestion de fichiers
 * \author ALHABAJ Mahmod, BELDA Tom
 * \version 0.1
 * \date 22 avril 2020
 */
#pragma once
 /*
 Modules internes : */
#include <iostream> 
#include <fstream>

#include "Cexception.h"

/** \class Cfichier
 *  \brief Classe de gestion de fichiers.
 *
 *  Permet de gerer de maniere simple des fichiers
 */

class Cfichier {
private:
	std::ifstream* IFSFlux; /** flux de donnees   */
	bool bUtilisable; /** Etat du fichier */
public:
	/**
	 * \fn Cfichier(const char* pcChemin)
	 * \brief Constructeur par default.
	 *
	 * \param pcChemin chaine de caractères representant le chemin vers le fichier a manipuler
	 * Ouvre et prepare le fichier a etre manipulé
	 */
	Cfichier(const char* pcChemin);

	/**
	 * \fn FICprochain_separateur(char sep)
	 * \brief Saute jusqu'au prochain separateur dans le fichier
	 *
	 * \param sep caractere representant le separateur
	 * \exception FIN_FICHIER le separateur n'existe pas
	 * Ouvre et prepare le fichier a etre manipulé
	 */
	void FICprochain_separateur(char cSeparateur);

	/**
	 * \fn FIClire_int()
	 * \brief Recupere le prochain int dans le fichier
	 *
	 * \return entier l'element recupere
	 * \exception ERREUR_LECTURE mauvais type en lecture
	 */
	int FIClire_int();

	/**
	 * \fn FIClire_double()
	 * \brief Recupere le prochain Double dans le fichier
	 *
	 * \return double l'element recupere
	 * \exception ERREUR_LECTURE mauvais type en lecture
	 */
	double FIClire_double();

	/**
	 * \fn FIClire_mot()
	 * \brief Recupere la prochaine chaine de caracteres 
	 * \pre le tableau en paramètre doit pouvoir contenir le mot recupere
	 *
	 * \return chaine de caracteres char*
	 */
	void FIClire_mot(char* pcChaine);

	/**
	 * \fn FIClire_un()
	 * \brief recupere un caractere
	 *
	 * \return caractere 
	 */
	char FIClire_un();

	/**
	 * \fn FICutilisable()
	 * \brief Verifie si le fichier est FICutilisable
	 *
	 * \return boolean representant l'etat du fichier
	 */
	bool FICutilisable();
};
