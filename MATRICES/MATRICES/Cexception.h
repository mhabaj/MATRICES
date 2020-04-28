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
Cette classe permet de cr�er des objets qui sont remont�s 
lors de la lev�e d'exception dans votre programme.
***********************************************************/

#pragma once

#include <iostream>

// D�finition de la valeur initiale d'une exception
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
   void EXCafficher_erreur();
   /* Cette fonction permet d'afficher l'erreur
	E : n�ant
	n�cessite : n�ant
	S : n�ant
	entra�ne : la valeur de l'exception est affichee*/
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