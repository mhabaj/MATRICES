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
	CMatrice(Type** paramMat);
	void MatModifierElem(Type elem, int ligne, int colonne);
	void MatAjoutLigne();
	void MatAjoutColonne();




};