/**
 * \file Cmatrice.h
 * \brief Gestion de Matrices
 * \author ALHABAJ Mahmod, BELDA Tom
 * \version 0.1
 * \date 22 avril 2020
 */
#pragma once

#include "Cexception.h"
#include "CFichier.h"

#include <ostream>
#include <iostream>

/** \class Cmatrice
 * \brief Classe de gestion de matrices.
 *
 * Permet la creation de matrice de n'importe quel type et fournis quelques calculs simples.
 */
template <class Ttype> class Cmatrice
{

private:
	unsigned int uiMATnombre_colonnes;/**Nombre de colonnes de la matrice */
	unsigned int uiMATnombre_lignes;/**Nombre de lignes de la matrice */
	Ttype** ppTMATmatrice;/**Elements de la matrice */

public:
	/**
	 * \fn Cmatrice()
	 * \brief Constructeur par default.
	 *
	 * Alloue en mémoire l'espace d'un matrice de dimension 1,1.
	 */
	Cmatrice();

	/**
	 * \fn Cmatrice(const char* pcChemin)
	 * \brief Constructeur via fichier.
	 * \pre La matrice doit etre une matrice de double.
	 *
	 * \param pcChemin Fichier source de la matrice a creer.
	 * \exception ERREUR_FICHIER Erreur fichier en cas de chemin non valide
	 */
	Cmatrice(const char* pcChemin);

	/**
	 * \fn Cmatrice(int iLigne, int iColonne)
	 * \brief Constructeur avec dimensions.
	 *
	 * \param iLigne Nombres de lignes(plus grand ou egal a 1).
	 * \param iColonne Nombre de colonnes(plus grand ou egal a 1).
 	 * \exception ERREUR_DIMENSIONS Dimensions Cmatrice non valide
	 */
	Cmatrice(unsigned int uiLigne, unsigned int uiColonne);

	/**
	 * \fn Cmatrice(int iLigne, int iColonne, Ttype* pTTableau_elements)
	 * \brief Constructeur avec dimensions et contenus.
	 * \pre Le nombre d'elements du tableau doit etre egale a uiLigne * uiColonne.
	 *
	 * \param uiLigne Nombres de lignes(plus grand ou egal a 1).
	 * \param uiColonne Nombre de collones(plus grand ou egal a 1).
	 * \param pTTableau_elements tableau des éléments a mettre dans la matrice.
	 * \exception ERREUR_DIMENSIONS Dimensions Cmatrice non valide
	 */
	Cmatrice(unsigned int uiLigne, unsigned int uiColonne, const Ttype* pTTableau_elements);

	/**
	 * \fn Cmatrice(const Cmatrice<Ttype>& MATparam)
	 * \brief Constructeur de recopie.
	 *
	 * \param MATparam Cmatrice matrice a recopie.
	 */
	Cmatrice(const Cmatrice<Ttype>& MATparam);

	/**
	 * \fn operator=(const Cmatrice& MATparam)
	 * \brief surcharge de l'operateur =
	 *
	 * \param MATparam Cmatrice
	 * \return objet Cmatrice<Ttype>&
	 */
	Cmatrice<Ttype>& operator=(const Cmatrice& MATparam);

	/**
	 * \fn ~Cmatrice()
	 * \brief Destructeur.
	 */
	~Cmatrice();

	/**
	* \fn MATlire_nombre_colonnes()
	* \brief Renvoie le nombre de colonnes
	*
	* \return unsigned int nombre de colonnes
	*/
	unsigned int MATlire_nombre_colonnes() const;

	/**
	* \fn MATlire_nombre_lignes()
	* \brief Renvoie le nombre de lignes
	*
	* \return unsigned int nombre de ligne
	*/
	unsigned int MATlire_nombre_lignes() const;

	/**
	* \fn MATlire_elements()
	* \brief Renvoie les éléments de la matrice
	*
	* \return Ttype pointeur sur les elements de la matrice
	*/
	Ttype** MATlire_elements() const;

	/**
	* \fn MATlire_element(unsigned int uiLigne, unsigned int uiColonne) const;
	* \brief Renvoie la valeur de l'element dans la matrice
	*
	* \param uiLigne Entier non signe representant le numero de la ligne
	* \param uiColonne Entier non signe representant le numero de la colonne
	* \return Ttype Element <Ttype> dans la Matrice
	*/
	Ttype MATlire_element(unsigned int uiLigne, unsigned int uiColonne) const;

	/**
	* \fn MATmodifier_element(Ttype TElement, unsigned int uiLigne, unsigned int uiColonne);
	* \brief Modifie un element dans la matrice
	*
	* \param TElement Nouveau element <Ttype> a mettre dans la matrice
	* \param uiLigne Entier non signe representant le numero de la ligne
	* \param uiColonne Entier non signe representant le numero de la colonne
	*/
	void MATmodifier_element(Ttype TElement, unsigned int uiLigne, unsigned int uiColonne);

	/**
	* \fn MATajouter_ligne();
	* \brief Ajoute une ligne vide a la matrice
	*/
	void MATajouter_ligne();

	/**
	* \fn MATajouter_ligne();
	* \brief Ajoute une ligne remplie a la matrice
	* \pre Le tableau doit avoir comme taille le nombre de colonnes
	*
	* \param TLigne Tableau contenant la ligne a ajouter
	*/
	void MATajouter_ligne(const Ttype* TLigne);

	/**
	* \fn MATajouter_colonne();
	* \brief Ajoute une colonne vide a la matrice
	*/
	void MATajouter_colonne();

	/**
	* \fn MATajouter_colonne(const Ttype* TColonne);
	* \brief Ajoute une colonne remplie a la matrice
	* \pre Le tableau doit avoir comme taille le nombre de lignes
	*
	* \param TColonne Tableau contenant la colonne a ajouter
	*/
	void MATajouter_colonne(const Ttype* TColonne);

	/**
	* \fn MATsupprimer_ligne(unsigned int uiIndice);
	* \brief supprime la ligne a l'indice
	*
	* \param uiIndice indice de la ligne a supprimer
	*/
	void MATsupprimer_ligne(unsigned int uiIndice);

	/**
	* \fn MATsupprimer_colonne(unsigned int uiIndice);
	* \brief supprime la colonne a l'indice
	*
	* \param uiIndice indice de la colonne a supprimer
	*/
	void MATsupprimer_colonne(unsigned int uiIndice);
};

