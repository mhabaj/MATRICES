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
	M�thode : n�ant
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
void Cexception::EXCmodifier_valeur(unsigned int val)
{
 uiEXCvaleur = val;
 //l'exception est modifi�e
}

void Cexception::EXCafficher_erreur()
{
	switch (uiEXCvaleur) {
	case 1:
		std::cout << "Erreur : Fichier introuvable\n";
		break;
	case 2:
		std::cout << "Erreur : Dimensions non conformes\n";
		break;
	case 3:
		std::cout << "Erreur : Indices hors dimension\n";
		break;
	case 4:
		std::cout << "Erreur : Division par 0\n";
		break;
	case 5:
		std::cout << "Erreur : Fichier inutilisable\n";
		break;
	case 6:
		std::cout << "Erreur : Lecture impossible\n";
		break;
	case 7:
		std::cout << "Erreur : Fin du fichier\n";
		break;
	case 8:
		std::cout << "Erreur : Probl�me flux d'affichage\n";
		break;
	case 9:
		std::cout << "Erreur : Pour les fichiers, seul le type double est accepte\n";
		break;
	}
}