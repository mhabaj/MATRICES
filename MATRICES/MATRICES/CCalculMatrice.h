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
  *	 Permet d'effectuer des operations complexes sur des objets Cmatrice
  */
template <typename Ttype> class CCalculMatrice : public Cmatrice<Ttype>
{
public:
	/**
	 * \fn Cmatrice()
	 * \brief Constructeur par default.
	 *
	 * Alloue en mémoire l'espace d'un matrice de dimension 1,1.
	 */
	CCalculMatrice(){};

	/**
	 * \fn Cmatrice(const char* sPath)
	 * \brief Constructeur via fichier.
	 *
	 * \param sPath Fichier source de la matrice a creer.
	 * \exception ERREUR_FICHIER Erreur fichier en cas de chemin non valide
	 */
	CCalculMatrice(const char* sPath) : Cmatrice<Ttype>(sPath) {}

	/**
	 * \fn Cmatrice(int iLigne, int iColonne)
	 * \brief Constructeur avec dimensions.
	 *
	 * \param iLigne Nombres de lignes.
	 * \param iColonne Nombre de collones.
	 * \exception ERREUR_DIMENSIONS Dimensions Cmatrice non valide
	 */
	CCalculMatrice(int iLigne, int iColonne)  : Cmatrice<Ttype>(iLigne, iColonne) {}

	/**
	 * \fn Cmatrice(int iLigne, int iColonne, Ttype* pTypeTableauElems)
	 * \brief Constructeur avec dimensions et contenus.
	 *
	 * \param iLigne Nombres de lignes.
	 * \param iColonne Nombre de collones.
	 * \param pTypeTableauElems tableau des éléments a mettre dans la matrice.
	 * \pre Le nombre d'elements du tableau doit etre egale a iLigne * iColonne.
	 * \exception ERREUR_DIMENSIONS Dimensions Cmatrice non valide
	 */
	CCalculMatrice(int iLigne, int iColonne, Ttype* pTypeTableauElems) : Cmatrice<Ttype>(iLigne, iColonne, pTypeTableauElems) {}

	/**
	 * \fn Cmatrice(const Cmatrice<Ttype>& MATParam)
	 * \brief Constructeur de recopie.
	 *
	 * \param MATParam Matrice a recopie.
	 */
	CCalculMatrice(const Cmatrice<Ttype>& MATParam) : Cmatrice<Ttype>(MATParam) {}

	/**
	 * \fn transpose(Cmatrice<Ttype> mat)
	 * \brief Calculer la transpose de la matrice
	 * \tparam <Ttype> 
	 * \param mat Cmatrice<Ttype> sujet de l'operation
	 * \return objet Cmatrice<Ttype> representant le resultat de l'operation
	 */
	CCalculMatrice<Ttype> transpose();

	/**
	 * \fn operator*(const double iScalaire)
	 * \brief surcharge de l'operateur * (Multiplication par un scalaire)
	 * \param iScalaire Scalaire a multiplier
	 * \return objet Cmatrice<Ttype> resultat de la multiplication
	 */
	CCalculMatrice<Ttype> operator*(const double iScalaire);

	/**
	 * \fn operator/(const double iScalaire)
	 * \brief surcharge de l'operateur / (Division par un scalaire)
	 * \param iScalaire Scalaire divisant la Cmatrice
	 * \return objet Cmatrice<Ttype> resultat de la multiplication
	 */
	CCalculMatrice<Ttype> operator/(const double iScalaire);

};

template<typename Ttype>
CCalculMatrice<Ttype> operator*(const double iScalaire, const CCalculMatrice<Ttype>& MATmat)//Supporte *
{
	unsigned int uiLigLoop, uiColLoop;

	unsigned int iLig = MATmat.MATlire_nombre_lignes();
	unsigned int iCol = MATmat.MATlire_nombre_colonnes();

	CCalculMatrice<Ttype> result(iLig, iCol);

	for (uiLigLoop = 0; uiLigLoop < iLig; uiLigLoop++)
	{
		for (uiColLoop = 0; uiColLoop < iCol; uiColLoop++)
		{
			result.MATmodifier_element(iScalaire * (MATmat.MATlire_element(uiLigLoop, uiColLoop)), uiLigLoop, uiColLoop);
		}
	}

	return result;
}

template<typename Ttype>
CCalculMatrice<Ttype> CCalculMatrice<Ttype>::operator*(const double iScalaire)//Justifier choix multiplication//Supporte *
{
	unsigned int uiLigLoop, uiColLoop;

	CCalculMatrice<Ttype> result(this->MATlire_nombre_lignes(), this->MATlire_nombre_colonnes());

	for (uiLigLoop = 0; uiLigLoop < this->MATlire_nombre_lignes(); uiLigLoop++)
	{
		for (uiColLoop = 0; uiColLoop < this->MATlire_nombre_colonnes(); uiColLoop++)
		{
			result.MATmodifier_element((this->MATlire_element(uiLigLoop, uiColLoop)) * iScalaire, uiLigLoop, uiColLoop);
		}
	}

	return result;
}