template<class Ttype>
Cmatrice<Ttype>::Cmatrice()
{
	uiMATnombre_colonnes = 1;
	uiMATnombre_lignes = 1;
	ppTMATmatrice = (Ttype**) new Ttype*[1];
	ppTMATmatrice[0] = (Ttype*)new Ttype[1];
}

Cmatrice<double>::Cmatrice(const char* pcChemin)
{	
	Cfichier f(pcChemin);

	if (!f.FICutilisable()) { //On verifie si le fichier est utilisable
		Cexception EXCerror;
		EXCerror.EXCmodifier_valeur(ERREUR_FICHIER);//Le fichier n'est pas utilisable : non existant ou chemin errone
		throw EXCerror;
	}
	else {
		unsigned int uiBoucle_initialisation, uiBoucle_ligne, uiBoucle_colonne;

		char cType[20];
		unsigned int uiNombre_ligne, uiNombre_colonne;

		f.FICprochain_separateur('=');
		f.FIClire_mot(cType);

		if (strcmp(cType, "double") != 0) {//On verifie que le type de la matrice du fichier est bien double
			Cexception EXCerror;
			EXCerror.EXCmodifier_valeur(ERREUR_TYPE);//Le constructeur par fichier ne fonctionne qu'avec le type double.
			throw EXCerror;
		}
		else {

			f.FICprochain_separateur('=');
			uiNombre_ligne = f.FIClire_int();

			f.FICprochain_separateur('=');
			uiNombre_colonne = f.FIClire_int();

			uiMATnombre_lignes = uiNombre_ligne;
			uiMATnombre_colonnes = uiNombre_colonne;

			ppTMATmatrice = new double*[uiMATnombre_colonnes];//Creer un tableau de tableau, cela represente le nombre de colonnes.

			for (uiBoucle_initialisation = 0; uiBoucle_initialisation < uiMATnombre_colonnes; uiBoucle_initialisation++) {
				ppTMATmatrice[uiBoucle_initialisation] = new double[uiMATnombre_lignes];//Creer un tableau de Ttype sur chaque colonne, cela represente les lignes.
			}

			f.FICprochain_separateur('[');
			f.FIClire_un();

			for (uiBoucle_ligne = 0; uiBoucle_ligne < uiMATnombre_lignes; uiBoucle_ligne++)
			{
				for (uiBoucle_colonne = 0; uiBoucle_colonne < uiMATnombre_colonnes; uiBoucle_colonne++)
				{
					MATmodifier_element(f.FIClire_double(), uiBoucle_ligne, uiBoucle_colonne);
				}
			}
		}
	}
}

