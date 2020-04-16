/**
 * \file CMatrice.h
 * \brief Gestion de Matrices
 * \author Tom Belda, Mahmod Alhabaj
 * \version 0.1
 * \date 14 avril 2020
 */
#pragma once

#include <iostream> 
#include <fstream>
#include <string>

#include "Cexception.h"

/** \class CMatrice
 * \brief Classe de gestion de matrices.
 *
 * Permet la creation de matrice de n'importe quel type et fournis quelques calculs simples.
 */
template <typename Type> class CMatrice
{

private:
	int iMATNbCol;/**<Nombre de colonnes de la matrice */
	int iMATNbLig;/**<Nombre de lignes de la matrice */
	Type** ppTYPEMATMatrice;/**<Elements de la matrice */

public:
	/**
	 * \fn CMatrice()
	 * \brief Constructeur par default.
	 */
	CMatrice();

	/**
	 * \fn CMatrice(const char* sPath)
	 * \brief Constructeur via fichier.
	 *
	 * \param sPath Fichier source de la matrice a creer.
	 */
	CMatrice(const char* sPath);

	/**
	 * \fn CMatrice(int iLigne, int iColonne)
	 * \brief Constructeur avec dimensions.
	 *
	 * \param iLigne Nombres de lignes.
	 * \param iColonne Nombre de collones.
	 */
	CMatrice(int iLigne, int iColonne);

	/**
	 * \fn CMatrice(int iLigne, int iColonne, Type* pTypeTableauElems)
	 * \brief Constructeur avec dimensions et contenus.
	 *
	 * \param iLigne Nombres de lignes.
	 * \param iColonne Nombre de collones.
	 * \param pTypeTableauElems tableau des �l�ments a mettre dans la matrice.
	 * \pre Le nombre d'elements du tableau doit etre egale a iLigne * iColonne.
	 */
	CMatrice(int iLigne, int iColonne, Type* pTypeTableauElems);

	/**
	 * \fn CMatrice(const CMatrice<Type>& MATParam)
	 * \brief Constructeur de recopie.
	 *
	 * \param MATParam Matrice a recopie.
	 */
	CMatrice(const CMatrice<Type>& MATParam);

	/**
	 * \fn ~CMatrice()
	 * \brief Destructeur.
	 */
	~CMatrice();
	int getCol() const;
	int getLig() const;
	Type getElem(int iLig, int iCol) const;
	void MATModifierElem(Type elem, int ligne, int colonne);
	void MATAjoutLigne();
	void MATAjoutColonne();
	void MATAfficherMatrice();
	CMatrice<Type>& operator=(const CMatrice& MATParam)
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
	CMatrice<Type> operator*(double iScalaire)
	{
		unsigned int uiLigLoop, uiColLoop;

		CMatrice<Type> result(iMATNbLig, iMATNbCol);

		for (uiLigLoop  = 0; uiLigLoop < iMATNbLig; uiLigLoop++)
		{
			for (uiColLoop = 0; uiColLoop < iMATNbCol; uiColLoop++)
			{
				result.MATModifierElem((ppTYPEMATMatrice[uiColLoop][uiLigLoop]) * iScalaire, uiLigLoop, uiColLoop);
			}
		}

		return result;
	}
	CMatrice<Type> operator/(double iScalaire) throw(Cexception)
	{
		if (iScalaire == 0) {
			Cexception error;
			error.EXCmodifier_valeur(DIVISION_PAR_0);
			throw error;
		}
		else {
			unsigned int uiLigLoop, uiColLoop;

			CMatrice<Type> result(iMATNbLig, iMATNbCol);

			for (uiLigLoop = 0; uiLigLoop < iMATNbLig; uiLigLoop++)
			{
				for (uiColLoop = 0; uiColLoop < iMATNbCol; uiColLoop++)
				{
					result.MATModifierElem((getElem(uiLigLoop, uiColLoop)) / iScalaire, uiLigLoop, uiColLoop);
				}
			}

			return result;
		}
	}
};

template<typename Type>
CMatrice<Type> operator*(double iScalaire, const CMatrice<Type>& MATmat)
{
	unsigned int uiLigLoop, uiColLoop;

	int iLig = MATmat.getLig();
    int iCol = MATmat.getCol();

    CMatrice<Type> result(iLig, iCol);

    for (uiLigLoop = 0; uiLigLoop < iLig; uiLigLoop++)
    {
        for (uiColLoop = 0; uiColLoop < iCol; uiColLoop++)
        {
            result.MATModifierElem(iScalaire * (MATmat.getElem(uiLigLoop, uiColLoop)), uiLigLoop, uiColLoop);
        }
    }

    return result;
}

template<typename Type>
CMatrice<Type>::CMatrice()
{
	iMATNbCol = 0;
	iMATNbLig = 0;
	ppTYPEMATMatrice = NULL;
}

