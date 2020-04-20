/**
 * \file CMatrice.h
 * \brief Gestion de Matrices
 * \author Tom Belda, Mahmod Alhabaj
 * \version 0.1
 * \date 14 avril 2020
 */
#pragma once

#include "Cexception.h"
#include "CFichier.h"

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
	 *
	 * Alloue en mémoire l'espace d'un matrice de dimension 1,1.
	 */
	CMatrice();

	/**
	 * \fn CMatrice(const char* sPath)
	 * \brief Constructeur via fichier.
	 *
	 * \param sPath Fichier source de la matrice a creer.
	 */
	CMatrice(const char* sPath) throw(Cexception);

	/**
	 * \fn CMatrice(int iLigne, int iColonne)
	 * \brief Constructeur avec dimensions.
	 *
	 * \param iLigne Nombres de lignes.
	 * \param iColonne Nombre de collones.
	 */
	CMatrice(int iLigne, int iColonne) throw(Cexception);

	/**
	 * \fn CMatrice(int iLigne, int iColonne, Type* pTypeTableauElems)
	 * \brief Constructeur avec dimensions et contenus.
	 *
	 * \param iLigne Nombres de lignes.
	 * \param iColonne Nombre de collones.
	 * \param pTypeTableauElems tableau des éléments a mettre dans la matrice.
	 * \pre Le nombre d'elements du tableau doit etre egale a iLigne * iColonne.
	 */
	CMatrice(int iLigne, int iColonne, Type* pTypeTableauElems) throw(Cexception);

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
	CMatrice<Type> operator*(const double iScalaire)//Justifier choix multiplication
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
	CMatrice<Type> operator/(const double iScalaire) throw(Cexception)
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
CMatrice<Type> operator*(const double iScalaire, const CMatrice<Type>& MATmat)
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
	iMATNbCol = 1;
	iMATNbLig = 1;
	ppTYPEMATMatrice = (Type**) new Type*[1];
	ppTYPEMATMatrice[0] = (Type*)new Type[1];
}


CMatrice<double>::CMatrice(const char* sPath) throw(Cexception)//la matrice doit etre une matrice de double
{
	unsigned int uiIniLoop, uiLigLoop, uiColLoop;

	char* cType;
	unsigned int uiNbLig, uiNbCol;

	double dValue;

	CFichier f(sPath);
	std::cout << "ain't nothing gonna break my stride\n";

	if (&f == NULL) {
		std::cout << "nobody gonna slow me down\n";
		Cexception error;
		error.EXCmodifier_valeur(ERREUR_FICHIER);
		throw error;
	}
	else {
		std::cout << "oh no, I gotta keep on moving\n";
		f.nextSep('=');
		cType = f.getString();

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
CMatrice<Type>::CMatrice(int iLigne, int iColonne) throw(Cexception) //nombre de lignes et de colonnes plus grand ou égale a 1.
{
	if (iLigne < 1 || iColonne < 1) {
		Cexception error;
		error.EXCmodifier_valeur(ERREUR_DIMENSIONS);
		throw error;
		delete this;
	}
	else {
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
}


template<typename Type>
CMatrice<Type>::CMatrice(int iLigne, int iColonne, Type* pTypeTableauElems) throw(Cexception) //le tableau doit pouvoir remplir la matrice
{
	if (iLigne < 1 || iColonne < 1) {
		Cexception error;
		error.EXCmodifier_valeur(ERREUR_DIMENSIONS);
		throw error;
		delete this;
	}
	else {
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
	if (iLig < 0 || iLig >= iMATNbLig || iCol < 0 || iCol >= iMATNbCol) {
		Cexception error;
		error.EXCmodifier_valeur(HORS_DIMENSIONS);
		throw error;
	}
	return ppTYPEMATMatrice[iCol][iLig];
}

template<typename Type>
void CMatrice<Type>::MATModifierElem(Type TYPEElem, int iLig, int iCol)
{
	if (iLig < 0 || iLig >= iMATNbLig || iCol < 0 || iCol >= iMATNbCol) {
		Cexception error;
		error.EXCmodifier_valeur(HORS_DIMENSIONS);
		throw error;
	}
	ppTYPEMATMatrice[iCol][iLig] = TYPEElem;
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