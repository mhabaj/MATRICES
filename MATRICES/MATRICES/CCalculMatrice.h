/**
 * \file Ccalcul_matrice.h
 * \brief Operations de calculs complexes sur Matrices
 * \author ALHABAJ Mahmod, BELDA Tom
 * \version 0.1
 * \date 22 avril 2020
 */
#pragma once

#include "CMatrice.h"

 /** \class Ccalcul_matrice
  * \brief Classe de gestion d'operations de calculs complexes sur Matrices
  * 
  *	Permet d'effectuer des operations complexes sur des objets Cmatrice
  */
template <class Ttype> class Ccalcul_matrice : public Cmatrice<Ttype>
{
public:
	/**
	 * \fn Cmatrice()
	 * \brief Constructeur par default.
	 *
	 * Alloue en mémoire l'espace d'un matrice de dimension 1,1.
	 */
	Ccalcul_matrice(){};

	/**
	 * \fn Cmatrice(const char* pcChemin)
	 * \brief Constructeur via fichier.
	 *
	 * \param pcChemin Fichier source de la matrice a creer.
	 * \exception ERREUR_FICHIER Erreur fichier en cas de chemin non valide
	 */
	Ccalcul_matrice(const char* pcChemin) : Cmatrice<Ttype>(pcChemin) {}

	/**
	 * \fn Cmatrice(int uiLigne, int uiColonne)
	 * \brief Constructeur avec dimensions.
	 *
	 * \param uiLigne Nombres de lignes.
	 * \param uiColonne Nombre de collones.
	 * \exception ERREUR_DIMENSIONS Dimensions Cmatrice non valide
	 */
	Ccalcul_matrice(unsigned int uiLigne, unsigned int uiColonne)  : Cmatrice<Ttype>(uiLigne, uiColonne) {}

	/**
	 * \fn Cmatrice(int uiLigne, int uiColonne, Ttype* pTTableau_elements)
	 * \brief Constructeur avec dimensions et contenus.
	 * \pre Le nombre d'elements du tableau doit etre egale a uiLigne * uiColonne.
	 *
	 * \param uiLigne Nombres de lignes.
	 * \param uiColonne Nombre de collones.
	 * \param pTTableau_elements tableau des éléments a mettre dans la matrice.
	 * \exception ERREUR_DIMENSIONS Dimensions Cmatrice non valide
	 */
	Ccalcul_matrice(unsigned int uiLigne, unsigned int uiColonne, Ttype* pTTableau_elements) : Cmatrice<Ttype>(uiLigne, uiColonne, pTTableau_elements) {}

	/**
	 * \fn Cmatrice(const Cmatrice<Ttype>& MATparam)
	 * \brief Constructeur de recopie.
	 *
	 * \param MATparam Matrice a recopie.
	 */
	Ccalcul_matrice(const Cmatrice<Ttype>& MATparam) : Cmatrice<Ttype>(MATparam) {}

	/**
	 * \fn transpose(Cmatrice<Ttype> mat)
	 * \brief Calculer la transpose de la matrice
	 * 
	 * \return objet Cmatrice<Ttype> representant le resultat de l'operation
	 */
	Ccalcul_matrice<Ttype> transpose();

	/**
	 * \fn operator*(const double dScalaire)
	 * \brief surcharge de l'operateur * (Multiplication par un scalaire)
	 *
	 * \param dScalaire Scalaire a multiplier
	 * \return objet Cmatrice<Ttype> resultat de la multiplication
	 */
	Ccalcul_matrice<Ttype> operator*(const double dScalaire);

	/**
	 * \fn operator/(const double dScalaire)
	 * \brief surcharge de l'operateur / (Division par un scalaire)
	 *
	 * \param dScalaire Scalaire divisant la Cmatrice
	 * \return objet Cmatrice<Ttype> resultat de la multiplication
	 */
	Ccalcul_matrice<Ttype> operator/(const double dScalaire);

};

