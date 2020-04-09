#pragma once
#include "CMatrice.h"

class CCalculMatrice
{
private:
	CCalculMatrice() {};

public:
	template <typename Type>
	static CMatrice<Type>& transpose(CMatrice<Type> mat);
};

template<typename Type>
CMatrice<Type>& CCalculMatrice::transpose(CMatrice<Type> mat)
{
	CMatrice<Type> result(mat.getCol(), mat.getLig());
	for (int iloopLig = 0; iloopLig < result.getLig(); iloopLig++)
	{
		for (int iloopCol = 0; iloopCol < result.getCol(); iloopCol++)
		{
			result.MATModifierElem(mat.getElem(iloopCol, iloopLig), iloopLig, iloopCol);
		}
	}
	result.MATAfficherMatrice();
	return result;
}

int main()
{
	double tab1[4] = { 1, 2, 3, 4 };
	CMatrice<double> m1(2, 2, tab1);
	m1.MATAfficherMatrice();
	std::cout << "-------------------------------------\n";
	CMatrice<double> m2(m1);
	m2.MATAfficherMatrice();
	m1.MATModifierElem(0, 0, 0);
	std::cout << "/////////////////////////////////////\n";
	m1.MATAfficherMatrice();
	std::cout << "-------------------------------------\n";
	m2.MATAfficherMatrice();
	std::cout << "/////////////////////////////////////\n";
	CMatrice<double> m3;
	m3 = m2*2;
	m2.MATAfficherMatrice();
	std::cout << "-------------------------------------\n";
	m3.MATAfficherMatrice();
	std::cout << "/////////////////////////////////////\n";
	CMatrice<double> m12("C:/Users/belda_mjro20o/Desktop/mat.txt");
	m12.MATAfficherMatrice();
	//CCalculMatrice::transpose<double>(m1).MATAfficherMatrice();
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
=======
	static CMatrice<Type> transpose(CMatrice<Type> mat);
};
>>>>>>> parent of c16fd76... ez constructor
