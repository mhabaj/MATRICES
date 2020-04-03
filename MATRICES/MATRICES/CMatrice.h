#pragma once
#include <iostream> 
#include <string>   
using namespace std;

template <typename Type>

class CMatrice
{

private:
	int iMATnbCol;
	int iMATnbLig;
	Type** ppTYPEMATMatrice;

public:
	CMatrice();
	CMatrice(string sPath);
	CMatrice(int iLigne, int iColonne);
	CMatrice(int iLigne, int iColonne, Type* pTypeTableauElems);//Pre condition : taille de pTypeTableauElems = a iLigne*iColonne
	CMatrice(Type** MATParam);
	CMatrice operator *(CMatrice& MATParam);
	CMatrice operator /(CMatrice& MATParam);
	void MATModifierElem(Type elem, int ligne, int colonne);
	void MATAjoutLigne();
	void MATAjoutColonne();
	void MATAfficherMatrice();

};