template<typename Ttype>
CCalculMatrice<Ttype> CCalculMatrice<Ttype>::operator/(const double iScalaire) //Supporte /
{
	if (iScalaire == 0) {
		Cexception error;
		error.EXCmodifier_valeur(DIVISION_PAR_0);//Division par 0 impossible
		throw error;
	}
	else {
		unsigned int uiLigLoop, uiColLoop;

		CCalculMatrice<Ttype> result(this->MATlire_nombre_lignes(), this->MATlire_nombre_colonnes());

		for (uiLigLoop = 0; uiLigLoop < this->MATlire_nombre_lignes(); uiLigLoop++)
		{
			for (uiColLoop = 0; uiColLoop < this->MATlire_nombre_colonnes(); uiColLoop++)
			{
				result.MATmodifier_element((this->MATlire_element(uiLigLoop, uiColLoop)) / iScalaire, uiLigLoop, uiColLoop);
			}
		}

		return result;
	}
}

template<typename Ttype>
CCalculMatrice<Ttype> operator+(const CCalculMatrice<Ttype> mat1, const CCalculMatrice<Ttype> mat2)//Supporte +
{
	if (mat1.MATlire_nombre_colonnes() != mat2.MATlire_nombre_colonnes() || mat1.MATlire_nombre_lignes() != mat2.MATlire_nombre_lignes()) {
		Cexception error;
		error.EXCmodifier_valeur(ERREUR_DIMENSIONS);//Les dimensions des matrices ne permettent pas l'additon
		throw error;
	}
	else {
		unsigned int uiLigLoop, uiColLoop;

		CCalculMatrice<Ttype> result(mat1.MATlire_nombre_lignes(), mat1.MATlire_nombre_colonnes());

		for (uiLigLoop = 0; uiLigLoop < mat1.MATlire_nombre_lignes(); uiLigLoop++)
		{
			for (uiColLoop = 0; uiColLoop < mat1.MATlire_nombre_colonnes(); uiColLoop++)
			{
				result.MATmodifier_element(mat1.MATlire_element(uiLigLoop, uiColLoop) + mat2.MATlire_element(uiLigLoop, uiColLoop), uiLigLoop, uiColLoop);
			}
		}
		return result;
	}
}

template<typename Ttype>
CCalculMatrice<Ttype> operator-(const CCalculMatrice<Ttype> mat1, const CCalculMatrice<Ttype> mat2)//Supporte -
{
	if (mat1.MATlire_nombre_colonnes() != mat2.MATlire_nombre_colonnes() || mat1.MATlire_nombre_lignes() != mat2.MATlire_nombre_lignes()) {
		Cexception error;
		error.EXCmodifier_valeur(ERREUR_DIMENSIONS);//Les dimensions des matrices ne permettent pas la soustraction
		throw error;
	}
	else {
		unsigned int uiLigLoop, uiColLoop;

		Cmatrice<Ttype> result(mat1.MATlire_nombre_lignes(), mat1.MATlire_nombre_colonnes());

		for (uiLigLoop = 0; uiLigLoop < mat1.MATlire_nombre_lignes(); uiLigLoop++)
		{
			for (uiColLoop = 0; uiColLoop < mat1.MATlire_nombre_colonnes(); uiColLoop++)
			{
				result.MATmodifier_element(mat1.MATlire_element(uiLigLoop, uiColLoop) - mat2.MATlire_element(uiLigLoop, uiColLoop), uiLigLoop, uiColLoop);
			}
		}
		return result;
	}
}

template<typename Ttype>
CCalculMatrice<Ttype> operator*(const CCalculMatrice<Ttype> mat1, const CCalculMatrice<Ttype> mat2)//supporte *
{
	if (mat1.MATlire_nombre_colonnes() != mat2.MATlire_nombre_lignes()) {
		Cexception error;
		error.EXCmodifier_valeur(ERREUR_DIMENSIONS);//Les dimensions des matrices ne permettent pas la multiplication
		throw error;
	}
	else {
		unsigned int uiLigLoop, uiColLoop, uiCalLoop;

		Cmatrice<Ttype> result(mat1.MATlire_nombre_lignes(), mat2.MATlire_nombre_colonnes());

		for (uiLigLoop = 0; uiLigLoop < result.MATlire_nombre_lignes(); uiLigLoop++)
		{
			for (uiColLoop = 0; uiColLoop < result.MATlire_nombre_colonnes(); uiColLoop++)
			{
				result.MATmodifier_element(mat1.MATlire_element(uiLigLoop, 0) * mat2.MATlire_element(0, uiColLoop), uiLigLoop, uiColLoop);
				for (uiCalLoop = 1; uiCalLoop < mat2.MATlire_nombre_lignes(); uiCalLoop++)
				{
					result.MATmodifier_element(mat1.MATlire_element(uiLigLoop, uiCalLoop) * mat2.MATlire_element(uiCalLoop, uiColLoop) + result.MATlire_element(uiLigLoop, uiColLoop), uiLigLoop, uiColLoop);
				}
			}
		}
		return result;
	}
}


template<typename Ttype>
CCalculMatrice<Ttype> CCalculMatrice<Ttype>::transpose()
{
	unsigned int uiLigLoop, uiColLoop;

	Cmatrice<Ttype> result(this->MATlire_nombre_colonnes(), this->MATlire_nombre_lignes());

	for (uiLigLoop = 0; uiLigLoop < result.MATlire_nombre_lignes(); uiLigLoop++)
	{
		for (uiColLoop = 0; uiColLoop < result.MATlire_nombre_colonnes(); uiColLoop++)
		{
			result.MATmodifier_element(this->MATlire_element(uiColLoop, uiLigLoop), uiLigLoop, uiColLoop);
		}
	}
	return result;
}