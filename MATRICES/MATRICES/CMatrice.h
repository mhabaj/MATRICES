#pragma once
#include <iostream> 
#include <fstream>
#include <string>
#include "CCalculMatrice.h"

template <typename Type> class CMatrice
{

private:
	int iMATNbCol;
	int iMATNbLig;
	Type** ppTYPEMATMatrice;

public:
	CMatrice();//c fé
	CMatrice(const char* sPath);
	CMatrice(int iLigne, int iColonne);//c fé
	CMatrice(int iLigne, int iColonne, Type* pTypeTableauElems);//Pre condition : taille de pTypeTableauElems = a iLigne*iColonne // c fé
	CMatrice(const CMatrice<Type>& MATParam);//c fé
	~CMatrice();//c fé

	CMatrice<Type>& operator=(const CMatrice& MATParam)//c fé
	{
		iMATNbCol = MATParam.iMATNbCol;
		iMATNbLig = MATParam.iMATNbLig;

		ppTYPEMATMatrice = (Type**) new Type*[iMATNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

		for (int iloop = 0; iloop < iMATNbCol; iloop++) {
			ppTYPEMATMatrice[iloop] = (Type*)new Type[iMATNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
		}

		for (int iloopLig = 0; iloopLig < iMATNbLig; iloopLig++)
		{
			for (int iloopCol = 0; iloopCol < iMATNbCol; iloopCol++)
			{
				ppTYPEMATMatrice[iloopCol][iloopLig] = MATParam.ppTYPEMATMatrice[iloopCol][iloopLig];
			}
		}
		
		return *this;
	}
	int getCol() const;//c fé
	int getLig() const;//c fé
	Type getElem(int iLig, int iCol) const;//c fé
	void MATModifierElem(Type elem, int ligne, int colonne);//c fé
	void MATAjoutLigne();//c fé
	void MATAjoutColonne();//c fé
	void MATAfficherMatrice();//c fé
	CMatrice<Type> operator*(double iScalaire)
	{
		CMatrice<Type> result(iMATNbLig, iMATNbCol);

		for (int iloopLig = 0; iloopLig < iMATNbLig; iloopLig++)
		{
			for (int iloopCol = 0; iloopCol < iMATNbCol; iloopCol++)
			{
				result.MATModifierElem(iScalaire*(ppTYPEMATMatrice[iloopCol][iloopLig]), iloopLig, iloopCol);
			}
		}

		return result;
	}
	CMatrice<Type> operator/(double iScalaire)
	{
		CMatrice<Type> result(iMATNbLig, iMATNbCol);

		for (int iloopLig = 0; iloopLig < iMATNbLig; iloopLig++)
		{
			for (int iloopCol = 0; iloopCol < iMATNbCol; iloopCol++)
			{
				result.MATModifierElem((getElem(iloopLig, iloopCol)) / iScalaire, iloopLig, iloopCol);
			}
		}

		return result;
	}
};

template<typename Type>
CMatrice<Type> operator*(double iScalaire, const CMatrice<Type>& MATmat)
{
	int iLig = MATmat.getLig();
    int iCol = MATmat.getCol();

    CMatrice<Type> result(iLig, iCol);

    for (int iloopLig = 0; iloopLig < iLig; iloopLig++)
    {
        for (int iloopCol = 0; iloopCol < iCol; iloopCol++)
        {
            result.MATModifierElem(iScalaire * (MATmat.getElem(iloopLig, iloopCol)), iloopLig, iloopCol);
        }
    }

    return result;
}