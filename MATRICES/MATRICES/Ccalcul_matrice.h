/**
 * \file Ccalcul_matrice.h
 * \brief Operations de calculs complexes sur Matrices
 * \author ALHABAJ Mahmod, BELDA Tom
 * \version 0.1
 * \date 22 avril 2020
 */
#pragma once
/*
Modules internes : */
#include "Cmatrice.h"

 /** 
  * \class Ccalcul_matrice
  * \brief Classe de gestion d'operations de calculs complexes sur Matrices
  * 
  *	Permet d'effectuer des operations complexes sur des objets d'origine Cmatrice
  */
template <class Ttype> class Ccalcul_matrice : public Cmatrice<Ttype>
{
public:
	/**
	 * \fn Ccalcul_matrice()
	 * \brief Constructeur par default.
	 *
	 * Alloue en mémoire l'espace d'un matrice de dimension 1,1.
	 */
	Ccalcul_matrice(){}

	/**
	 * \fn Ccalcul_matrice(const char* pcChemin)
	 * \brief Constructeur via fichier.
	 *
	 * \param pcChemin Fichier source de la matrice a creer.
	 * \exception ERREUR_FICHIER Erreur fichier en cas de chemin non valide
	 */
	Ccalcul_matrice(const char* pcChemin) : Cmatrice<Ttype>(pcChemin) {}

	/**
	 * \fn Ccalcul_matrice(int uiLigne, int uiColonne)
	 * \brief Constructeur avec dimensions.
	 *
	 * \param uiLigne Nombres de lignes.
	 * \param uiColonne Nombre de collones.
	 * \exception ERREUR_DIMENSIONS Dimensions Cmatrice non valide
	 */
	Ccalcul_matrice(unsigned int uiLigne, unsigned int uiColonne)  : Cmatrice<Ttype>(uiLigne, uiColonne) {}

	/**
	 * \fn Ccalcul_matrice(int uiLigne, int uiColonne, Ttype* pTTableau_elements)
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
	 * \fn Ccalcul_matrice(const Cmatrice<Ttype>& MATparam)
	 * \brief Constructeur de recopie.
	 *
	 * \param MATparam Matrice a recopie.
	 */
	Ccalcul_matrice(const Cmatrice<Ttype>& MATparam) : Cmatrice<Ttype>(MATparam) {}


	/**
	 * \fn CCMtranspose(Cmatrice<Ttype> mat)
	 * \brief Calculer la transpose de la matrice
	 * 
	 * \return objet Cmatrice<Ttype> representant le resultat de l'operation
	 */
	Ccalcul_matrice<Ttype> CCMtranspose();

	/**
	 * \fn operator*(const double dScalaire)
	 * \brief surcharge de l'operateur * (Multiplication par un scalaire)
	 * \pre il faut que le Ttype de la matrice supporte la multiplication par un scalaire
	 *
	 * \param dScalaire Scalaire a multiplier
	 * \return objet Cmatrice<Ttype> resultat de la multiplication
	 */
	Ccalcul_matrice<Ttype> operator*(const double dScalaire);

	/**
	 * \fn operator/(const double dScalaire)
	 * \brief surcharge de l'operateur / (Division par un scalaire)
	 * \pre il faut que le Ttype de la matrice supporte la division par un scalaire
	 *
	 * \param dScalaire Scalaire divisant la Cmatrice
	 * \return objet Cmatrice<Ttype> resultat de la division
	 */
	Ccalcul_matrice<Ttype> operator/(const double dScalaire);

	/**
	 * \fn operator+(const Ccalcul_matrice<Ttype> CCMmat)
	 * \brief surcharge de l'operateur + (addition entre matrices)
	 * \pre il faut que le Ttype de la matrice supporte l'addition par un autre Ttype
	 *
	 * \param matrice de l'addition
	 * \return objet Cmatrice<Ttype> resultat de l'addition
	 */
	Ccalcul_matrice<Ttype> operator+(const Ccalcul_matrice<Ttype> CCMmat);

	/**
	 * \fn operator-(const Ccalcul_matrice<Ttype> CCMmat)
	 * \brief surcharge de l'operateur - (soustraction entre matrices)
	 * \pre il faut que le Ttype de la matrice supporte la soustraction par un autre Ttype
	 *
	 * \param matrice de la soustraction
	 * \return objet Cmatrice<Ttype> resultat de la soustraction
	 */
	Ccalcul_matrice<Ttype> operator-(const Ccalcul_matrice<Ttype> CCMmat);

	/**
	 * \fn operator*(const Ccalcul_matrice<Ttype> CCMmat)
	 * \brief surcharge de l'operateur * (multiplication entre matrices)
	 * \pre il faut que le Ttype de la matrice supporte la multiplication par un autre Ttype
	 *
	 * \param matrice de la multiplication
	 * \return objet Cmatrice<Ttype> resultat de la multiplication
	 */
	Ccalcul_matrice<Ttype> operator*(const Ccalcul_matrice<Ttype> CCMmat);

};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * \fn operator*(const double dScalaire, const Ccalcul_matrice<Ttype>& MATparam)
 * \brief surcharge de l'operateur * (Multiplication par un scalaire)
 * \pre il faut que le Ttype de la matrice supporte la multiplication par un scalaire
 *
 * \param dScalaire Scalaire a multiplier
 * \param MATparam matrice a multiplier
 * \return objet Cmatrice<Ttype> resultat de la multiplication
 */
