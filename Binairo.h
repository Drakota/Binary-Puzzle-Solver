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
	const int NOMBRE_Z�ROS = 5;
	const int NOMBRE_UNS = 5;
	const char VALEUR_SENTINELLE = '*' - '0';
	int nbLignesBinairo_;
	Chrono chronom�tre_;
	Matrice <int> m_;
	Matrice <int> minit_;
	ostream & rOut_;
public:
	Binairo(ifstream & in, ofstream & out);
	void Solutionner();
private:
	void AfficherEnTete(ostream & output, int maxColonnes) const;
	string DeterminerChaine(int i, int j) const;
	void InitMatrice(ifstream& in);							// Initialise la matrice
	void PlacerChiffre(int x, int y);						// Place un chiffre dans la matrice
	bool PeutBouger(int x, int y);							// V�rifie si le programme peut se d�placer dans la matrice
	bool Normaliser(int & x, int & y);						// V�rifie la position dans la matrice
	bool CaseExiste(int x, int y);							// V�rifie si la case voulu existe
	bool VerificationHorizontale(int x, int y, int nombre); // V�rifie les voisins horizontal d'une case
	bool VerificationVerticale(int x, int y, int nombre);	// V�rifie les voisins vertical d'une case
	bool VerifieLigneIdentique(int ligne);					// V�rifie il y a des lignes identiques dans la matrice
	bool VerifieColonneIdentique(int colonne);				// V�rifie il y a des colonnes identiques dans la matrice
	bool PeutPlacer(int x, int y, int nombre);				// V�rifie si le programme peut ins�rer un nombre dans la case
	bool EstLigneCompl�t�e(int ligne) const;				// V�rifie si tous les cases de la ligne contiennent soie 0 ou 1
	bool EstColonneCompl�t�e(int colonne) const;			// V�rifie si tous les cases de la colonne contiennent soie 0 ou 1
	void Ecrire(ostream & out);								// Affiche le Binairo
	int TrouverCodeValidationLigne(int ligne);				// Calcul en d�cimal une ligne
	int TrouverValidationColonne(int colonne);				// Calcul en d�cimal une colonne
	void EcrireCodeValidationColonnes(ostream & out);		// Affiche les r�sultats en d�cimal
};