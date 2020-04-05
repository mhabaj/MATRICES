#pragma once
#include <iostream> 
#include <string>   
using namespace std;



template <typename Type> class CMatrice
{

private:
	int iMATNbCol;
	int iMATNbLig;
	Type** ppTYPEMATMatrice;

public:
	CMatrice();//c f�
	CMatrice(string sPath);
	CMatrice(int iLigne, int iColonne);//c f�
	CMatrice(int iLigne, int iColonne, Type* pTypeTableauElems);//Pre condition : taille de pTypeTableauElems = a iLigne*iColonne // c f�
	CMatrice(const CMatrice<Type>& MATParam);//c pa f�
	~CMatrice();

	CMatrice<Type>& operator =(const CMatrice& MATParam)//c pa f�
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
				*ppTYPEMATMatrice[iloopCol][iloopLig] = *MATParam.ppTYPEMATMatrice[iloopCol][iloopLig];
			}
		}
		
		return *this;
	}
	int getCol() const;
	int getLig() const;
	Type getElem(int iLig, int iCol) const;
	void MATModifierElem(Type elem, int ligne, int colonne);//c f�
	void MATAjoutLigne();//c f�
	void MATAjoutColonne();//c f�
	void MATAfficherMatrice();//c f�

};