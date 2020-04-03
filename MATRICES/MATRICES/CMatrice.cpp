#include "CMatrice.h"

template<typename Type>
CMatrice<Type>::CMatrice()
{
	iMATnbCol = 0;
	iMATnbLig = 0;
	ppTYPEMATMatrice = NULL;
}

template<typename Type>
CMatrice<Type>::CMatrice(string sPath)
{
}

template<typename Type>
CMatrice<Type>::CMatrice(int iLigne, int iColonne)
{
	iMATnbCol = iColonne;
	iMATnbLig = iLigne;

	ppTYPEMATMatrice = (Type**) new Type*[iMATnbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

	for (int iloop = 0; iloop < iMATnbCol; iloop++) {
		ppTYPEMATMatrice[iloop] = (Type*)new Type[iMATnbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
	}
}


template<typename Type>
CMatrice<Type>::CMatrice(int iLigne, int iColonne, Type* pTypeTableauElems)
{
	iMATnbCol = iColonne;
	iMATnbLig = iLigne;

	ppTYPEMATMatrice = (Type**) new Type*[iMATnbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

	for (int iloop = 0; iloop < iMATnbCol; iloop++) {
		ppTYPEMATMatrice[iloop] = (Type*)new Type[iMATnbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
	}

	for (int iloopLig = 0; iloopLig < iMATnbLig; iloopLig++)
	{
		for (int iloopCol = 0; iloopCol < iMATnbCol; iloopCol++)
		{
			ppTYPEMATMatrice[iloopCol][iloopLig] = pTypeTableauElems[iloopLig*iMATnbCol + iloopCol];
		}
	}
}

template<typename Type>
void CMatrice<Type>::MATAfficherMatrice()
{
	for (int iloopLig = 0; iloopLig < iMATnbLig; iloopLig++)
	{
		for (int iloopCol = 0; iloopCol < iMATnbCol; iloopCol++)
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
	return 0;
}