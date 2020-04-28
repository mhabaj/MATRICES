#include "Ccalcul_matrice.h"

/**
*	Fonction principale main
*   Binome: ALHABAJ Mahmod / BELDA Tom
*	Projet: Matrices
*	Polytech: Tours DI3GR1
*	Professeur Referent: V. T'kindt
*
*/


int main(unsigned int argc, char* argv[])
{
	unsigned int uiBoucle_arguments, uiNombre_matrice;
	unsigned int uiDecalage = 1;
	
	double dValeur;

	uiNombre_matrice = argc - 1;

	Ccalcul_matrice<double>* CCMMatrices = new Ccalcul_matrice<double>[uiNombre_matrice];

	for (uiBoucle_arguments = 1; uiBoucle_arguments < argc; uiBoucle_arguments++) {
		try {
			CCMMatrices[uiBoucle_arguments - uiDecalage] = *new Ccalcul_matrice<double>(argv[uiBoucle_arguments]);
		}
		catch (Cexception e) {
			std::cout << "Fichier : " << argv[uiBoucle_arguments] << " : ";
			e.EXCafficher_erreur();
			uiDecalage++;
			uiNombre_matrice--;
		}
	}

	if (uiNombre_matrice > 0) {

		for (uiBoucle_arguments = 0; uiBoucle_arguments < uiNombre_matrice; uiBoucle_arguments++) {
			std::cout << "Matrice " << uiBoucle_arguments + 1 << " : ";
			std::cout << CCMMatrices[uiBoucle_arguments] << "\n";
		}

		std::cout << "Rentrer la valeur du scalaire :\n";
		
			if (std::cin >> dValeur) {
				
				std::cout << "Valeur Scalaire Rentree: " << dValeur << std::endl;
				for (uiBoucle_arguments = 0; uiBoucle_arguments < uiNombre_matrice; uiBoucle_arguments++) {
					std::cout << "Matrice " << uiBoucle_arguments + 1 << " * " << dValeur << " = " << CCMMatrices[uiBoucle_arguments] * dValeur << "\n";
				}

				std::cout << "--------------------------------------\n";

				for (uiBoucle_arguments = 0; uiBoucle_arguments < uiNombre_matrice; uiBoucle_arguments++) {
					try {
						std::cout << "Matrice " << uiBoucle_arguments + 1 << " / " << dValeur << " = " << CCMMatrices[uiBoucle_arguments] / dValeur << "\n";
					}
					catch (Cexception e) {
						std::cout << "Matrice " << uiBoucle_arguments + 1 << " : ";
						e.EXCafficher_erreur();
					}
				}

				std::cout << "--------------------------------------\n";

				Ccalcul_matrice<double> CMMAddition(CCMMatrices[0]);

				for (uiBoucle_arguments = 1; uiBoucle_arguments < uiNombre_matrice; uiBoucle_arguments++) {
					try {
						CMMAddition = CMMAddition + CCMMatrices[uiBoucle_arguments];
					}
					catch (Cexception e) {
						std::cout << "Matrice " << uiBoucle_arguments + 1 << " : ";
						e.EXCafficher_erreur();
					}
				}

				std::cout << "Resultat de l'addition : " << CMMAddition << "\n";

				std::cout << "--------------------------------------\n";

				Ccalcul_matrice<double> CMMCalcul(CCMMatrices[0]);

				for (uiBoucle_arguments = 1; uiBoucle_arguments < uiNombre_matrice; uiBoucle_arguments++) {
					try {
						if (uiBoucle_arguments % 2 == 0)
							CMMCalcul = CMMCalcul + CCMMatrices[uiBoucle_arguments];
						else
							CMMCalcul = CMMCalcul - CCMMatrices[uiBoucle_arguments];
					}
					catch (Cexception e) {
						std::cout << "Matrice " << uiBoucle_arguments + 1 << " : ";
						e.EXCafficher_erreur();
					}
				}

				std::cout << "Resultat du calcul M1-M2+M3....(Seulement matrices valides) : " << CMMCalcul << "\n";

				std::cout << "--------------------------------------\n";

				Ccalcul_matrice<double> CMMMultiplication(CCMMatrices[0]);

				for (uiBoucle_arguments = 1; uiBoucle_arguments < uiNombre_matrice; uiBoucle_arguments++) {
					try {
						CMMMultiplication = CMMMultiplication * CCMMatrices[uiBoucle_arguments];
					}
					catch (Cexception e) {
						std::cout << "Matrice " << uiBoucle_arguments + 1 << " : ";
						e.EXCafficher_erreur();
					}
				}

				std::cout << "Resultat de la multiplication : " << CMMMultiplication << "\n";
			}
			else {
				std::cout << "Erreur : Argument invalide en parametre\n";
				exit(ARGUMENT_INVALIDE);
			}
		
			delete[] CCMMatrices;
			
	
	}
	return 0;
}