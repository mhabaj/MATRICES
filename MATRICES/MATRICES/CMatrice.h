#pragma once

#include <iostream> 
#include <fstream>
#include <string>

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
				result.MATModifierElem((ppTYPEMATMatrice[iloopCol][iloopLig]) * iScalaire, iloopLig, iloopCol);
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

	for (int iloopLig = 0; iloopLig < iMATNbLig; iloopLig++)
	{
		for (int iloopCol = 0; iloopCol < iMATNbCol; iloopCol++)
		{
			ppTYPEMATMatrice[iloopCol][iloopLig] = 0;
		}
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