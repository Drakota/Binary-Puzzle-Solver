/*
Charles Morin et Jonathan Bouchard
2016-12-03
Binairo
Binairo.h
*/
#include "Chrono.h"
#include "Matrice.h"
#pragma once

class Binairo
{
	const int NOMBRE_LIGNE = 10;
	const int NOMBRE_COLONNE = 10;
    const int NOMBRE_ZÉROS = 5;
	const int NOMBRE_UNS = 5;
	const char VALEUR_SENTINELLE = '*' - '0';
	int nbLignesBinairo_;
	Chrono chronomètre_;
	Matrice <int> m_;
	Matrice <int> minit_;
	ostream & rOut_;
public:
	Binairo(ifstream & in, ofstream & out);
	void Solutionner();
private:
	void InitMatrice(ifstream& in);
	void BloquerCase(int x, int y);
	void PlacerChiffre(int x, int y);
	// vos autres méthodes private ici…
	bool VerifierVoisin(int x, int y);
	bool PeutBouger(int x, int y);
	bool PeutPlacerUn(int x, int y);
	bool PeutPlacerZéros(int x, int y);
	void AfficherEnTete(ostream & output, int maxColonnes) const;
	string DeterminerChaine(int i, int j) const;
	bool EstLigneComplétée(int ligne) const;
	bool EstColonneComplétée(int colonne) const;
	void Ecrire(ostream & out);
	int TrouverCodeValidationLigne(int ligne);
	void EcrireCodeValidationColonnes(ostream & out);
};