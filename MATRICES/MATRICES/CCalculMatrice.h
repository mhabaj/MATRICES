/**
 * \file CCalculMatrice.h
 * \brief Operations de calcules complexes sur Matrices
 * \author ALHABAJ Mahmod, BELDA Tom
 * \version 0.1
 * \date 22 avril 2020
 */
#pragma once

#include "CMatrice.h"

class CCalculMatrice
{
public:
	template<typename Type>
	static CMatrice<Type> transpose(CMatrice<Type> mat);
	template<typename Type>
	static CMatrice<Type> addition(CMatrice<Type> mat1, CMatrice<Type> mat2);
	template<typename Type>
	static CMatrice<Type> soustraction(CMatrice<Type> mat1, CMatrice<Type> mat2);
	template<typename Type>
	static CMatrice<Type> multiplication(CMatrice<Type> mat1, CMatrice<Type> mat2);
};

template<typename Type>
CMatrice<Type> CCalculMatrice::transpose(CMatrice<Type> mat)
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
static CMatrice<Type> CCalculMatrice::addition(CMatrice<Type> mat1, CMatrice<Type> mat2)
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
static CMatrice<Type> CCalculMatrice::soustraction(CMatrice<Type> mat1, CMatrice<Type> mat2)
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
static CMatrice<Type> CCalculMatrice::multiplication(CMatrice<Type> mat1, CMatrice<Type> mat2)
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