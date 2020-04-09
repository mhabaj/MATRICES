#include "CMatrice.h"

template<typename Type>
CMatrice<Type>::CMatrice()
{
	iMATNbCol = 0;
	iMATNbLig = 0;
	ppTYPEMATMatrice = NULL;
}

template<typename Type>
CMatrice<Type>::CMatrice(const char* sPath)
{
	std::ifstream IFSFlux(sPath);
	if (IFSFlux) {
		char cTemp = ' ';
		while (cTemp != '=') {
			IFSFlux.get(cTemp);
		}
		char type[16];
		IFSFlux >> type;

		cTemp = ' ';
		while (cTemp != '=') {
			IFSFlux.get(cTemp);
		}
		int nbLig;
		IFSFlux >> nbLig;

		cTemp = ' ';
		while (cTemp != '=') {
			IFSFlux.get(cTemp);
		}
		int nbCol;
		IFSFlux >> nbCol;

		iMATNbLig = nbLig;
		iMATNbCol = nbCol;

		ppTYPEMATMatrice = (Type**) new Type*[iMATNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

		for (int iloop = 0; iloop < iMATNbCol; iloop++) {
			ppTYPEMATMatrice[iloop] = (Type*)new Type[iMATNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
		}

		cTemp = ' ';
		while (cTemp != '[') {
			IFSFlux.get(cTemp);
		}
		IFSFlux.get(cTemp);

		for (int iloopLig = 0; iloopLig < iMATNbLig; iloopLig++)
		{
			for (int iloopCol = 0; iloopCol < iMATNbCol; iloopCol++)
			{
				double temp = 0;
				IFSFlux >> temp;
				MATModifierElem(temp, iloopLig, iloopCol);
			}
		}
	}
	else {
		std::cout << "ERREUR !!!! ERREUR !!!!";
	}
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
CMatrice<Type>::CMatrice(const CMatrice<Type>& MATParam)
{
	if (MATParam.ppTYPEMATMatrice) {

		iMATNbCol = MATParam.iMATNbCol;
		iMATNbLig = MATParam.iMATNbLig;

		ppTYPEMATMatrice = new Type*[iMATNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

		for (int iloop = 0; iloop < iMATNbCol; iloop++) {
			ppTYPEMATMatrice[iloop] = new Type[iMATNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
		}

		for (int iloop = 0; iloop < iMATNbCol; iloop++)
		{
			for (int iloopLig = 0; iloopLig < iMATNbLig; iloopLig++)
			{
				ppTYPEMATMatrice[iloop][iloopLig] = MATParam.ppTYPEMATMatrice[iloop][iloopLig];
			}
		}
	}
}

template<typename Type>
CMatrice<Type>::~CMatrice()
{
	if (ppTYPEMATMatrice) {
		for (int i = 0; i < iMATNbCol; i++) {
			delete[] ppTYPEMATMatrice[i];
		}

			delete[] ppTYPEMATMatrice;
	}
}

template<typename Type>
int CMatrice<Type>::getCol() const
{
	return iMATNbCol;
}

template<typename Type>
int CMatrice<Type>::getLig() const
{
	return iMATNbLig;
}

template<typename Type>
Type CMatrice<Type>::getElem(int iLig, int iCol) const
{
	return ppTYPEMATMatrice[iCol][iLig];
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
	double tab1[4] = { 1, 2, 3, 4 };
	CMatrice<double> m1(2, 2, tab1);
	m1.MATAfficherMatrice();
	printf("-------------------------------------\n");
	CMatrice<double> m2(m1);
	m2.MATAfficherMatrice();
	m1.MATModifierElem(0, 0, 0);
	printf("/////////////////////////////////////\n");
	m1.MATAfficherMatrice();
	printf("-------------------------------------\n");
	m2.MATAfficherMatrice();
	printf("/////////////////////////////////////\n");
	CMatrice<double> m3;
	m3 = m2*2.5;
	m2.MATAfficherMatrice();
	printf("-------------------------------------\n");
	m3.MATAfficherMatrice();
	printf("/////////////////////////////////////\n");
	//CMatrice<double> m12("C:/Users/belda_mjro20o/Desktop/mat.txt");
	//m12.MATAfficherMatrice();
	//CCalculMatrice<double>::transpose(m3).MATAfficherMatrice();
	/*
	m1.MATAjoutColonne();
	m1.MATModifierElem(5, 0, 2);
	m1.MATModifierElem(7, 1, 2);
	std::cout << "-----------\n";
	m1.MATAfficherMatrice();
	m1.MATAjoutLigne();
	m1.MATModifierElem(8, 2, 0);
	m1.MATModifierElem(9, 2, 1);
	m1.MATModifierElem(10, 2, 2);
	std::cout << "-----------\n";
	m1.MATAfficherMatrice();
	std::cout << "-----------\n";
	(2*m1).MATAfficherMatrice();
	std::cout << "-----------\n";
	(m1*7).MATAfficherMatrice();
	std::cout << "-----------\n";
	(m1/2).MATAfficherMatrice();
	*/
	return 0;
}