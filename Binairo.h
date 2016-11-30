#include "Chrono.h"
#include "Matrice.h"
#pragma once

class Binairo
{
	Chrono chronomètre_;
	Matrice <int> m_;
	ostream & rOut_;
public:
	Binairo(ifstream & in, ofstream & out);
	void Solutionner();
private:
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