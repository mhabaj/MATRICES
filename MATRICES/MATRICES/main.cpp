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
	std::cout << "M2 / 0 :\n";
	try {
		m2 / 0;
	}
	catch (Cexception e) {
		e.EXCaffiche_erreur();
	}
	std::cout << "/////////////////////////////////////\n";

	try {
		CMatrice<double> m3("C:/Users/belda_mijro20o/Desktop/mat.txt");
		std::cout << "/////////////////////////////////////\n";
	}
	catch (Cexception e) {
		e.EXCaffiche_erreur();
	}

	std::cout << "Transposee de M1 :\n";
	(CCalculMatrice::transpose(m1)).MATAfficherMatrice();
	std::cout << "-------------------------------------\n";
	std::cout << "M1 + M2 :\n";
	(CCalculMatrice::addition(m1, m2)).MATAfficherMatrice();
	std::cout << "-------------------------------------\n";
	std::cout << "M1 - M2 :\n";
	(CCalculMatrice::soustraction(m1, m2)).MATAfficherMatrice();
	std::cout << "-------------------------------------\n";
	std::cout << "M1 * M2 :\n";
	(CCalculMatrice::multiplication(m1, m2)).MATAfficherMatrice();
	std::cout << "/////////////////////////////////////\n";

	int tab2[4] = { 2, 7, 3, 9 };
	CMatrice<int> m4(2, 2, tab2);
	m4 = m4 * 1.5;
	m4.MATAfficherMatrice();
	std::cout << "-------------------------------------\n";
	int tab3[2] = { 5, 1 };
	m4.MATAjoutLigne(tab3);
	m4.MATAfficherMatrice();
	std::cout << "-------------------------------------\n";
	int tab4[3] = {11, 6, 4};
	m4.MATAjoutColonne(tab4);
	m4.MATAfficherMatrice();
	std::cout << "-------------------------------------\n";

	try {
		CMatrice<double> m5(0, 0);
	}
	catch (Cexception e) {
		e.EXCaffiche_erreur();
	}

	return 0;
}