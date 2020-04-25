/**
 * \file CCalculMatrice.h
 * \brief Operations de calcules complexes sur Matrices
 * \author ALHABAJ Mahmod, BELDA Tom
 * \version 0.1
 * \date 22 avril 2020
 */
#pragma once

#include "CMatrice.h"

 /** \class CCalculMatrice
  *  \brief Classe de gestion d'operations de calcules complexes sur Matrices
  * 
  *	 Permet d'effectuer des operations complexes sur des objets CMatrice
  */
template <typename Type> class CCalculMatrice : public CMatrice<Type>
{
public:
	/**
	 * \fn CMatrice()
	 * \brief Constructeur par default.
	 *
	 * Alloue en mémoire l'espace d'un matrice de dimension 1,1.
	 */
	CCalculMatrice(){};

	/**
	 * \fn CMatrice(const char* sPath)
	 * \brief Constructeur via fichier.
	 *
	 * \param sPath Fichier source de la matrice a creer.
	 * \exception ERREUR_FICHIER Erreur fichier en cas de chemin non valide
	 */
	CCalculMatrice(const char* sPath) : CMatrice<Type>(sPath) {}

	/**
	 * \fn CMatrice(int iLigne, int iColonne)
	 * \brief Constructeur avec dimensions.
	 *
	 * \param iLigne Nombres de lignes.
	 * \param iColonne Nombre de collones.
	 * \exception ERREUR_DIMENSIONS Dimensions CMatrice non valide
	 */
	CCalculMatrice(int iLigne, int iColonne) throw(Cexception) : CMatrice<Type>(iLigne, iColonne) {}

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
	CCalculMatrice(int iLigne, int iColonne, Type* pTypeTableauElems) throw(Cexception) : CMatrice<Type>(iLigne, iColonne, pTypeTableauElems) {}

	/**
	 * \fn CMatrice(const CMatrice<Type>& MATParam)
	 * \brief Constructeur de recopie.
	 *
	 * \param MATParam Matrice a recopie.
	 */
	CCalculMatrice(const CMatrice<Type>& MATParam) : CMatrice<Type>(MATParam) {}

	/**
	 * \fn transpose(CMatrice<Type> mat)
	 * \brief Calculer la transpose de la matrice
	 * \tparam <Type> 
	 * \param mat CMatrice<Type> sujet de l'operation
	 * \return objet CMatrice<Type> representant le resultat de l'operation
	 */
	CCalculMatrice<Type> transpose();

	/**
	 * \fn operator*(const double iScalaire)
	 * \brief surcharge de l'operateur * (Multiplication par un scalaire)
	 * \param iScalaire Scalaire a multiplier
	 * \return objet CMatrice<Type> resultat de la multiplication
	 */
	CCalculMatrice<Type> operator*(const double iScalaire);

	/**
	 * \fn operator/(const double iScalaire)
	 * \brief surcharge de l'operateur / (Division par un scalaire)
	 * \param iScalaire Scalaire divisant la CMatrice
	 * \return objet CMatrice<Type> resultat de la multiplication
	 */
	CCalculMatrice<Type> operator/(const double iScalaire) throw(Cexception);

};

