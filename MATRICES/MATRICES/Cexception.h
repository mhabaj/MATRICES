/**********************************************************
Titre : Classe pour la gestion des exceptions
***********************************************************
Auteur  : V. Ttype'kindt   
Version : 1.0
Date	: 10/07/2006
-------------------------
Lecteur : V. Ttype'kindt     
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
Cette classe permet de cr�er des objets qui sont remont�s 
lors de la lev�e d'exception dans votre programme.
***********************************************************/

#pragma once

#include <iostream>

// D�finition de la valeur initiale d'une exception
#define FAUX 0					
#define FICHIER_INTROUVABLE 1
#define ERREUR_DIMENSIONS 2
#define HORS_DIMENSIONS 3
#define DIVISION_PAR_0 4
#define ERREUR_FICHIER 5
#define ERREUR_LECTURE 6
#define FIN_FICHIER 7
#define ERREUR_FLUX 8

class Cexception
{
 // Cette classe repr�sente une ou plusieurs exceptions lev�es 
 // par le programme

 //Attributs :
 private :
     unsigned int uiEXCvaleur;//cette variable contient la valeur de l'exception						      
  
 /*ETAT INITIAL
    uiEXCvaleur = FAUX*/

 //Primitives :
 public :
   Cexception();
   /* Constructeur par d�faut de la classe 
	E : n�ant
	n�cessite : n�ant
	S : n�ant
	entra�ne : l'exception est initialis� � FAUX */
   ~Cexception(){}
   /* Destructeur de la classe
	E : n�ant
	n�cessite : n�ant
	S : n�ant
	entra�ne : l'exception est d�truite*/
   void EXCmodifier_valeur(unsigned int);
   /* Cette fonction permet de modifier la valeur de l'exception
	E : nouvelle valeur
	n�cessite : n�ant
	S : n�ant
	entra�ne : la valeur de l'exception est modifi�e*/
   unsigned int EXClire_valeur();
   /* Cette fonction permet de consulter la valeur de l'exception
	E : n�ant
	n�cessite : n�ant
	S : valeur de l'exception
	entra�ne : la valeur de l'exception est retourn�e*/
   void EXCaffiche_erreur();
 //MODULES EXTERNES
};

/**************************************************************
Nom : EXClire_valeur
***************************************************************
Cette fonction permet de consulter la valeur de l'exception
***************************************************************
Entr�e : rien
N�cessite : n�ant 
Sortie : la valeur de l'exception
Entra�ne : L'exception est retourn�e
***************************************************************/
inline unsigned int Cexception::EXClire_valeur()
{
 return(uiEXCvaleur);
}