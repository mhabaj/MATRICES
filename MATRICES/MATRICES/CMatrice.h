#pragma once
#include <iostream> 
#include <string>   
using namespace std;

template <typename Type>

class CMatrice
{

private:
	int inbCol;
	int inbLig;
	Type** ptrptrMatrice;


public:

	CMatrice();
	CMatrice(string sPath);
	CMatrice(int iLigne, int iColonne);
	CMatrice(int iLigne, int iColonne, Type* pTypeTableauElems);
	CMatrice(Type** MATParam);
	CMatrice operator *(CMatrice& MATParam);
	CMatrice operator /(CMatrice& MATParam);
	void MATModifierElem(Type elem, int ligne, int colonne);
	void MATAjoutLigne();
	void MATAjoutColonne();
	void MATAfficherMatrice();
	



};