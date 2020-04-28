/**********************************************************
Titre : Classe pour la gestion des exceptions
***********************************************************
Auteur  : V. T'kindt   
Version : 1.0
Date	: 10/07/2006
-------------------------
Lecteur : V. T'kindt     
Date	: 11/07/2006
***********************************************************
Auteur	: 
Version	:
Date	:
-------------------------
Lecteur : 
Date	: 
***********************************************************
Corps de la classe Cexception.
Cette classe permet de cr�er des objets qui sont remont�s 
lors de la lev�e d'exception dans votre programme.
***********************************************************/


/*CLASSE Cexception
  DOCUMENTATION
	Attributs : uiEXCvaleur, entier, contient la valeur de l'exception
	Structure : Cette classe contient une m�thode de modification et une m�thode
			de consultation de la valeur de l'exception
	Modules internes :*/
		#include <fstream>
		#include "Cexception.h"

//CORPS

/**************************************************************
Nom : Cexception
***************************************************************
Constructeur par d�faut de la classe Cexception : permet 
d'initialiser un objet
***************************************************************
Entr�e : rien
N�cessite : n�ant 
Sortie : rien
Entra�ne : L'exception est intialis�e � FAUX
***************************************************************/
Cexception::Cexception()
{
 uiEXCvaleur = FAUX;
 //l'exception est initialis�
}

/**************************************************************
Nom : EXCmodifier_valeur
***************************************************************
Cette fonction permet de modifier la valeur de l'exception
***************************************************************
Entr�e : la nouvelle valeur de l'exception
N�cessite : n�ant 
Sortie : rien
Entra�ne : L'exception est modifi�e
***************************************************************/
void Cexception::EXCmodifier_valeur(unsigned int uiEXCparam)
{
 uiEXCvaleur = uiEXCparam;
 //l'exception est modifi�e
}

void Cexception::EXCafficher_erreur()
{
	switch (uiEXCvaleur) {
	case ERREUR_DIMENSIONS:
		std::cout << "EXCEPTION Erreur : Dimensions non conformes\n";
		break;
	case HORS_DIMENSIONS:
		std::cout << "EXCEPTION Erreur : Indices hors dimension\n";
		break;
	case DIVISION_PAR_0:
		std::cout << "EXCEPTION Erreur : Division par 0\n";
		break;
	case ERREUR_FICHIER:
		std::cout << "EXCEPTION Erreur : Fichier inutilisable ou inexistant\n";
		break;
	case ERREUR_LECTURE:
		std::cout << "EXCEPTION Erreur : Lecture impossible\n";
		break;
	case FIN_FICHIER:
		std::cout << "EXCEPTION Erreur : Fin du fichier\n";
		break;
	case ERREUR_FLUX:
		std::cout << "EXCEPTION Erreur : Probleme flux d'affichage\n";
		break;
	case ERREUR_TYPE:
		std::cout << "EXCEPTION Erreur : Pour les fichiers, seul le type double est accepte\n";
		break;
	case ARGUMENT_INVALIDE:
		std::cout << "EXCEPTION Erreur : Argument invalide passe en parametre\n";
		break;
	default:
		std::cout << "Erreur: Exception non repertorie\n";
	}
}


