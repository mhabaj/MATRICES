/**
 * \file CMatrice.h
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

/** \class CMatrice
 * \brief Classe de gestion de matrices.
 *
 * Permet la creation de matrice de n'importe quel type et fournis quelques calculs simples.
 */
template <typename Type> class CMatrice
{

private:
	unsigned int iMATNbCol;/**Nombre de colonnes de la matrice */
	unsigned int iMATNbLig;/**Nombre de lignes de la matrice */
	Type** ppTYPEMATMatrice;/**Elements de la matrice */

public:
	/**
	 * \fn CMatrice()
	 * \brief Constructeur par default.
	 *
	 * Alloue en mémoire l'espace d'un matrice de dimension 1,1.
	 */
	CMatrice();

	/**
	 * \fn CMatrice(const char* sPath)
	 * \brief Constructeur via fichier.
	 *
	 * \param sPath Fichier source de la matrice a creer.
	 * \exception ERREUR_FICHIER Erreur fichier en cas de chemin non valide
	 */
	CMatrice(const char* sPath);

	/**
	 * \fn CMatrice(int iLigne, int iColonne)
	 * \brief Constructeur avec dimensions.
	 *
	 * \param iLigne Nombres de lignes.
	 * \param iColonne Nombre de collones.
 	 * \exception ERREUR_DIMENSIONS Dimensions CMatrice non valide
	 */
	CMatrice(unsigned int uiLigne, unsigned int uiColonne);

	/**
	 * \fn CMatrice(int iLigne, int iColonne, Type* pTypeTableauElems)
	 * \brief Constructeur avec dimensions et contenus.
	 *
	 * \param iLigne Nombres de lignes.
	 * \param iColonne Nombre de collones.
	 * \param pTypeTableauElems tableau des éléments a mettre dans la matrice.
	 * \pre Le nombre d'elements du tableau doit etre egale a iLigne * iColonne.
	 * \exception ERREUR_DIMENSIONS Dimensions CMatrice non valide
	 */
	CMatrice(unsigned int uiLigne, unsigned int uiColonne, const Type* pTypeTableauElems);

	/**
	 * \fn CMatrice(const CMatrice<Type>& MATParam)
	 * \brief Constructeur de recopie.
	 *
	 * \param MATParam Matrice a recopie.
	 */
	CMatrice(const CMatrice<Type>& MATParam);

	/**
	 * \fn operator=(const CMatrice& MATParam)
	 * \brief surcharge de l'operateur =
	 * \param MATParam CMatrice
	 * \return objet CMatrice<Type>&
	 */
	CMatrice<Type>& operator=(const CMatrice& MATParam);

	/**
	 * \fn ~CMatrice()
	 * \brief Destructeur.
	 */
	~CMatrice();

	/**
	* \fn getCol()
	* \brief Renvoie le nombre de colonnes
	*/
	unsigned int getCol() const;

	/**
	* \fn getLig()
	* \brief Renvoie le nombre de lignes
	*/
	unsigned int getLig() const;

	Type** getElems() const;

	/**
	* \fn getElem(int iLig, int iCol) const;
	* \brief Renvoie la valeur de l'element dans la matrice
	* \param iLig Entier representant le numero de la ligne
	* \param iCol Entier representant le numero de la colonne
	* \return Type Element <Type> dans la Matrice
	*/
	Type getElem(unsigned int uiLig, unsigned int uiCol) const;

	/**
	* \fn MATModifierElem(Type elem, int ligne, int colonne);
	* \brief Modifie un element dans la matrice
	* \param elem Nouveau element <Type> a mettre dans la matrice
	* \param ligne Entier representant le numero de la ligne
	* \param colonne Entier representant le numero de la colonne
	*/
	void MATModifierElem(Type elem, unsigned int uiLig, unsigned int uiCol);

	/**
	* \fn MATAjoutLigne();
	* \brief Ajoute une ligne vide a la matrice
	*/
	void MATAjoutLigne();

	/**
	* \fn MATAjoutLigne();
	* \brief Ajoute une ligne remplie a la matrice
	* \param TypeLigne Tableau contenant la ligne a ajouter
	*/
	void MATAjoutLigne(const Type* TypeLigne);

	/**
	* \fn MATAjoutColonne();
	* \brief Ajoute une colonne vide a la matrice
	*/
	void MATAjoutColonne();

	/**
	* \fn MATAjoutColonne(const Type* TypeColonne);
	* \brief Ajoute une colonne remplie a la matrice
	* \param TypeColonne Tableau contenant la colonne a ajouter
	*/
	void MATAjoutColonne(const Type* TypeColonne);

	void MATSupprimerLigne(unsigned int uiIndice);

	void MATSupprimerColonne(unsigned int uiIndice);
};

