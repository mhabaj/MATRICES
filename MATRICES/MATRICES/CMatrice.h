#pragma once
#include <iostream> 
#include <string>
#include "CCalculMatrice.h"

template <typename Type> class CMatrice
{

private:
	int iMATNbCol;
	int iMATNbLig;
	Type** ppTYPEMATMatrice;

public:
	CMatrice();//c f�
	CMatrice(std::string sPath);
	CMatrice(int iLigne, int iColonne);//c f�
	CMatrice(int iLigne, int iColonne, Type* pTypeTableauElems);//Pre condition : taille de pTypeTableauElems = a iLigne*iColonne // c f�
	CMatrice(const CMatrice<Type>& MATParam);//c f�
	~CMatrice();//c f�

	CMatrice<Type>& operator =(const CMatrice& MATParam)//c f�
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
	int getCol() const;//c f�
	int getLig() const;//c f�
	Type getElem(int iLig, int iCol) const;//c f�
	void MATModifierElem(Type elem, int ligne, int colonne);//c f�
	void MATAjoutLigne();//c f�
	void MATAjoutColonne();//c f�
	void MATAfficherMatrice();//c f�

};