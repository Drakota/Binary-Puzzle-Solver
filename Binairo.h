#include "Chrono.h"
#include "Matrice.h"
#pragma once

class Binairo
{
	Chrono chronom�tre_;
	Matrice <int> m_;
	ostream & rOut_;
public:
	Binairo(ifstream & in, ofstream & out);
	void Solutionner();
private:
	void PlacerChiffre(int x, int y);
	// vos autres m�thodes private ici�
	void AfficherEnTete(ostream & output, int maxColonnes) const;
	string DeterminerChaine(int i, int j) const;
	bool EstLigneCompl�t�e(int ligne) const;
	bool EstColonneCompl�t�e(int colonne) const;
	void Ecrire(ostream & out);
	int TrouverCodeValidationLigne(int ligne);
	void EcrireCodeValidationColonnes(ostream & out);
};