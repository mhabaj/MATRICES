#include "CCalculMatrice.h"
#include "CMatrice.h"

int main()
{
	double tab1[4] = { 1, 2, 3, 4 };
	Cmatrice<double> m1(2, 2, tab1);
	std::cout << "M1 :\n";
	std::cout << m1 << "\n";
	std::cout << "-------------------------------------\n";
	Cmatrice<double> m2(m1);
	std::cout << "M2 = M1 :\n";
	std::cout << m2 << "\n";
	std::cout << "-------------------------------------\n";
	m2.MATmodifier_element(7, 1, 0);
	std::cout << "Modifie M2 -> 3 = 7 :\n";
	std::cout << m2 << "\n";
	std::cout << "-------------------------------------\n";
	std::cout << "M1 :\n";
	std::cout << m1 << "\n";
	std::cout << "/////////////////////////////////////\n";

	CCalculMatrice<double> m3("C:/Users/belda_mjro20o/Desktop/mat.txt");
	std::cout << "M3 : \n" << m3 << "\n";
	std::cout << "/////////////////////////////////////\n";
	
	std::cout << "M3 * 2.5 :\n" << (m3*2.5) << "\n";
	std::cout << "-------------------------------------\n";
	std::cout << "1.7 * M3 :\n" << (1.7*m3) << "\n";
	std::cout << "-------------------------------------\n";
	std::cout << "M3 / 4 :\n" << (m3 / 4) << "\n";
	std::cout << "/////////////////////////////////////\n";

	std::cout << "Transposee de M3 :\n";
	std::cout << m3.transpose() << "\n";
	std::cout << "-------------------------------------\n";
	std::cout << "M3 + M3 :\n";
	std::cout << m3 + m3 << "\n";
	std::cout << "-------------------------------------\n";
	std::cout << "M3 - M3 :\n";
	std::cout << m3 - m3 << "\n";
	std::cout << "-------------------------------------\n";
	std::cout << "M3 * M3 :\n";
	std::cout << m3 * m3 << "\n";
	std::cout << "/////////////////////////////////////\n";

	double tab2[4] = { 2, 7, 3, 9 };
	CCalculMatrice<double> m4(2, 2, tab2);
	m4 = m4 * 1.5;
	std::cout << m4 << "\n";
	std::cout << "-------------------------------------\n";
	double tab3[2] = { 5, 1 };
	m4.MATajouter_ligne(tab3);
	std::cout << m4 << "\n";
	std::cout << "-------------------------------------\n";
	double tab4[3] = {11, 6, 4};
	m4.MATajouter_colonne(tab4);
	std::cout << m4 << "\n";
	std::cout << "-------------------------------------\n";
	m4.MATsupprimer_ligne(1);
	std::cout << m4 << "\n";
	std::cout << "-------------------------------------\n";
	m4.MATsupprimer_colonne(1);
	std::cout << m4 << "\n";
	std::cout << "-------------------------------------\n";

	CCalculMatrice<CCalculMatrice<double>> mu(2, 1);
	mu.MATmodifier_element(m3, 0, 0);
	mu.MATmodifier_element(m4, 1, 0);
	std::cout << "MU :\n";
	std::cout << mu << "\n-------------------------------------\nMU * 3:\n";
	std::cout << mu * 3 << "\n-------------------------------------\n3 * MU:\n";
	std::cout << 3 * mu << "\n-------------------------------------\nMU / 4:\n";
	std::cout << mu / 4 << "\n-------------------------------------\nMU + MU:\n";
	std::cout << mu + mu << "\n-------------------------------------\nMU - MU:\n";
	std::cout << mu - mu << "\n-------------------------------------\nMU * MU:\n";
	try {
		std::cout << mu * mu;
	}
	catch (Cexception e) {
		e.EXCaffiche_erreur();
	}

	std::cout << "-------------------------------------\nM3 + M4 :\n";

	try {
		std::cout << m3 + m4 << "\n";
	}
	catch (Cexception e) {
		e.EXCaffiche_erreur();
	}
	return 0;
}