template<class Ttype>
Cmatrice<Ttype>::Cmatrice(unsigned int uiLigne, unsigned int uiColonne)
{
	if (uiLigne < 1 || uiColonne < 1) {
		Cexception EXCerror;
		EXCerror.EXCmodifier_valeur(ERREUR_DIMENSIONS);//Les dimensions sont inférieurs a 1
		throw EXCerror;
	}
	else {
		unsigned int uiBoucle_initialisation;

		uiMATnombre_colonnes = uiColonne;
		uiMATnombre_lignes = uiLigne;

		ppTMATmatrice = (Ttype**) new Ttype*[uiMATnombre_colonnes];//Creer un tableau de tableau, cela represente le nombre de colonnes.

		for (uiBoucle_initialisation = 0; uiBoucle_initialisation < uiMATnombre_colonnes; uiBoucle_initialisation++) {
			ppTMATmatrice[uiBoucle_initialisation] = (Ttype*)new Ttype[uiMATnombre_lignes];//Creer un tableau de Ttype sur chaque colonne, cela represente les lignes.
		}
	}
}


template<class Ttype>
Cmatrice<Ttype>::Cmatrice(unsigned int uiLigne, unsigned int uiColonne, const Ttype* pTTableau_elements)
{
	if (uiLigne < 1 || uiColonne < 1) {
		Cexception EXCerror;
		EXCerror.EXCmodifier_valeur(ERREUR_DIMENSIONS);//Les dimensions sont inférieurs a 1
		throw EXCerror;
	}
	else {
		unsigned int uiBoucle_initialisation, uiBoucle_ligne, uiBoucle_colonne;

		uiMATnombre_colonnes = uiColonne;
		uiMATnombre_lignes = uiLigne;

		ppTMATmatrice = (Ttype**) new Ttype*[uiMATnombre_colonnes];//Creer un tableau de tableau, cela represente le nombre de colonnes.

		for (uiBoucle_initialisation = 0; uiBoucle_initialisation < uiMATnombre_colonnes; uiBoucle_initialisation++) {
			ppTMATmatrice[uiBoucle_initialisation] = (Ttype*)new Ttype[uiMATnombre_lignes];//Creer un tableau de Ttype sur chaque colonne, cela represente les lignes.
		}

		for (uiBoucle_ligne = 0; uiBoucle_ligne < uiMATnombre_lignes; uiBoucle_ligne++)//on remplie la matrice avec le tableau d'éléments passer en paramètres
		{
			for (uiBoucle_colonne = 0; uiBoucle_colonne < uiMATnombre_colonnes; uiBoucle_colonne++)
			{
				ppTMATmatrice[uiBoucle_colonne][uiBoucle_ligne] = pTTableau_elements[uiBoucle_ligne*uiMATnombre_colonnes + uiBoucle_colonne];
			}
		}
	}
}

template<class Ttype>
Cmatrice<Ttype>::Cmatrice(const Cmatrice<Ttype>& MATparam)
{
	if (MATparam.ppTMATmatrice) {

		unsigned int uiBoucle_initialisation, uiBoucle_ligne, uiBoucle_colonne;

		uiMATnombre_colonnes = MATparam.uiMATnombre_colonnes;
		uiMATnombre_lignes = MATparam.uiMATnombre_lignes;

		ppTMATmatrice = (Ttype**) new Ttype*[uiMATnombre_colonnes];//Creer un tableau de tableau, cela represente le nombre de colonnes.

		for (uiBoucle_initialisation = 0; uiBoucle_initialisation < uiMATnombre_colonnes; uiBoucle_initialisation++) {
			ppTMATmatrice[uiBoucle_initialisation] = (Ttype*)new Ttype[uiMATnombre_lignes];//Creer un tableau de Ttype sur chaque colonne, cela represente les lignes.
		}

		for (uiBoucle_ligne = 0; uiBoucle_ligne < uiMATnombre_lignes; uiBoucle_ligne++)//On copie le contenu du tableau a recopie
		{
			for (uiBoucle_colonne = 0; uiBoucle_colonne < uiMATnombre_colonnes; uiBoucle_colonne++)
			{
				ppTMATmatrice[uiBoucle_colonne][uiBoucle_ligne] = MATparam.ppTMATmatrice[uiBoucle_colonne][uiBoucle_ligne];
			}
		}
	}
}