template<typename Type>
CMatrice<Type>::CMatrice(const char* sPath)
{
	unsigned int uiIniLoop, uiLigLoop, uiColLoop;

	char cTempSep = ' ';

	char cType[16];
	unsigned int uiNbLig;
	unsigned int uiNbCol;

	double dValue;

	std::ifstream IFSFlux(sPath);

	if (IFSFlux) {
		while (cTempSep != '=') {
			IFSFlux.get(cTempSep);
		}
		IFSFlux >> cType;

		cTempSep = ' ';
		while (cTempSep != '=') {
			IFSFlux.get(cTempSep);
		}
		IFSFlux >> uiNbLig;

		cTempSep = ' ';
		while (cTempSep != '=') {
			IFSFlux.get(cTempSep);
		}
		IFSFlux >> uiNbCol;

		iMATNbLig = uiNbLig;
		iMATNbCol = uiNbCol;

		ppTYPEMATMatrice = (Type**) new Type*[iMATNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

		for (uiIniLoop = 0; uiIniLoop < iMATNbCol; uiIniLoop++) {
			ppTYPEMATMatrice[uiIniLoop] = (Type*)new Type[iMATNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
		}

		cTempSep = ' ';
		while (cTempSep != '[') {
			IFSFlux.get(cTempSep);
		}
		IFSFlux.get(cTempSep);

		for (uiLigLoop = 0; uiLigLoop < iMATNbLig; uiLigLoop++)
		{
			for (uiColLoop = 0; uiColLoop < iMATNbCol; uiColLoop++)
			{
				IFSFlux >> dValue;
				MATModifierElem(dValue, uiLigLoop, uiColLoop);
			}
		}
	}
	else {
		std::cout << "ERREUR !!!! ERREUR !!!!";
	}
}

template<typename Type>
CMatrice<Type>::CMatrice(int iLigne, int iColonne)
{
	unsigned int uiIniLoop, uiLigLoop, uiColLoop;

	iMATNbCol = iColonne;
	iMATNbLig = iLigne;

	ppTYPEMATMatrice = (Type**) new Type*[iMATNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

	for (uiIniLoop = 0; uiIniLoop < iMATNbCol; uiIniLoop++) {
		ppTYPEMATMatrice[uiIniLoop] = (Type*)new Type[iMATNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
	}

	for (uiLigLoop = 0; uiLigLoop < iMATNbLig; uiLigLoop++)
	{
		for (uiColLoop = 0; uiColLoop < iMATNbCol; uiColLoop++)
		{
			ppTYPEMATMatrice[uiColLoop][uiLigLoop] = 0;
		}
	}
}


template<typename Type>
CMatrice<Type>::CMatrice(int iLigne, int iColonne, Type* pTypeTableauElems)
{
	unsigned int uiIniLoop, uiLigLoop, uiColLoop;

	iMATNbCol = iColonne;
	iMATNbLig = iLigne;

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
int CMatrice<Type>::getCol() const
{
	return iMATNbCol;
}

template<typename Type>
int CMatrice<Type>::getLig() const
{
	return iMATNbLig;
}

template<typename Type>
Type CMatrice<Type>::getElem(int iLig, int iCol) const
{
	return ppTYPEMATMatrice[iCol][iLig];
}

template<typename Type>
void CMatrice<Type>::MATModifierElem(Type elem, int ligne, int colonne)
{
	if (ligne < iMATNbLig && colonne < iMATNbCol) {
		ppTYPEMATMatrice[colonne][ligne] = elem;
	}
}

template<typename Type>
void CMatrice<Type>::MATAjoutLigne()
{
	unsigned int uiIniLoop, uiLigLoop, uiColLoop;
	int iTempNbLig = iMATNbLig + 1;

	Type** ppTypeTempMatrice;

	ppTypeTempMatrice = (Type**) new Type*[iMATNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

	for (uiIniLoop = 0; uiIniLoop < iMATNbCol; uiIniLoop++) {
		ppTypeTempMatrice[uiIniLoop] = (Type*)new Type[iTempNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
	}

	for (uiLigLoop = 0; uiLigLoop < iMATNbLig; uiLigLoop++)
	{
		for (uiColLoop = 0; uiColLoop < iMATNbCol; uiColLoop++)
		{
			ppTypeTempMatrice[uiColLoop][uiLigLoop] = ppTYPEMATMatrice[uiColLoop][uiLigLoop];
		}
	}

	delete(ppTYPEMATMatrice);

	ppTYPEMATMatrice = ppTypeTempMatrice;

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
void CMatrice<Type>::MATAfficherMatrice()
{
	unsigned int uiLigLoop, uiColLoop;

	for (uiLigLoop = 0; uiLigLoop < iMATNbLig; uiLigLoop++)
	{
		for (int uiColLoop = 0; uiColLoop < iMATNbCol; uiColLoop++)
		{
			std::cout << ppTYPEMATMatrice[uiColLoop][uiLigLoop] << " ";
		}
		std::cout << "\n";
	}
}