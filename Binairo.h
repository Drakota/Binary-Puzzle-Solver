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
<<<<<<< HEAD
	const char VALEUR_SENTINELLE = '*';
=======
	const int NOMBRE_LIGNE = 10;
	const int NOMBRE_COLONNE = 10;
	const char VALEUR_SENTINELLE = '*' - '0';
>>>>>>> refs/remotes/origin/JO
	int nbLignesBinairo_;
	Chrono chronom�tre_;
	Matrice <int> m_;
	ostream & rOut_;
public:
	Binairo(ifstream & in, ofstream & out);
	void Solutionner();
private:
	void InitMatrice(ifstream& in);
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