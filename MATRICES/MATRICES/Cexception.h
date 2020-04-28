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
Interface de la classe Cexception.
Cette classe permet de créer des objets qui sont remontés 
lors de la levée d'exception dans votre programme.
***********************************************************/

#pragma once

#include <iostream>

// Définition de la valeur initiale d'une exception
#define FAUX 0
#define ERREUR_DIMENSIONS 1 //Les deimensions ne sont pas valide(plus petit que 1)
#define HORS_DIMENSIONS 2 //Indices plus grand que le nombre de colonnes ou de lignes
#define DIVISION_PAR_0 3 //Division par 0
#define ERREUR_FICHIER 4 //Acces au fichier impossible
#define ERREUR_LECTURE 5 //Erreur dans la lecture du fichier(mauvais type demande
#define FIN_FICHIER 6 //Fin du fichier atteinte
#define ERREUR_FLUX 7 //Probleme au niveau d'un flux
#define ERREUR_TYPE 8 //Probleme de type(matrice)

class Cexception
{
 // Cette classe représente une ou plusieurs exceptions levées 
 // par le programme

 //Attributs :
 private :
     unsigned int uiEXCvaleur;//cette variable contient la valeur de l'exception						      
  
 /*ETAT INITIAL
    uiEXCvaleur = FAUX*/

 //Primitives :
 public :
   Cexception();
   /* Constructeur par défaut de la classe 
	E : néant
	nécessite : néant
	S : néant
	entraîne : l'exception est initialisé à FAUX */
   ~Cexception(){}
   /* Destructeur de la classe
	E : néant
	nécessite : néant
	S : néant
	entraîne : l'exception est détruite*/
   void EXCmodifier_valeur(unsigned int);
   /* Cette fonction permet de modifier la valeur de l'exception
	E : nouvelle valeur
	nécessite : néant
	S : néant
	entraîne : la valeur de l'exception est modifiée*/
   unsigned int EXClire_valeur();
   /* Cette fonction permet de consulter la valeur de l'exception
	E : néant
	nécessite : néant
	S : valeur de l'exception
	entraîne : la valeur de l'exception est retournée*/
   void EXCafficher_erreur();
   /* Cette fonction permet d'afficher l'erreur
	E : néant
	nécessite : néant
	S : néant
	entraîne : la valeur de l'exception est affichee*/
};

/**************************************************************
Nom : EXClire_valeur
***************************************************************
Cette fonction permet de consulter la valeur de l'exception
***************************************************************
Entrée : rien
Nécessite : néant 
Sortie : la valeur de l'exception
Entraîne : L'exception est retournée
***************************************************************/
inline unsigned int Cexception::EXClire_valeur()
{
 return(uiEXCvaleur);
}