template<class Ttype>
Cmatrice<Ttype>& Cmatrice<Ttype>::operator=(const Cmatrice& MATparam)
{
	unsigned int uiBoucle_initialisation, uiBoucle_ligne, uiBoucle_colonne;

	uiMATnombre_colonnes = MATparam.uiMATnombre_colonnes;
	uiMATnombre_lignes = MATparam.uiMATnombre_lignes;

	ppTMATmatrice = (Ttype**) new Ttype*[uiMATnombre_colonnes];//Creer un tableau de tableau, cela represente le nombre de colonnes.

	for (uiBoucle_initialisation = 0; uiBoucle_initialisation < uiMATnombre_colonnes; uiBoucle_initialisation++) {
		ppTMATmatrice[uiBoucle_initialisation] = (Ttype*)new Ttype[uiMATnombre_lignes];//Creer un tableau de Ttype sur chaque colonne, cela represente les lignes.
	}

	for (uiBoucle_ligne = 0; uiBoucle_ligne < uiMATnombre_lignes; uiBoucle_ligne++)
	{
		for (uiBoucle_colonne = 0; uiBoucle_colonne < uiMATnombre_colonnes; uiBoucle_colonne++)
		{
			ppTMATmatrice[uiBoucle_colonne][uiBoucle_ligne] = MATparam.ppTMATmatrice[uiBoucle_colonne][uiBoucle_ligne];
		}
	}

	return *this;
}

/**
 * \fn operator<<(std::ostream& fFlux, Cmatrice<Ttype> const& MATmatrice)
 * \brief surcharge de l'operateur <<
 *
 * \param fFlux flux de données
 * \param MATmatrice matrice a afficher
 * \return std::ostream& flux de données
 */
template<class Ttype>
std::ostream& operator<<(std::ostream& fFlux, Cmatrice<Ttype> const& MATmatrice)
{
	if (!fFlux.good()) {//Si le flux a un probleme
		Cexception EXCerror;
		EXCerror.EXCmodifier_valeur(ERREUR_FLUX);//Le fFlux de donné n'est pas FICutilisable
		throw EXCerror;
	}
	else {
		unsigned int uiBoucle_ligne, uiBoucle_colonne;

		fFlux << "[";
		for (uiBoucle_ligne = 0; uiBoucle_ligne < MATmatrice.MATlire_nombre_lignes(); uiBoucle_ligne++)
		{
			fFlux << "[";
			for (uiBoucle_colonne = 0; uiBoucle_colonne < MATmatrice.MATlire_nombre_colonnes(); uiBoucle_colonne++)
			{
				if (uiBoucle_colonne != MATmatrice.MATlire_nombre_colonnes() - 1)
					fFlux << MATmatrice.MATlire_element(uiBoucle_ligne, uiBoucle_colonne) << " ";
				else
					fFlux << MATmatrice.MATlire_element(uiBoucle_ligne, uiBoucle_colonne);
			}
			if (uiBoucle_ligne != MATmatrice.MATlire_nombre_lignes() - 1)
				fFlux << "] ";
			else
				fFlux << "]";
		}
		fFlux << "]";

		return fFlux;
	}
}

template<class Ttype>
Cmatrice<Ttype>::~Cmatrice()
{
	if (ppTMATmatrice) {

		unsigned int uiBoucle_colonne;

		for (uiBoucle_colonne = 0; uiBoucle_colonne < uiMATnombre_colonnes; uiBoucle_colonne++) {
			delete[] ppTMATmatrice[uiBoucle_colonne];
		}

		delete[] ppTMATmatrice;
	}
}