template<typename Type>
CCalculMatrice<Type> operator*(const double iScalaire, const CCalculMatrice<Type>& MATmat)//Supporte *
{
	unsigned int uiLigLoop, uiColLoop;

	unsigned int iLig = MATmat.getLig();
	unsigned int iCol = MATmat.getCol();

	CCalculMatrice<Type> result(iLig, iCol);

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
CCalculMatrice<Type> CCalculMatrice<Type>::operator*(const double iScalaire)//Justifier choix multiplication//Supporte *
{
	unsigned int uiLigLoop, uiColLoop;

	CCalculMatrice<Type> result(this->getLig(), this->getCol());

	for (uiLigLoop = 0; uiLigLoop < this->getLig(); uiLigLoop++)
	{
		for (uiColLoop = 0; uiColLoop < this->getCol(); uiColLoop++)
		{
			result.MATModifierElem((this->getElem(uiLigLoop, uiColLoop)) * iScalaire, uiLigLoop, uiColLoop);
		}
	}

	return result;
}

template<typename Type>
CCalculMatrice<Type> CCalculMatrice<Type>::operator/(const double iScalaire) throw(Cexception)//Supporte /
{
	if (iScalaire == 0) {
		Cexception error;
		error.EXCmodifier_valeur(DIVISION_PAR_0);//Division par 0 impossible
		throw error;
	}
	else {
		unsigned int uiLigLoop, uiColLoop;

		CCalculMatrice<Type> result(this->getLig(), this->getCol());

		for (uiLigLoop = 0; uiLigLoop < this->getLig(); uiLigLoop++)
		{
			for (uiColLoop = 0; uiColLoop < this->getCol(); uiColLoop++)
			{
				result.MATModifierElem((this->getElem(uiLigLoop, uiColLoop)) / iScalaire, uiLigLoop, uiColLoop);
			}
		}

		return result;
	}
}

template<typename Type>
CCalculMatrice<Type> operator+(const CCalculMatrice<Type> mat1, const CCalculMatrice<Type> mat2)//Supporte +
{
	if (mat1.getCol() != mat2.getCol() || mat1.getLig() != mat2.getLig()) {
		Cexception error;
		error.EXCmodifier_valeur(ERREUR_DIMENSIONS);//Les dimensions des matrices ne permettent pas l'additon
		throw error;
	}
	else {
		unsigned int uiLigLoop, uiColLoop;

		CCalculMatrice<Type> result(mat1.getLig(), mat1.getCol());

		for (uiLigLoop = 0; uiLigLoop < mat1.getLig(); uiLigLoop++)
		{
			for (uiColLoop = 0; uiColLoop < mat1.getCol(); uiColLoop++)
			{
				result.MATModifierElem(mat1.getElem(uiLigLoop, uiColLoop) + mat2.getElem(uiLigLoop, uiColLoop), uiLigLoop, uiColLoop);
			}
		}
		return result;
	}
}

template<typename Type>
CCalculMatrice<Type> operator-(const CCalculMatrice<Type> mat1, const CCalculMatrice<Type> mat2)//Supporte -
{
	if (mat1.getCol() != mat2.getCol() || mat1.getLig() != mat2.getLig()) {
		Cexception error;
		error.EXCmodifier_valeur(ERREUR_DIMENSIONS);//Les dimensions des matrices ne permettent pas la soustraction
		throw error;
	}
	else {
		unsigned int uiLigLoop, uiColLoop;

		CMatrice<Type> result(mat1.getLig(), mat1.getCol());

		for (uiLigLoop = 0; uiLigLoop < mat1.getLig(); uiLigLoop++)
		{
			for (uiColLoop = 0; uiColLoop < mat1.getCol(); uiColLoop++)
			{
				result.MATModifierElem(mat1.getElem(uiLigLoop, uiColLoop) - mat2.getElem(uiLigLoop, uiColLoop), uiLigLoop, uiColLoop);
			}
		}
		return result;
	}
}

template<typename Type>
CCalculMatrice<Type> operator*(const CCalculMatrice<Type> mat1, const CCalculMatrice<Type> mat2)//supporte *
{
	if (mat1.getCol() != mat2.getLig()) {
		Cexception error;
		error.EXCmodifier_valeur(ERREUR_DIMENSIONS);//Les dimensions des matrices ne permettent pas la multiplication
		throw error;
	}
	else {
		unsigned int uiLigLoop, uiColLoop, uiCalLoop;

		CMatrice<Type> result(mat1.getLig(), mat2.getCol());

		for (uiLigLoop = 0; uiLigLoop < result.getLig(); uiLigLoop++)
		{
			for (uiColLoop = 0; uiColLoop < result.getCol(); uiColLoop++)
			{
				result.MATModifierElem(mat1.getElem(uiLigLoop, 0) * mat2.getElem(0, uiColLoop), uiLigLoop, uiColLoop);
				for (uiCalLoop = 1; uiCalLoop < mat2.getLig(); uiCalLoop++)
				{
					result.MATModifierElem(mat1.getElem(uiLigLoop, uiCalLoop) * mat2.getElem(uiCalLoop, uiColLoop) + result.getElem(uiLigLoop, uiColLoop), uiLigLoop, uiColLoop);
				}
			}
		}
		return result;
	}
}


template<typename Type>
CCalculMatrice<Type> CCalculMatrice<Type>::transpose()
{
	unsigned int uiLigLoop, uiColLoop;

	CMatrice<Type> result(this->getCol(), this->getLig());

	for (uiLigLoop = 0; uiLigLoop < result.getLig(); uiLigLoop++)
	{
		for (uiColLoop = 0; uiColLoop < result.getCol(); uiColLoop++)
		{
			result.MATModifierElem(this->getElem(uiColLoop, uiLigLoop), uiLigLoop, uiColLoop);
		}
	}
	return result;
}