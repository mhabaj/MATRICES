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
	CMatrice<Type> result(mat.getCol(), mat.getLig());
	for (int iloopLig = 0; iloopLig < result.getLig(); iloopLig++)
	{
		for (int iloopCol = 0; iloopCol < result.getCol(); iloopCol++)
		{
			result.MATModifierElem(mat.getElem(iloopCol, iloopLig), iloopLig, iloopCol);
		}
	}
	return result;
}

template<typename Type>
static CMatrice<Type> CCalculMatrice::addition(CMatrice<Type> mat1, CMatrice<Type> mat2)
{
	CMatrice<Type> result(mat1.getCol(), mat1.getLig());
	for (int iloopLig = 0; iloopLig < mat1.getLig(); iloopLig++)
	{
		for (int iloopCol = 0; iloopCol < mat1.getCol(); iloopCol++)
		{
			result.MATModifierElem(mat1.getElem(iloopLig, iloopCol) + mat2.getElem(iloopLig, iloopCol), iloopLig, iloopCol);
		}
	}
	return result;
}

template<typename Type>
static CMatrice<Type> CCalculMatrice::soustraction(CMatrice<Type> mat1, CMatrice<Type> mat2)
{
	CMatrice<Type> result(mat1.getCol(), mat1.getLig());
	for (int iloopLig = 0; iloopLig < mat1.getLig(); iloopLig++)
	{
		for (int iloopCol = 0; iloopCol < mat1.getCol(); iloopCol++)
		{
			result.MATModifierElem(mat1.getElem(iloopLig, iloopCol) - mat2.getElem(iloopLig, iloopCol), iloopLig, iloopCol);
		}
	}
	return result;
}

template<typename Type>
static CMatrice<Type> CCalculMatrice::multiplication(CMatrice<Type> mat1, CMatrice<Type> mat2)
{
	CMatrice<Type> result(mat1.getLig(), mat2.getCol());
	for (int iLoopLig = 0; iLoopLig < result.getLig(); iLoopLig++)
	{
		for (int iLoopCol = 0; iLoopCol < result.getCol(); iLoopCol++)
		{
			for (int iLoopCal = 0; iLoopCal < mat2.getLig(); iLoopCal++)
			{
				result.MATModifierElem(mat1.getElem(iLoopLig, iLoopCal) * mat2.getElem(iLoopCal, iLoopCol) + result.getElem(iLoopLig, iLoopCol), iLoopLig, iLoopCol);
			}
		}
	}
	return result;
}