template<class Ttype>
unsigned int Cmatrice<Ttype>::MATlire_nombre_colonnes() const
{
	return uiMATnombre_colonnes;
}

template<class Ttype>
unsigned int Cmatrice<Ttype>::MATlire_nombre_lignes() const
{
	return uiMATnombre_lignes;
}

template<class Ttype>
Ttype** Cmatrice<Ttype>::MATlire_elements() const
{
	return ppTMATmatrice;
}

template<class Ttype>
Ttype Cmatrice<Ttype>::MATlire_element(unsigned int uiLigne, unsigned int uiColonne) const
{
	if (uiLigne < 0 || uiLigne >= uiMATnombre_lignes || uiColonne < 0 || uiColonne >= uiMATnombre_colonnes) {
		Cexception EXCerror;
		EXCerror.EXCmodifier_valeur(HORS_DIMENSIONS);//Les indices sont hors de la matrice
		throw EXCerror;
	}
	return ppTMATmatrice[uiColonne][uiLigne];
}

template<class Ttype>
void Cmatrice<Ttype>::MATmodifier_element(Ttype TElement, unsigned int uiLigne, unsigned int uiColonne)
{
	if (uiLigne < 0 || uiLigne >= uiMATnombre_lignes || uiColonne < 0 || uiColonne >= uiMATnombre_colonnes) {
		Cexception EXCerror;
		EXCerror.EXCmodifier_valeur(HORS_DIMENSIONS);//Les indices sont hors de la matrice
		throw EXCerror;
	}
	ppTMATmatrice[uiColonne][uiLigne] = TElement;
}

template<class Ttype>
void Cmatrice<Ttype>::MATajouter_ligne()
{
	unsigned int uiBoucle_initialisation, uiBoucle_ligne, uiBoucle_colonne;
	unsigned int uiNombre_lignes_temporaire = uiMATnombre_lignes + 1;

	Ttype** ppTMatrice_temporaire;

	ppTMatrice_temporaire = (Ttype**) new Ttype*[uiMATnombre_colonnes];//Creer un tableau de tableau, cela represente le nombre de colonnes.

	for (uiBoucle_initialisation = 0; uiBoucle_initialisation < uiMATnombre_colonnes; uiBoucle_initialisation++) {
		ppTMatrice_temporaire[uiBoucle_initialisation] = (Ttype*)new Ttype[uiNombre_lignes_temporaire];//Creer un tableau de Ttype sur chaque colonne, cela represente les lignes.
	}

	for (uiBoucle_ligne = 0; uiBoucle_ligne < uiMATnombre_lignes; uiBoucle_ligne++)//On recopier l'ancien tableau dans le nouveau
	{
		for (uiBoucle_colonne = 0; uiBoucle_colonne < uiMATnombre_colonnes; uiBoucle_colonne++)
		{
			ppTMatrice_temporaire[uiBoucle_colonne][uiBoucle_ligne] = ppTMATmatrice[uiBoucle_colonne][uiBoucle_ligne];
		}
	}

	delete[] ppTMATmatrice;

	ppTMATmatrice = ppTMatrice_temporaire;

	uiMATnombre_lignes++;
}

template<class Ttype>
void Cmatrice<Ttype>::MATajouter_ligne(const Ttype* TypeLigne)
{
	unsigned int uiBoucle_initialisation, uiBoucle_ligne, uiBoucle_colonne;
	unsigned int uiNombre_lignes_temporaire = uiMATnombre_lignes + 1;

	Ttype** ppTMatrice_temporaire;

	ppTMatrice_temporaire = (Ttype**) new Ttype*[uiMATnombre_colonnes];//Creer un tableau de tableau, cela represente le nombre de colonnes.

	for (uiBoucle_initialisation = 0; uiBoucle_initialisation < uiMATnombre_colonnes; uiBoucle_initialisation++) {
		ppTMatrice_temporaire[uiBoucle_initialisation] = (Ttype*)new Ttype[uiNombre_lignes_temporaire];//Creer un tableau de Ttype sur chaque colonne, cela represente les lignes.
	}

	for (uiBoucle_ligne = 0; uiBoucle_ligne < uiMATnombre_lignes; uiBoucle_ligne++)//On recopier l'ancien tableau dans le nouveau
	{
		for (uiBoucle_colonne = 0; uiBoucle_colonne < uiMATnombre_colonnes; uiBoucle_colonne++)
		{
			ppTMatrice_temporaire[uiBoucle_colonne][uiBoucle_ligne] = ppTMATmatrice[uiBoucle_colonne][uiBoucle_ligne];

		}
	}

	for (uiBoucle_colonne = 0; uiBoucle_colonne < uiMATnombre_colonnes; uiBoucle_colonne++)//On rajoute le tableau passer en parametre
	{
		ppTMatrice_temporaire[uiBoucle_colonne][uiNombre_lignes_temporaire-1] = TypeLigne[uiBoucle_colonne];
	}

	delete[] ppTMATmatrice;

	ppTMATmatrice = ppTMatrice_temporaire;

	uiMATnombre_lignes++;
}