template<typename Type>
CMatrice<Type>::CMatrice()
{
	iMATNbCol = 1;
	iMATNbLig = 1;
	ppTYPEMATMatrice = (Type**) new Type*[1];
	ppTYPEMATMatrice[0] = (Type*)new Type[1];
}

CMatrice<double>::CMatrice(const char* sPath)//la matrice doit etre une matrice de double
{
	unsigned int uiIniLoop, uiLigLoop, uiColLoop;

	char cType[20];
	unsigned int uiNbLig, uiNbCol;
	
	

	CFichier f(sPath);

	if (!f.utilisable()) {
		Cexception error;
		error.EXCmodifier_valeur(ERREUR_FICHIER);//Le fichier n'est pas utilisable : non existant ou chemin errone
		throw error;
	}
	else {
		f.nextSep('=');
		f.getString(cType);

		f.nextSep('=');
		uiNbLig = f.getInt();

		f.nextSep('=');
		uiNbCol = f.getInt();

		iMATNbLig = uiNbLig;
		iMATNbCol = uiNbCol;

		ppTYPEMATMatrice = new double*[iMATNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

		for (uiIniLoop = 0; uiIniLoop < iMATNbCol; uiIniLoop++) {
			ppTYPEMATMatrice[uiIniLoop] = new double[iMATNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
		}

		f.nextSep('[');
		f.next();

		for (uiLigLoop = 0; uiLigLoop < iMATNbLig; uiLigLoop++)
		{
			for (uiColLoop = 0; uiColLoop < iMATNbCol; uiColLoop++)
			{
				MATModifierElem(f.getDouble(), uiLigLoop, uiColLoop);
			}
		}
	}
}

template<typename Type>
CMatrice<Type>::CMatrice(unsigned int uiLigne, unsigned int uiColonne) //nombre de lignes et de colonnes plus grand ou égale a 1.
{
	if (uiLigne < 1 || uiColonne < 1) {
		Cexception error;
		error.EXCmodifier_valeur(ERREUR_DIMENSIONS);//Les dimensions sont inférieurs a 1
		throw error;
	}
	else {
		unsigned int uiIniLoop;

		iMATNbCol = uiColonne;
		iMATNbLig = uiLigne;

		ppTYPEMATMatrice = (Type**) new Type*[iMATNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

		for (uiIniLoop = 0; uiIniLoop < iMATNbCol; uiIniLoop++) {
			ppTYPEMATMatrice[uiIniLoop] = (Type*)new Type[iMATNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
		}
	}
}


template<typename Type>
CMatrice<Type>::CMatrice(unsigned int uiLigne, unsigned int uiColonne, const Type* pTypeTableauElems) //le tableau doit pouvoir remplir la matrice
{
	if (uiLigne < 1 || uiColonne < 1) {
		Cexception error;
		error.EXCmodifier_valeur(ERREUR_DIMENSIONS);//Les dimensions sont inférieurs a 1
		throw error;
	}
	else {
		unsigned int uiIniLoop, uiLigLoop, uiColLoop;

		iMATNbCol = uiColonne;
		iMATNbLig = uiLigne;

		ppTYPEMATMatrice = (Type**) new Type*[iMATNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

		for (uiIniLoop = 0; uiIniLoop < iMATNbCol; uiIniLoop++) {
			ppTYPEMATMatrice[uiIniLoop] = (Type*)new Type[iMATNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
		}

		for (uiLigLoop = 0; uiLigLoop < iMATNbLig; uiLigLoop++)
		{
			for (uiColLoop = 0; uiColLoop < iMATNbCol; uiColLoop++)
			{
				ppTYPEMATMatrice[uiColLoop][uiLigLoop] = pTypeTableauElems[uiLigLoop*iMATNbCol + uiColLoop];
			}
		}
	}
}

template<typename Type>
CMatrice<Type>::CMatrice(const CMatrice<Type>& MATParam)
{
	if (MATParam.ppTYPEMATMatrice) {

		unsigned int uiIniLoop, uiLigLoop, uiColLoop;

		iMATNbCol = MATParam.iMATNbCol;
		iMATNbLig = MATParam.iMATNbLig;

		ppTYPEMATMatrice = (Type**) new Type*[iMATNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

		for (uiIniLoop = 0; uiIniLoop < iMATNbCol; uiIniLoop++) {
			ppTYPEMATMatrice[uiIniLoop] = (Type*)new Type[iMATNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
		}

		for (uiLigLoop = 0; uiLigLoop < iMATNbLig; uiLigLoop++)
		{
			for (uiColLoop = 0; uiColLoop < iMATNbCol; uiColLoop++)
			{
				ppTYPEMATMatrice[uiColLoop][uiLigLoop] = MATParam.ppTYPEMATMatrice[uiColLoop][uiLigLoop];
			}
		}
	}
}

template<typename Type>
CMatrice<Type>& CMatrice<Type>::operator=(const CMatrice& MATParam)
{
	unsigned int uiIniLoop, uiLigLoop, uiColLoop;

	iMATNbCol = MATParam.iMATNbCol;
	iMATNbLig = MATParam.iMATNbLig;

	ppTYPEMATMatrice = (Type**) new Type*[iMATNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

	for (uiIniLoop = 0; uiIniLoop < iMATNbCol; uiIniLoop++) {
		ppTYPEMATMatrice[uiIniLoop] = (Type*)new Type[iMATNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
	}

	for (uiLigLoop = 0; uiLigLoop < iMATNbLig; uiLigLoop++)
	{
		for (uiColLoop = 0; uiColLoop < iMATNbCol; uiColLoop++)
		{
			ppTYPEMATMatrice[uiColLoop][uiLigLoop] = MATParam.ppTYPEMATMatrice[uiColLoop][uiLigLoop];
		}
	}

	return *this;
}

template<typename Type>
std::ostream& operator<<(std::ostream& flux, CMatrice<Type> const& mat)
{
	if (!flux.good()) {
		Cexception error;
		error.EXCmodifier_valeur(ERREUR_FLUX);//Le flux de donné n'est pas utilisable
		throw error;
	}
	else {
		unsigned int uiLigLoop, uiColLoop;

		flux << "[";
		for (uiLigLoop = 0; uiLigLoop < mat.getLig(); uiLigLoop++)
		{
			flux << "[";
			for (uiColLoop = 0; uiColLoop < mat.getCol(); uiColLoop++)
			{
				if (uiColLoop != mat.getCol() - 1)
					flux << mat.getElem(uiLigLoop, uiColLoop) << " ";
				else
					flux << mat.getElem(uiLigLoop, uiColLoop);
			}
			if (uiLigLoop != mat.getLig() - 1)
				flux << "] ";
			else
				flux << "]";
		}
		flux << "]";

		return flux;
	}
}

template<typename Type>
CMatrice<Type>::~CMatrice()
{
	if (ppTYPEMATMatrice) {

		unsigned int uiLoop;

		for (uiLoop = 0; uiLoop < iMATNbCol; uiLoop++) {
			delete[] ppTYPEMATMatrice[uiLoop];
		}

		delete[] ppTYPEMATMatrice;
	}
}

template<typename Type>
unsigned int CMatrice<Type>::getCol() const
{
	return iMATNbCol;
}

template<typename Type>
unsigned int CMatrice<Type>::getLig() const
{
	return iMATNbLig;
}

template<typename Type>
Type** CMatrice<Type>::getElems() const
{
	return ppTYPEMATMatrice;
}

template<typename Type>
Type CMatrice<Type>::getElem(unsigned int uiLig, unsigned int uiCol) const
{
	if (uiLig < 0 || uiLig >= iMATNbLig || uiCol < 0 || uiCol >= iMATNbCol) {
		Cexception error;
		error.EXCmodifier_valeur(HORS_DIMENSIONS);//Les indices sont hors de la matrice
		throw error;
	}
	return ppTYPEMATMatrice[uiCol][uiLig];
}

template<typename Type>
void CMatrice<Type>::MATModifierElem(Type TYPEElem, unsigned int uiLig, unsigned int uiCol)
{
	if (uiLig < 0 || uiLig >= iMATNbLig || uiCol < 0 || uiCol >= iMATNbCol) {
		Cexception error;
		error.EXCmodifier_valeur(HORS_DIMENSIONS);//Les indices sont hors de la matrice
		throw error;
	}
	ppTYPEMATMatrice[uiCol][uiLig] = TYPEElem;
}

template<typename Type>
void CMatrice<Type>::MATAjoutLigne()
{
	unsigned int uiIniLoop, uiLigLoop, uiColLoop;
	int iTempNbLig = iMATNbLig + 1;

	Type** ppTYPETempMatrice;

	ppTYPETempMatrice = (Type**) new Type*[iMATNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

	for (uiIniLoop = 0; uiIniLoop < iMATNbCol; uiIniLoop++) {
		ppTYPETempMatrice[uiIniLoop] = (Type*)new Type[iTempNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
	}

	for (uiLigLoop = 0; uiLigLoop < iMATNbLig; uiLigLoop++)
	{
		for (uiColLoop = 0; uiColLoop < iMATNbCol; uiColLoop++)
		{
			ppTYPETempMatrice[uiColLoop][uiLigLoop] = ppTYPEMATMatrice[uiColLoop][uiLigLoop];
		}
	}

	delete(ppTYPEMATMatrice);

	ppTYPEMATMatrice = ppTYPETempMatrice;

	iMATNbLig++;
}

template<typename Type>
void CMatrice<Type>::MATAjoutLigne(const Type* TypeLigne)//tableau de la meme taille que le nombre de colonne
{
	unsigned int uiIniLoop, uiLigLoop, uiColLoop;
	int iTempNbLig = iMATNbLig + 1;

	Type** ppTYPETempMatrice;

	ppTYPETempMatrice = (Type**) new Type*[iMATNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

	for (uiIniLoop = 0; uiIniLoop < iMATNbCol; uiIniLoop++) {
		ppTYPETempMatrice[uiIniLoop] = (Type*)new Type[iTempNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
	}

	for (uiLigLoop = 0; uiLigLoop < iMATNbLig; uiLigLoop++)
	{
		for (uiColLoop = 0; uiColLoop < iMATNbCol; uiColLoop++)
		{
			ppTYPETempMatrice[uiColLoop][uiLigLoop] = ppTYPEMATMatrice[uiColLoop][uiLigLoop];

		}
	}

	for (uiColLoop = 0; uiColLoop < iMATNbCol; uiColLoop++)
	{
		ppTYPETempMatrice[uiColLoop][iTempNbLig-1] = TypeLigne[uiColLoop];
	}

	delete(ppTYPEMATMatrice);

	ppTYPEMATMatrice = ppTYPETempMatrice;

	iMATNbLig++;
}

template<typename Type>
void CMatrice<Type>::MATAjoutColonne()
{
	unsigned int uiIniLoop, uiColLoop;
	int iTempNbCol = iMATNbCol + 1;

	Type** ppTypeTempMatrice;

	ppTypeTempMatrice = (Type**) new Type*[iTempNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

	for (uiIniLoop = 0; uiIniLoop < iTempNbCol; uiIniLoop++) {
		ppTypeTempMatrice[uiIniLoop] = (Type*)new Type[iMATNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
	}

	for (uiColLoop = 0; uiColLoop < iMATNbCol; uiColLoop++)
	{
		ppTypeTempMatrice[uiColLoop] = ppTYPEMATMatrice[uiColLoop];
	}

	delete(ppTYPEMATMatrice);

	ppTYPEMATMatrice = ppTypeTempMatrice;

	iMATNbCol++;
}

template<typename Type>
void CMatrice<Type>::MATAjoutColonne(const Type* TypeColonne)//taille du tableau egale au nombre de lignes
{
	unsigned int uiIniLoop, uiColLoop, uiLigLoop;
	unsigned int iTempNbCol = iMATNbCol + 1;

	Type** ppTypeTempMatrice;

	ppTypeTempMatrice = (Type**) new Type*[iTempNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

	for (uiIniLoop = 0; uiIniLoop < iTempNbCol; uiIniLoop++) {
		ppTypeTempMatrice[uiIniLoop] = (Type*)new Type[iMATNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
	}

	for (uiColLoop = 0; uiColLoop < iMATNbCol; uiColLoop++)
	{
		ppTypeTempMatrice[uiColLoop] = ppTYPEMATMatrice[uiColLoop];
	}

	for (uiLigLoop = 0; uiLigLoop < iTempNbCol; uiLigLoop++)
	{
		ppTypeTempMatrice[iTempNbCol - 1][uiLigLoop] = TypeColonne[uiLigLoop];
	}

	delete(ppTYPEMATMatrice);

	ppTYPEMATMatrice = ppTypeTempMatrice;

	iMATNbCol++;
}


template<typename Type>
void CMatrice<Type>::MATSupprimerLigne(unsigned int uiIndice)
{
	if (iMATNbLig <= 1) {
		Cexception error;
		error.EXCmodifier_valeur(ERREUR_DIMENSIONS);//La matrice sera vide apres suppression
		throw error;
	}
	else if (uiIndice >= iMATNbLig) {
		Cexception error;
		error.EXCmodifier_valeur(HORS_DIMENSIONS);//Les indices sont hors de la matrice
		throw error;
	}
	else {
		unsigned int uiIniLoop, uiLigLoop, uiColLoop, uiGetLoop;
		int iTempNbLig = iMATNbLig - 1;

		Type** ppTYPETempMatrice;

		ppTYPETempMatrice = (Type**) new Type*[iMATNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

		for (uiIniLoop = 0; uiIniLoop < iMATNbCol; uiIniLoop++) {
			ppTYPETempMatrice[uiIniLoop] = (Type*)new Type[iTempNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
		}

		for (uiLigLoop = 0, uiGetLoop = 0; uiLigLoop < iTempNbLig; uiLigLoop++, uiGetLoop++)
		{
			if (uiLigLoop == uiIndice)
				uiGetLoop++;

			for (uiColLoop = 0; uiColLoop < iMATNbCol; uiColLoop++)
			{
				ppTYPETempMatrice[uiColLoop][uiLigLoop] = ppTYPEMATMatrice[uiColLoop][uiGetLoop];
			}
		}

		delete(ppTYPEMATMatrice);

		ppTYPEMATMatrice = ppTYPETempMatrice;

		iMATNbLig--;
	}
}


template<typename Type>
void CMatrice<Type>::MATSupprimerColonne(unsigned int uiIndice)
{
	if (iMATNbCol <= 1) {
		Cexception error;
		error.EXCmodifier_valeur(ERREUR_DIMENSIONS);//La matrice sera vide apres suppression
		throw error;
	}
	else if (uiIndice >= iMATNbCol) {
		Cexception error;
		error.EXCmodifier_valeur(HORS_DIMENSIONS);//Les indices sont hors de la matrice
		throw error;
	}
	else {
		unsigned int uiIniLoop, uiLigLoop, uiColLoop, uiGetLoop;
		int iTempNbCol = iMATNbCol - 1;

		Type** ppTYPETempMatrice;

		ppTYPETempMatrice = (Type**) new Type*[iTempNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

		for (uiIniLoop = 0; uiIniLoop < iMATNbCol; uiIniLoop++) {
			ppTYPETempMatrice[uiIniLoop] = (Type*)new Type[iMATNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
		}

		for (uiColLoop = 0, uiGetLoop = 0; uiColLoop < iTempNbCol; uiColLoop++, uiGetLoop++)
		{
			if (uiColLoop == uiIndice)
				uiGetLoop++;

			ppTYPETempMatrice[uiColLoop] = ppTYPEMATMatrice[uiGetLoop];
		}

		for (uiColLoop = 0; uiColLoop < iTempNbCol; uiColLoop++)
			delete[]
			delete[] ppTYPEMATMatrice;

		ppTYPEMATMatrice = ppTYPETempMatrice;

		iMATNbCol--;
	}
}