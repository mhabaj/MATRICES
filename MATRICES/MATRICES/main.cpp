#include "CCalculMatrice.h"
#include "CMatrice.h"

int main()
{
	double tab1[4] = { 1, 2, 3, 4 };
	CMatrice<double> m1(2, 2, tab1);
	std::cout << "M1 :\n";
	m1.MATAfficherMatrice();
	std::cout << "-------------------------------------\n";
	CMatrice<double> m2(m1);
	std::cout << "M2 = M1 :\n";
	m2.MATAfficherMatrice();
	std::cout << "-------------------------------------\n";
	m2.MATModifierElem(7, 1, 0);
	std::cout << "Modifie M2 -> 3 = 7 :\n";
	m2.MATAfficherMatrice();
	std::cout << "-------------------------------------\n";
	std::cout << "M1 :\n";
	m1.MATAfficherMatrice();
	std::cout << "/////////////////////////////////////\n";

	std::cout << "M2 * 2.5 :\n";
	(m2*2.5).MATAfficherMatrice();
	std::cout << "-------------------------------------\n";
	std::cout << "1.7 * M2 :\n";
	(1.7*m2).MATAfficherMatrice();
	std::cout << "-------------------------------------\n";
	std::cout << "M2 / 3 :\n";
	(m2 / 3).MATAfficherMatrice();
	std::cout << "/////////////////////////////////////\n";

	CMatrice<double> m3("C:/Users/belda_mjro20o/Desktop/mat.txt");
	std::cout << "M3 importe de C:/Users/belda_mjro20o/Desktop/mat.txt :\n";
	m3.MATAfficherMatrice();
	std::cout << "/////////////////////////////////////\n";

	std::cout << "Transposée de M3 :\n";
	(CCalculMatrice::transpose(m3)).MATAfficherMatrice();
	std::cout << "-------------------------------------\n";
	std::cout << "M1 + M2 :\n";
	(CCalculMatrice::addition(m1, m2)).MATAfficherMatrice();
	std::cout << "-------------------------------------\n";
	std::cout << "M1 - M2 :\n";
	(CCalculMatrice::soustraction(m1, m2)).MATAfficherMatrice();
	std::cout << "-------------------------------------\n";
	std::cout << "M1 * M2 :\n";
	(CCalculMatrice::multiplication(m1, m2)).MATAfficherMatrice();
	return 0;
}