template<class Ttype>
Ccalcul_matrice<Ttype> operator*(const double dScalaire, const Ccalcul_matrice<Ttype>& MATparam)
{
	unsigned int uiBoucle_ligne, uiBoucle_colonne;

	//On recupère les dimensions de la matrice
	unsigned int uiLigne = MATparam.MATlire_nombre_lignes();
	unsigned int uiColonne = MATparam.MATlire_nombre_colonnes();

	//On creer une nouvelle matrice
	Ccalcul_matrice<Ttype> CCMresult(uiLigne, uiColonne);

	//On recopie chaque element en le multipliant par le scalaire
	for (uiBoucle_ligne = 0; uiBoucle_ligne < uiLigne; uiBoucle_ligne++)
	{
		for (uiBoucle_colonne = 0; uiBoucle_colonne < uiColonne; uiBoucle_colonne++)
		{
			CCMresult.MATmodifier_element(dScalaire * (MATparam.MATlire_element(uiBoucle_ligne, uiBoucle_colonne)), uiBoucle_ligne, uiBoucle_colonne);
		}
	}

	return CCMresult;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


template<class Ttype>
Ccalcul_matrice<Ttype> Ccalcul_matrice<Ttype>::operator*(const double dScalaire)//Justifier choix multiplication
{
	unsigned int uiBoucle_ligne, uiBoucle_colonne;

	//On creer une nouvelle matrice
	Ccalcul_matrice<Ttype> CCMresult(this->MATlire_nombre_lignes(), this->MATlire_nombre_colonnes());

	//On recopie chaque element en le multipliant par le scalaire
	for (uiBoucle_ligne = 0; uiBoucle_ligne < this->MATlire_nombre_lignes(); uiBoucle_ligne++)
	{
		for (uiBoucle_colonne = 0; uiBoucle_colonne < this->MATlire_nombre_colonnes(); uiBoucle_colonne++)
		{
			CCMresult.MATmodifier_element((this->MATlire_element(uiBoucle_ligne, uiBoucle_colonne)) * dScalaire, uiBoucle_ligne, uiBoucle_colonne);
		}
	}

	return CCMresult;
}

template<class Ttype>
Ccalcul_matrice<Ttype> Ccalcul_matrice<Ttype>::operator/(const double dScalaire)
{
	if (dScalaire == 0) {
		Cexception EXCerror;
		//Division par 0 impossible
		EXCerror.EXCmodifier_valeur(DIVISION_PAR_0);
		throw EXCerror;
	}
	else {
		unsigned int uiBoucle_ligne, uiBoucle_colonne;

		//On creer une nouvelle matrice
		Ccalcul_matrice<Ttype> CCMresult(this->MATlire_nombre_lignes(), this->MATlire_nombre_colonnes());

		//On recopie chaque element en le divisant par le scalaire
		for (uiBoucle_ligne = 0; uiBoucle_ligne < this->MATlire_nombre_lignes(); uiBoucle_ligne++)
		{
			for (uiBoucle_colonne = 0; uiBoucle_colonne < this->MATlire_nombre_colonnes(); uiBoucle_colonne++)
			{
				CCMresult.MATmodifier_element((this->MATlire_element(uiBoucle_ligne, uiBoucle_colonne)) / dScalaire, uiBoucle_ligne, uiBoucle_colonne);
			}
		}

		return CCMresult;
	}
}

template<class Ttype>
Ccalcul_matrice<Ttype> Ccalcul_matrice<Ttype>::operator+(const Ccalcul_matrice<Ttype> CCMmat)
{
	if (this->MATlire_nombre_colonnes() != CCMmat.MATlire_nombre_colonnes() || this->MATlire_nombre_lignes() != CCMmat.MATlire_nombre_lignes()) {
		Cexception EXCerror;
		//Les dimensions des matrices ne permettent pas l'additon
		EXCerror.EXCmodifier_valeur(ERREUR_DIMENSIONS);
		throw EXCerror;
	}
	else {
		unsigned int uiBoucle_ligne, uiBoucle_colonne;

		//On creer une nouvelle matrice
		Ccalcul_matrice<Ttype> CCMresult(this->MATlire_nombre_lignes(), this->MATlire_nombre_colonnes());

		//On recopie chaque element en le additionnant par l'element correspondant dans l'autre matrice
		for (uiBoucle_ligne = 0; uiBoucle_ligne < this->MATlire_nombre_lignes(); uiBoucle_ligne++)
		{
			for (uiBoucle_colonne = 0; uiBoucle_colonne < this->MATlire_nombre_colonnes(); uiBoucle_colonne++)
			{
				CCMresult.MATmodifier_element(this->MATlire_element(uiBoucle_ligne, uiBoucle_colonne) + CCMmat.MATlire_element(uiBoucle_ligne, uiBoucle_colonne), uiBoucle_ligne, uiBoucle_colonne);
			}
		}
		return CCMresult;
	}
}

template<class Ttype>
Ccalcul_matrice<Ttype> Ccalcul_matrice<Ttype>::operator-(const Ccalcul_matrice<Ttype> CCMmat)
{
	if (this->MATlire_nombre_colonnes() != CCMmat.MATlire_nombre_colonnes() || this->MATlire_nombre_lignes() != CCMmat.MATlire_nombre_lignes()) {
		Cexception EXCerror;
		//Les dimensions des matrices ne permettent pas la soustraction
		EXCerror.EXCmodifier_valeur(ERREUR_DIMENSIONS);
		throw EXCerror;
	}
	else {
		unsigned int uiBoucle_ligne, uiBoucle_colonne;

		//On creer une nouvelle matrice
		Cmatrice<Ttype> CCMresult(this->MATlire_nombre_lignes(), this->MATlire_nombre_colonnes());

		//On recopie chaque element en le soustrayant par l'element correspondant dans l'autre matrice
		for (uiBoucle_ligne = 0; uiBoucle_ligne < this->MATlire_nombre_lignes(); uiBoucle_ligne++)
		{
			for (uiBoucle_colonne = 0; uiBoucle_colonne < this->MATlire_nombre_colonnes(); uiBoucle_colonne++)
			{
				CCMresult.MATmodifier_element(this->MATlire_element(uiBoucle_ligne, uiBoucle_colonne) - CCMmat.MATlire_element(uiBoucle_ligne, uiBoucle_colonne), uiBoucle_ligne, uiBoucle_colonne);
			}
		}
		return CCMresult;
	}
}

template<class Ttype>
Ccalcul_matrice<Ttype> Ccalcul_matrice<Ttype>::operator*(const Ccalcul_matrice<Ttype> CCMmat)
{
	if (this->MATlire_nombre_colonnes() != CCMmat.MATlire_nombre_lignes()) {
		Cexception EXCerror;
		//Les dimensions des matrices ne permettent pas la multiplication
		EXCerror.EXCmodifier_valeur(ERREUR_DIMENSIONS);
		throw EXCerror;
	}
	else {
		unsigned int uiBoucle_ligne, uiBoucle_colonne, uiBoucle_calcul;

		//On creer une nouvelle matrice
		Cmatrice<Ttype> CCMresult(this->MATlire_nombre_lignes(), CCMmat.MATlire_nombre_colonnes());

		//Pour chaque ligne de 0 a la taille de la matrice
		for (uiBoucle_ligne = 0; uiBoucle_ligne < CCMresult.MATlire_nombre_lignes(); uiBoucle_ligne++)
		{
			//Pour chaque colonne de 0 a la taille de la matrice
			for (uiBoucle_colonne = 0; uiBoucle_colonne < CCMresult.MATlire_nombre_colonnes(); uiBoucle_colonne++)
			{
				//On fait le calcul une première fois pour s'en servir de base
				CCMresult.MATmodifier_element(this->MATlire_element(uiBoucle_ligne, 0) * CCMmat.MATlire_element(0, uiBoucle_colonne), uiBoucle_ligne, uiBoucle_colonne);
				//On additionne le resultat des calculs de 1 jusqu'au nombre de colonnes de la première matrice(ou nombre de lignes de la deuxième)
				for (uiBoucle_calcul = 1; uiBoucle_calcul < CCMmat.MATlire_nombre_lignes(); uiBoucle_calcul++)
				{
					//On fait element de la ligne de la matrice 1 * element de la colonne de la matrice 2 correspondant
					CCMresult.MATmodifier_element(this->MATlire_element(uiBoucle_ligne, uiBoucle_calcul) * CCMmat.MATlire_element(uiBoucle_calcul, uiBoucle_colonne) + CCMresult.MATlire_element(uiBoucle_ligne, uiBoucle_colonne), uiBoucle_ligne, uiBoucle_colonne);
				}
			}
		}
		return CCMresult;
	}
}



template<class Ttype>
Ccalcul_matrice<Ttype> Ccalcul_matrice<Ttype>::CCMtranspose()
{
	unsigned int uiBoucle_ligne, uiBoucle_colonne;

	//On creer une nouvelle matrice
	Cmatrice<Ttype> CCMresult(this->MATlire_nombre_colonnes(), this->MATlire_nombre_lignes());

	//On recopie la matrice en inversant les indexes
	for (uiBoucle_ligne = 0; uiBoucle_ligne < CCMresult.MATlire_nombre_lignes(); uiBoucle_ligne++)
	{
		for (uiBoucle_colonne = 0; uiBoucle_colonne < CCMresult.MATlire_nombre_colonnes(); uiBoucle_colonne++)
		{
			CCMresult.MATmodifier_element(this->MATlire_element(uiBoucle_colonne, uiBoucle_ligne), uiBoucle_ligne, uiBoucle_colonne);
		}
	}
	return CCMresult;
}