template<class Ttype>
Ccalcul_matrice<Ttype> operator*(const double dScalaire, const Ccalcul_matrice<Ttype>& MATparam)//Supporte *
{
	unsigned int uiBoucle_ligne, uiBoucle_colonne;

	unsigned int uiLigne = MATparam.MATlire_nombre_lignes();
	unsigned int uiColonne = MATparam.MATlire_nombre_colonnes();

	Ccalcul_matrice<Ttype> CMTresult(uiLigne, uiColonne);

	for (uiBoucle_ligne = 0; uiBoucle_ligne < uiLigne; uiBoucle_ligne++)
	{
		for (uiBoucle_colonne = 0; uiBoucle_colonne < uiColonne; uiBoucle_colonne++)
		{
			CMTresult.MATmodifier_element(dScalaire * (MATparam.MATlire_element(uiBoucle_ligne, uiBoucle_colonne)), uiBoucle_ligne, uiBoucle_colonne);
		}
	}

	return CMTresult;
}

template<class Ttype>
Ccalcul_matrice<Ttype> Ccalcul_matrice<Ttype>::operator*(const double dScalaire)//Justifier choix multiplication//Supporte *
{
	unsigned int uiBoucle_ligne, uiBoucle_colonne;

	Ccalcul_matrice<Ttype> CMTresult(this->MATlire_nombre_lignes(), this->MATlire_nombre_colonnes());

	for (uiBoucle_ligne = 0; uiBoucle_ligne < this->MATlire_nombre_lignes(); uiBoucle_ligne++)
	{
		for (uiBoucle_colonne = 0; uiBoucle_colonne < this->MATlire_nombre_colonnes(); uiBoucle_colonne++)
		{
			CMTresult.MATmodifier_element((this->MATlire_element(uiBoucle_ligne, uiBoucle_colonne)) * dScalaire, uiBoucle_ligne, uiBoucle_colonne);
		}
	}

	return CMTresult;
}

template<class Ttype>
Ccalcul_matrice<Ttype> Ccalcul_matrice<Ttype>::operator/(const double dScalaire) //Supporte /
{
	if (dScalaire == 0) {
		Cexception EXCerror;
		EXCerror.EXCmodifier_valeur(DIVISION_PAR_0);//Division par 0 impossible
		throw EXCerror;
	}
	else {
		unsigned int uiBoucle_ligne, uiBoucle_colonne;

		Ccalcul_matrice<Ttype> CMTresult(this->MATlire_nombre_lignes(), this->MATlire_nombre_colonnes());

		for (uiBoucle_ligne = 0; uiBoucle_ligne < this->MATlire_nombre_lignes(); uiBoucle_ligne++)
		{
			for (uiBoucle_colonne = 0; uiBoucle_colonne < this->MATlire_nombre_colonnes(); uiBoucle_colonne++)
			{
				CMTresult.MATmodifier_element((this->MATlire_element(uiBoucle_ligne, uiBoucle_colonne)) / dScalaire, uiBoucle_ligne, uiBoucle_colonne);
			}
		}

		return CMTresult;
	}
}

template<class Ttype>
Ccalcul_matrice<Ttype> operator+(const Ccalcul_matrice<Ttype> CMTmat1, const Ccalcul_matrice<Ttype> CMTmat2)//Supporte +
{
	if (CMTmat1.MATlire_nombre_colonnes() != CMTmat2.MATlire_nombre_colonnes() || CMTmat1.MATlire_nombre_lignes() != CMTmat2.MATlire_nombre_lignes()) {
		Cexception EXCerror;
		EXCerror.EXCmodifier_valeur(ERREUR_DIMENSIONS);//Les dimensions des matrices ne permettent pas l'additon
		throw EXCerror;
	}
	else {
		unsigned int uiBoucle_ligne, uiBoucle_colonne;

		Ccalcul_matrice<Ttype> CMTresult(CMTmat1.MATlire_nombre_lignes(), CMTmat1.MATlire_nombre_colonnes());

		for (uiBoucle_ligne = 0; uiBoucle_ligne < CMTmat1.MATlire_nombre_lignes(); uiBoucle_ligne++)
		{
			for (uiBoucle_colonne = 0; uiBoucle_colonne < CMTmat1.MATlire_nombre_colonnes(); uiBoucle_colonne++)
			{
				CMTresult.MATmodifier_element(CMTmat1.MATlire_element(uiBoucle_ligne, uiBoucle_colonne) + CMTmat2.MATlire_element(uiBoucle_ligne, uiBoucle_colonne), uiBoucle_ligne, uiBoucle_colonne);
			}
		}
		return CMTresult;
	}
}