template<class Ttype>
void Cmatrice<Ttype>::MATajouter_colonne()
{
	unsigned int uiBoucle_initialisation, uiBoucle_colonne;
	unsigned int uiNombre_colonnes_temporaire = uiMATnombre_colonnes + 1;

	Ttype** ppTMatrice_temporaire;

	ppTMatrice_temporaire = (Ttype**) new Ttype*[uiNombre_colonnes_temporaire];//Creer un tableau de tableau, cela represente le nombre de colonnes.

	for (uiBoucle_initialisation = 0; uiBoucle_initialisation < uiNombre_colonnes_temporaire; uiBoucle_initialisation++) {
		ppTMatrice_temporaire[uiBoucle_initialisation] = (Ttype*)new Ttype[uiMATnombre_lignes];//Creer un tableau de Ttype sur chaque colonne, cela represente les lignes.
	}

	for (uiBoucle_colonne = 0; uiBoucle_colonne < uiMATnombre_colonnes; uiBoucle_colonne++)//On recopier l'ancien tableau dans le nouveau
	{
		ppTMatrice_temporaire[uiBoucle_colonne] = ppTMATmatrice[uiBoucle_colonne];
	}

	delete[] ppTMATmatrice;

	ppTMATmatrice = ppTMatrice_temporaire;

	uiMATnombre_colonnes++;
}

template<class Ttype>
void Cmatrice<Ttype>::MATajouter_colonne(const Ttype* TypeColonne)//taille du tableau egale au nombre de lignes
{
	unsigned int uiBoucle_initialisation, uiBoucle_ligne, uiBoucle_colonne;
	unsigned int uiNombre_colonnes_temporaire = uiMATnombre_colonnes + 1;

	Ttype** ppTMatrice_temporaire;

	ppTMatrice_temporaire = (Ttype**) new Ttype*[uiNombre_colonnes_temporaire];//Creer un tableau de tableau, cela represente le nombre de colonnes.

	for (uiBoucle_initialisation = 0; uiBoucle_initialisation < uiNombre_colonnes_temporaire; uiBoucle_initialisation++) {
		ppTMatrice_temporaire[uiBoucle_initialisation] = (Ttype*)new Ttype[uiMATnombre_lignes];//Creer un tableau de Ttype sur chaque colonne, cela represente les lignes.
	}

	for (uiBoucle_colonne = 0; uiBoucle_colonne < uiMATnombre_colonnes; uiBoucle_colonne++)//On recopier l'ancien tableau dans le nouveau
	{
		ppTMatrice_temporaire[uiBoucle_colonne] = ppTMATmatrice[uiBoucle_colonne];
	}

	for (uiBoucle_ligne = 0; uiBoucle_ligne < uiMATnombre_lignes; uiBoucle_ligne++)//On rajoute le tableau passer en parametre
	{
		ppTMatrice_temporaire[uiNombre_colonnes_temporaire - 1][uiBoucle_ligne] = TypeColonne[uiBoucle_ligne];
	}

	delete[] ppTMATmatrice;

	ppTMATmatrice = ppTMatrice_temporaire;

	uiMATnombre_colonnes++;
}


