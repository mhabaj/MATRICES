#include "CMatrice.h"

template<typename Type>
CMatrice<Type>::CMatrice()
{
	iMATNbCol = 0;
	iMATNbLig = 0;
	ppTYPEMATMatrice = NULL;
}

template<typename Type>
CMatrice<Type>::CMatrice(string sPath)
{
}

template<typename Type>
CMatrice<Type>::CMatrice(int iLigne, int iColonne)
{
	iMATNbCol = iColonne;
	iMATNbLig = iLigne;

	ppTYPEMATMatrice = (Type**) new Type*[iMATNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

	for (int iloop = 0; iloop < iMATNbCol; iloop++) {
		ppTYPEMATMatrice[iloop] = (Type*)new Type[iMATNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
	}
}


template<typename Type>
CMatrice<Type>::CMatrice(int iLigne, int iColonne, Type* pTypeTableauElems)
{
	iMATNbCol = iColonne;
	iMATNbLig = iLigne;

	ppTYPEMATMatrice = (Type**) new Type*[iMATNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

	for (int iloop = 0; iloop < iMATNbCol; iloop++) {
		ppTYPEMATMatrice[iloop] = (Type*)new Type[iMATNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
	}

	for (int iloopLig = 0; iloopLig < iMATNbLig; iloopLig++)
	{
		for (int iloopCol = 0; iloopCol < iMATNbCol; iloopCol++)
		{
			ppTYPEMATMatrice[iloopCol][iloopLig] = pTypeTableauElems[iloopLig*iMATNbCol + iloopCol];
		}
	}
}

template<typename Type>
CMatrice<Type>::CMatrice(const Type& MATParam)
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
			*ppTYPEMATMatrice[iloopCol][iloopLig] = *(MATParam.ppTYPEMATMatrice[iloopCol][iloopLig]);
		}
	}
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
	int iTempNbLig = iMATNbLig + 1;

	Type** ppTypeTempMatrice;

	ppTypeTempMatrice = (Type**) new Type*[iMATNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

	for (int iloop = 0; iloop < iMATNbCol; iloop++) {
		ppTypeTempMatrice[iloop] = (Type*)new Type[iTempNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
	}

	for (int iloopLig = 0; iloopLig < iMATNbLig; iloopLig++)
	{
		for (int iloopCol = 0; iloopCol < iMATNbCol; iloopCol++)
		{
			ppTypeTempMatrice[iloopCol][iloopLig] = ppTYPEMATMatrice[iloopCol][iloopLig];
		}
	}

	delete(ppTYPEMATMatrice);

	ppTYPEMATMatrice = ppTypeTempMatrice;

	iMATNbLig++;
}

template<typename Type>
void CMatrice<Type>::MATAjoutColonne()
{
	int iTempNbCol = iMATNbCol + 1;

	Type** ppTypeTempMatrice;

	ppTypeTempMatrice = (Type**) new Type*[iTempNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

	for (int iloop = 0; iloop < iTempNbCol; iloop++) {
		ppTypeTempMatrice[iloop] = (Type*)new Type[iMATNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
	}

	for (int iloopCol = 0; iloopCol < iMATNbCol; iloopCol++)
	{
		ppTypeTempMatrice[iloopCol] = ppTYPEMATMatrice[iloopCol];
	}

	delete(ppTYPEMATMatrice);

	ppTYPEMATMatrice = ppTypeTempMatrice;

	iMATNbCol++;
}

template<typename Type>
void CMatrice<Type>::MATAfficherMatrice()
{
	for (int iloopLig = 0; iloopLig < iMATNbLig; iloopLig++)
	{
		for (int iloopCol = 0; iloopCol < iMATNbCol; iloopCol++)
		{
			std::cout << ppTYPEMATMatrice[iloopCol][iloopLig] << " ";
		}
		std::cout << "\n";
	}
}

int main()
{
	int tab1[4] = { 1, 2, 3, 4 };
	CMatrice<int>* m1 = new CMatrice<int>(2, 2, tab1);
	m1->MATAfficherMatrice();
	m1->MATAjoutColonne();
	m1->MATModifierElem(5, 0, 2);
	m1->MATModifierElem(7, 1, 2);
	std::cout << "-----------\n";
	m1->MATAfficherMatrice();
	m1->MATAjoutLigne();
	m1->MATModifierElem(8, 2, 0);
	m1->MATModifierElem(9, 2, 1);
	m1->MATModifierElem(10, 2, 2);
	std::cout << "-----------\n";
	m1->MATAfficherMatrice();
	CMatrice<int>* m2;
	m2 = m1;
	return 0;
}