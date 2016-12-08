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
	const char VALEUR_SENTINELLE = '*';
	int nbLignesBinairo_;
	Chrono chronomètre_;
	Matrice <int> m_;
	ostream & rOut_;
public:
	Binairo(ifstream & in, ofstream & out);
	void Solutionner();
private:
	void InitMatrice(ifstream& in);
	void PlacerChiffre(int x, int y);
	// vos autres méthodes private ici…
	void AfficherEnTete(ostream & output, int maxColonnes) const;
	string DeterminerChaine(int i, int j) const;
	bool EstLigneComplétée(int ligne) const;
	bool EstColonneComplétée(int colonne) const;
	void Ecrire(ostream & out);
	int TrouverCodeValidationLigne(int ligne);
	void EcrireCodeValidationColonnes(ostream & out);
};