template<class Ttype>
void Cmatrice<Ttype>::MATsupprimer_ligne(unsigned int uiIndice)
{
	if (uiMATnombre_lignes <= 1) {
		Cexception EXCerror;
		EXCerror.EXCmodifier_valeur(ERREUR_DIMENSIONS);//La matrice sera vide apres suppression
		throw EXCerror;
	}
	else if (uiIndice >= uiMATnombre_lignes) {
		Cexception EXCerror;
		EXCerror.EXCmodifier_valeur(HORS_DIMENSIONS);//Les indices sont hors de la matrice
		throw EXCerror;
	}
	else {
		unsigned int uiBoucle_initialisation, uiBoucle_ligne, uiBoucle_colonne, uiBoucle_lecture;
		unsigned int uiNombre_colonnes_temporaire = uiMATnombre_lignes - 1;

		Ttype** ppTMatrice_temporaire;

		ppTMatrice_temporaire = (Ttype**) new Ttype*[uiMATnombre_colonnes];//Creer un tableau de tableau, cela represente le nombre de colonnes.

		for (uiBoucle_initialisation = 0; uiBoucle_initialisation < uiMATnombre_colonnes; uiBoucle_initialisation++) {
			ppTMatrice_temporaire[uiBoucle_initialisation] = (Ttype*)new Ttype[uiNombre_colonnes_temporaire];//Creer un tableau de Ttype sur chaque colonne, cela represente les lignes.
		}

		for (uiBoucle_ligne = 0, uiBoucle_lecture = 0; uiBoucle_ligne < uiNombre_colonnes_temporaire; uiBoucle_ligne++, uiBoucle_lecture++)//On recopie l'ancien tableau
		{
			if (uiBoucle_ligne == uiIndice)//Sauf la ligne que l'on veut retirer
				uiBoucle_lecture++;

			for (uiBoucle_colonne = 0; uiBoucle_colonne < uiMATnombre_colonnes; uiBoucle_colonne++)
			{
				ppTMatrice_temporaire[uiBoucle_colonne][uiBoucle_ligne] = ppTMATmatrice[uiBoucle_colonne][uiBoucle_lecture];
			}
		}

		delete[] ppTMATmatrice;

		ppTMATmatrice = ppTMatrice_temporaire;

		uiMATnombre_lignes--;
	}
}


template<class Ttype>
void Cmatrice<Ttype>::MATsupprimer_colonne(unsigned int uiIndice)
{
	if (uiMATnombre_colonnes <= 1) {
		Cexception error;
		error.EXCmodifier_valeur(ERREUR_DIMENSIONS);//La matrice sera vide apres suppression
		throw error;
	}
	else if (uiIndice >= uiMATnombre_colonnes) {
		Cexception error;
		error.EXCmodifier_valeur(HORS_DIMENSIONS);//Les indices sont hors de la matrice
		throw error;
	}
	else {
		unsigned int uiBoucle_initialisation, uiBoucle_ligne, uiBoucle_colonne, uiBoucle_lecture;
		unsigned int uiNombre_colonnes_temporaire = uiMATnombre_colonnes - 1;

		Ttype** ppTMatrice_temporaire;

		ppTMatrice_temporaire = (Ttype**) new Ttype*[uiNombre_colonnes_temporaire];//Creer un tableau de tableau, cela represente le nombre de colonnes.

		for (uiBoucle_initialisation = 0; uiBoucle_initialisation < uiNombre_colonnes_temporaire; uiBoucle_initialisation++) {
			ppTMatrice_temporaire[uiBoucle_initialisation] = (Ttype*)new Ttype[uiMATnombre_lignes];//Creer un tableau de Ttype sur chaque colonne, cela represente les lignes.
		}

		for (uiBoucle_colonne = 0, uiBoucle_lecture = 0; uiBoucle_colonne < uiNombre_colonnes_temporaire; uiBoucle_colonne++, uiBoucle_lecture++)//On recopie l'ancien tableau
		{
			if (uiBoucle_colonne == uiIndice)//Sauf la colonne que l'on veut retirer
				uiBoucle_lecture++;

			ppTMatrice_temporaire[uiBoucle_colonne] = ppTMATmatrice[uiBoucle_lecture];
		}

		delete[] ppTMATmatrice;

		ppTMATmatrice = ppTMatrice_temporaire;

		uiMATnombre_colonnes--;
	}
}