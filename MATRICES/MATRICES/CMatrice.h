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
		unsigned int uiIniLoop, uiLigLoop, uiColLoop;

		iMATNbCol = MATParam.iMATNbCol;
		iMATNbLig = MATParam.iMATNbLig;

		ppTYPEMATMatrice = (Type**) new Type*[iMATNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

		for (uiIniLoop = 0; uiIniLoop < iMATNbCol; uiIniLoop++) {
			ppTYPEMATMatrice[uiIniLoop] = (Type*)new Type[iMATNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
		}

		for (uiLigLoop = 0; uiLigLoop < iMATNbLig; uiLigLoop++)
		{
			for (uiColLoop = 0; uiColLoop < iMATNbCol; uiColLoop++)
			{
				ppTYPEMATMatrice[uiColLoop][uiLigLoop] = MATParam.ppTYPEMATMatrice[uiColLoop][uiLigLoop];
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
		unsigned int uiLigLoop, uiColLoop;

		CMatrice<Type> result(iMATNbLig, iMATNbCol);

		for (uiLigLoop  = 0; uiLigLoop < iMATNbLig; uiLigLoop++)
		{
			for (uiColLoop = 0; uiColLoop < iMATNbCol; uiColLoop++)
			{
				result.MATModifierElem((ppTYPEMATMatrice[uiColLoop][uiLigLoop]) * iScalaire, uiLigLoop, uiColLoop);
			}
		}

		return result;
	}
	CMatrice<Type> operator/(double iScalaire)
	{
		unsigned int uiLigLoop, uiColLoop;

		CMatrice<Type> result(iMATNbLig, iMATNbCol);

		for (uiLigLoop = 0; uiLigLoop < iMATNbLig; uiLigLoop++)
		{
			for (uiColLoop = 0; uiColLoop < iMATNbCol; uiColLoop++)
			{
				result.MATModifierElem((getElem(uiLigLoop, uiColLoop)) / iScalaire, uiLigLoop, uiColLoop);
			}
		}

		return result;
	}
};

template<typename Type>
CMatrice<Type> operator*(double iScalaire, const CMatrice<Type>& MATmat)
{
	unsigned int uiLigLoop, uiColLoop;

	int iLig = MATmat.getLig();
    int iCol = MATmat.getCol();

    CMatrice<Type> result(iLig, iCol);

    for (uiLigLoop = 0; uiLigLoop < iLig; uiLigLoop++)
    {
        for (uiColLoop = 0; uiColLoop < iCol; uiColLoop++)
        {
            result.MATModifierElem(iScalaire * (MATmat.getElem(uiLigLoop, uiColLoop)), uiLigLoop, uiColLoop);
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
	unsigned int uiIniLoop, uiLigLoop, uiColLoop;

	char cTempSep = ' ';

	char cType[16];
	unsigned int uiNbLig;
	unsigned int uiNbCol;

	double dValue;

	std::ifstream IFSFlux(sPath);

	if (IFSFlux) {
		while (cTempSep != '=') {
			IFSFlux.get(cTempSep);
		}
		IFSFlux >> cType;

		cTempSep = ' ';
		while (cTempSep != '=') {
			IFSFlux.get(cTempSep);
		}
		IFSFlux >> uiNbLig;

		cTempSep = ' ';
		while (cTempSep != '=') {
			IFSFlux.get(cTempSep);
		}
		IFSFlux >> uiNbCol;

		iMATNbLig = uiNbLig;
		iMATNbCol = uiNbCol;

		ppTYPEMATMatrice = (Type**) new Type*[iMATNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

		for (uiIniLoop = 0; uiIniLoop < iMATNbCol; uiIniLoop++) {
			ppTYPEMATMatrice[uiIniLoop] = (Type*)new Type[iMATNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
		}

		cTempSep = ' ';
		while (cTempSep != '[') {
			IFSFlux.get(cTempSep);
		}
		IFSFlux.get(cTempSep);

		for (uiLigLoop = 0; uiLigLoop < iMATNbLig; uiLigLoop++)
		{
			for (uiColLoop = 0; uiColLoop < iMATNbCol; uiColLoop++)
			{
				IFSFlux >> dValue;
				MATModifierElem(dValue, uiLigLoop, uiColLoop);
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
	unsigned int uiIniLoop, uiLigLoop, uiColLoop;

	iMATNbCol = iColonne;
	iMATNbLig = iLigne;

	ppTYPEMATMatrice = (Type**) new Type*[iMATNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

	for (uiIniLoop = 0; uiIniLoop < iMATNbCol; uiIniLoop++) {
		ppTYPEMATMatrice[uiIniLoop] = (Type*)new Type[iMATNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
	}

	for (uiLigLoop = 0; uiLigLoop < iMATNbLig; uiLigLoop++)
	{
		for (uiColLoop = 0; uiColLoop < iMATNbCol; uiColLoop++)
		{
			ppTYPEMATMatrice[uiColLoop][uiLigLoop] = 0;
		}
	}
}


template<typename Type>
CMatrice<Type>::CMatrice(int iLigne, int iColonne, Type* pTypeTableauElems)
{
	unsigned int uiIniLoop, uiLigLoop, uiColLoop;

	iMATNbCol = iColonne;
	iMATNbLig = iLigne;

	ppTYPEMATMatrice = (Type**) new Type*[iMATNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

	for (uiIniLoop = 0; uiIniLoop < iMATNbCol; uiIniLoop++) {
		ppTYPEMATMatrice[uiIniLoop] = (Type*)new Type[iMATNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
	}

	for (uiLigLoop = 0; uiLigLoop < iMATNbLig; uiLigLoop++)
	{
		for (uiColLoop = 0; uiColLoop < iMATNbCol; uiColLoop++)
		{
			ppTYPEMATMatrice[uiColLoop][uiLigLoop] = pTypeTableauElems[uiLigLoop*iMATNbCol + uiColLoop];
		}
	}
}

template<typename Type>
CMatrice<Type>::CMatrice(const CMatrice<Type>& MATParam)
{
	if (MATParam.ppTYPEMATMatrice) {

		unsigned int uiIniLoop, uiLigLoop, uiColLoop;

		iMATNbCol = MATParam.iMATNbCol;
		iMATNbLig = MATParam.iMATNbLig;

		ppTYPEMATMatrice = (Type**) new Type*[iMATNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

		for (uiIniLoop = 0; uiIniLoop < iMATNbCol; uiIniLoop++) {
			ppTYPEMATMatrice[uiIniLoop] = (Type*)new Type[iMATNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
		}

		for (uiLigLoop = 0; uiLigLoop < iMATNbLig; uiLigLoop++)
		{
			for (uiColLoop = 0; uiColLoop < iMATNbCol; uiColLoop++)
			{
				ppTYPEMATMatrice[uiColLoop][uiLigLoop] = MATParam.ppTYPEMATMatrice[uiColLoop][uiLigLoop];
			}
		}
	}
}

template<typename Type>
CMatrice<Type>::~CMatrice()
{
	if (ppTYPEMATMatrice) {

		unsigned int uiLoop;

		for (uiLoop = 0; uiLoop < iMATNbCol; uiLoop++) {
			delete[] ppTYPEMATMatrice[uiLoop];
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
	unsigned int uiIniLoop, uiLigLoop, uiColLoop;
	int iTempNbLig = iMATNbLig + 1;

	Type** ppTypeTempMatrice;

	ppTypeTempMatrice = (Type**) new Type*[iMATNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

	for (uiIniLoop = 0; uiIniLoop < iMATNbCol; uiIniLoop++) {
		ppTypeTempMatrice[uiIniLoop] = (Type*)new Type[iTempNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
	}

	for (uiLigLoop = 0; uiLigLoop < iMATNbLig; uiLigLoop++)
	{
		for (uiColLoop = 0; uiColLoop < iMATNbCol; uiColLoop++)
		{
			ppTypeTempMatrice[uiColLoop][uiLigLoop] = ppTYPEMATMatrice[uiColLoop][uiLigLoop];
		}
	}

	delete(ppTYPEMATMatrice);

	ppTYPEMATMatrice = ppTypeTempMatrice;

	iMATNbLig++;
}

template<typename Type>
void CMatrice<Type>::MATAjoutColonne()
{
	unsigned int uiIniLoop, uiColLoop;
	int iTempNbCol = iMATNbCol + 1;

	Type** ppTypeTempMatrice;

	ppTypeTempMatrice = (Type**) new Type*[iTempNbCol];//Creer un tableau de tableau, cela represente le nombre de colonnes.

	for (uiIniLoop = 0; uiIniLoop < iTempNbCol; uiIniLoop++) {
		ppTypeTempMatrice[uiIniLoop] = (Type*)new Type[iMATNbLig];//Creer un tableau de Type sur chaque colonne, cela represente les lignes.
	}

	for (uiColLoop = 0; uiColLoop < iMATNbCol; uiColLoop++)
	{
		ppTypeTempMatrice[uiColLoop] = ppTYPEMATMatrice[uiColLoop];
	}

	delete(ppTYPEMATMatrice);

	ppTYPEMATMatrice = ppTypeTempMatrice;

	iMATNbCol++;
}

template<typename Type>
void CMatrice<Type>::MATAfficherMatrice()
{
	unsigned int uiLigLoop, uiColLoop;

	for (uiLigLoop = 0; uiLigLoop < iMATNbLig; uiLigLoop++)
	{
		for (int uiColLoop = 0; uiColLoop < iMATNbCol; uiColLoop++)
		{
			std::cout << ppTYPEMATMatrice[uiColLoop][uiLigLoop] << " ";
		}
		std::cout << "\n";
	}
}