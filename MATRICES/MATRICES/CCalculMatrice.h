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
class CCalculMatrice
{
public:

	/**
	 * \fn transpose(CMatrice<Type> mat)
	 * \brief Calculer la transpose de la matrice
	 * \tparam <Type> 
	 * \param mat CMatrice<Type> sujet de l'operation
	 * \return objet CMatrice<Type> representant le resultat de l'operation
	 */
	template<typename Type>
	static CMatrice<Type> transpose(const CMatrice<Type> mat);

	/**
	 * \fn addition(const CMatrice<Type> mat1, const CMatrice<Type> mat2)
	 * \brief Additionner deux CMatrices
	 * \tparam <Type>
	 * \param mat1 CMatrice
	 * \param mat2 CMatrice
	 * \return objet CMatrice<Type> representant le resultat de l'addition
	 */
	template<typename Type>
	static CMatrice<Type> addition(const CMatrice<Type> mat1, const CMatrice<Type> mat2);

	/**
	 * \fn soustraction(const CMatrice<Type> mat1, const CMatrice<Type> mat2)
	 * \brief soustraire deux CMatrices
	 * \tparam <Type>
	 * \param mat1 CMatrice
	 * \param mat2 CMatrice
	 * \return objet CMatrice<Type> representant le resultat de la soustraction
	 */
	template<typename Type>
	static CMatrice<Type> soustraction(const CMatrice<Type> mat1, const CMatrice<Type> mat2);

	/**
	 * \fn multiplication(const CMatrice<Type> mat1, const CMatrice<Type> mat2)
	 * \brief multiplier deux CMatrices
	 * \tparam <Type>
	 * \param mat1 CMatrice
	 * \param mat2 CMatrice
	 * \return objet CMatrice<Type> representant le resultat de la multiplication
	 */
	template<typename Type>
	static CMatrice<Type> multiplication(const CMatrice<Type> mat1, const CMatrice<Type> mat2);
};

template<typename Type>
CMatrice<Type> CCalculMatrice::transpose(const CMatrice<Type> mat)
{
	unsigned int uiLigLoop, uiColLoop;

	CMatrice<Type> result(mat.getCol(), mat.getLig());

	for (uiLigLoop = 0; uiLigLoop < result.getLig(); uiLigLoop++)
	{
		for (uiColLoop = 0; uiColLoop < result.getCol(); uiColLoop++)
		{
			result.MATModifierElem(mat.getElem(uiColLoop, uiLigLoop), uiLigLoop, uiColLoop);
		}
	}
	return result;
}

template<typename Type>
static CMatrice<Type> CCalculMatrice::addition(const CMatrice<Type> mat1, const CMatrice<Type> mat2)
{
	unsigned int uiLigLoop, uiColLoop;

	CMatrice<Type> result(mat1.getCol(), mat1.getLig());

	for (uiLigLoop = 0; uiLigLoop < mat1.getLig(); uiLigLoop++)
	{
		for (uiColLoop = 0; uiColLoop < mat1.getCol(); uiColLoop++)
		{
			result.MATModifierElem(mat1.getElem(uiLigLoop, uiColLoop) + mat2.getElem(uiLigLoop, uiColLoop), uiLigLoop, uiColLoop);
		}
	}
	return result;
}

template<typename Type>
static CMatrice<Type> CCalculMatrice::soustraction(const CMatrice<Type> mat1, const CMatrice<Type> mat2)
{
	unsigned int uiLigLoop, uiColLoop;

	CMatrice<Type> result(mat1.getCol(), mat1.getLig());

	for (uiLigLoop = 0; uiLigLoop < mat1.getLig(); uiLigLoop++)
	{
		for (uiColLoop = 0; uiColLoop < mat1.getCol(); uiColLoop++)
		{
			result.MATModifierElem(mat1.getElem(uiLigLoop, uiColLoop) - mat2.getElem(uiLigLoop, uiColLoop), uiLigLoop, uiColLoop);
		}
	}
	return result;
}

template<typename Type>
static CMatrice<Type> CCalculMatrice::multiplication(const CMatrice<Type> mat1, const CMatrice<Type> mat2)
{
	unsigned int uiLigLoop, uiColLoop, uiCalLoop;

	CMatrice<Type> result(mat1.getLig(), mat2.getCol());

	for (uiLigLoop = 0; uiLigLoop < result.getLig(); uiLigLoop++)
	{
		for (uiColLoop = 0; uiColLoop < result.getCol(); uiColLoop++)
		{
			for (uiCalLoop = 0; uiCalLoop < mat2.getLig(); uiCalLoop++)
			{
				result.MATModifierElem(mat1.getElem(uiLigLoop, uiCalLoop) * mat2.getElem(uiCalLoop, uiColLoop) + result.getElem(uiLigLoop, uiColLoop), uiLigLoop, uiColLoop);
			}
		}
	}
	return result;
}