template<class Ttype>
Ccalcul_matrice<Ttype> operator-(const Ccalcul_matrice<Ttype> CMTmat1, const Ccalcul_matrice<Ttype> CMTmat2)//Supporte -
{
	if (CMTmat1.MATlire_nombre_colonnes() != CMTmat2.MATlire_nombre_colonnes() || CMTmat1.MATlire_nombre_lignes() != CMTmat2.MATlire_nombre_lignes()) {
		Cexception EXCerror;
		EXCerror.EXCmodifier_valeur(ERREUR_DIMENSIONS);//Les dimensions des matrices ne permettent pas la soustraction
		throw EXCerror;
	}
	else {
		unsigned int uiBoucle_ligne, uiBoucle_colonne;

		Cmatrice<Ttype> CMTresult(CMTmat1.MATlire_nombre_lignes(), CMTmat1.MATlire_nombre_colonnes());

		for (uiBoucle_ligne = 0; uiBoucle_ligne < CMTmat1.MATlire_nombre_lignes(); uiBoucle_ligne++)
		{
			for (uiBoucle_colonne = 0; uiBoucle_colonne < CMTmat1.MATlire_nombre_colonnes(); uiBoucle_colonne++)
			{
				CMTresult.MATmodifier_element(CMTmat1.MATlire_element(uiBoucle_ligne, uiBoucle_colonne) - CMTmat2.MATlire_element(uiBoucle_ligne, uiBoucle_colonne), uiBoucle_ligne, uiBoucle_colonne);
			}
		}
		return CMTresult;
	}
}

template<class Ttype>
Ccalcul_matrice<Ttype> operator*(const Ccalcul_matrice<Ttype> CMTmat1, const Ccalcul_matrice<Ttype> CMTmat2)//supporte *
{
	if (CMTmat1.MATlire_nombre_colonnes() != CMTmat2.MATlire_nombre_lignes()) {
		Cexception EXCerror;
		EXCerror.EXCmodifier_valeur(ERREUR_DIMENSIONS);//Les dimensions des matrices ne permettent pas la multiplication
		throw EXCerror;
	}
	else {
		unsigned int uiBoucle_ligne, uiBoucle_colonne, uiBoucle_calcul;

		Cmatrice<Ttype> CMTresult(CMTmat1.MATlire_nombre_lignes(), CMTmat2.MATlire_nombre_colonnes());

		for (uiBoucle_ligne = 0; uiBoucle_ligne < CMTresult.MATlire_nombre_lignes(); uiBoucle_ligne++)
		{
			for (uiBoucle_colonne = 0; uiBoucle_colonne < CMTresult.MATlire_nombre_colonnes(); uiBoucle_colonne++)
			{
				CMTresult.MATmodifier_element(CMTmat1.MATlire_element(uiBoucle_ligne, 0) * CMTmat2.MATlire_element(0, uiBoucle_colonne), uiBoucle_ligne, uiBoucle_colonne);
				for (uiBoucle_calcul = 1; uiBoucle_calcul < CMTmat2.MATlire_nombre_lignes(); uiBoucle_calcul++)
				{
					CMTresult.MATmodifier_element(CMTmat1.MATlire_element(uiBoucle_ligne, uiBoucle_calcul) * CMTmat2.MATlire_element(uiBoucle_calcul, uiBoucle_colonne) + CMTresult.MATlire_element(uiBoucle_ligne, uiBoucle_colonne), uiBoucle_ligne, uiBoucle_colonne);
				}
			}
		}
		return CMTresult;
	}
}


template<class Ttype>
Ccalcul_matrice<Ttype> Ccalcul_matrice<Ttype>::transpose()
{
	unsigned int uiBoucle_ligne, uiBoucle_colonne;

	Cmatrice<Ttype> CMTresult(this->MATlire_nombre_colonnes(), this->MATlire_nombre_lignes());

	for (uiBoucle_ligne = 0; uiBoucle_ligne < CMTresult.MATlire_nombre_lignes(); uiBoucle_ligne++)
	{
		for (uiBoucle_colonne = 0; uiBoucle_colonne < CMTresult.MATlire_nombre_colonnes(); uiBoucle_colonne++)
		{
			CMTresult.MATmodifier_element(this->MATlire_element(uiBoucle_colonne, uiBoucle_ligne), uiBoucle_ligne, uiBoucle_colonne);
		}
	}
	return CMTresult;
}