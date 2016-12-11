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
	void AfficherEnTete(ostream & output, int maxColonnes) const;
	string DeterminerChaine(int i, int j) const;
	void InitMatrice(ifstream& in);							// Initialise la matrice
	void PlacerChiffre(int x, int y);						// Place un chiffre dans la matrice
	bool PeutBouger(int x, int y);							// Vérifie si le programme peut se déplacer dans la matrice
	bool Normaliser(int & x, int & y);						// Vérifie la position dans la matrice
	bool CaseExiste(int x, int y);							// Vérifie si la case voulu existe
	bool VerificationHorizontale(int x, int y, int nombre); // Vérifie les voisins horizontal d'une case
	bool VerificationVerticale(int x, int y, int nombre);	// Vérifie les voisins vertical d'une case
	bool VerifieLigneIdentique(int ligne);					// Vérifie il y a des lignes identiques dans la matrice
	bool VerifieColonneIdentique(int colonne);				// Vérifie il y a des colonnes identiques dans la matrice
	bool PeutPlacer(int x, int y, int nombre);				// Vérifie si le programme peut insérer un nombre dans la case
	bool EstLigneComplétée(int ligne) const;				// Vérifie si tous les cases de la ligne contiennent soie 0 ou 1
	bool EstColonneComplétée(int colonne) const;			// Vérifie si tous les cases de la colonne contiennent soie 0 ou 1
	void Ecrire(ostream & out);								// Affiche le Binairo
	int TrouverCodeValidationLigne(int ligne);				// Calcul en décimal une ligne
	int TrouverValidationColonne(int colonne);				// Calcul en décimal une colonne
	void EcrireCodeValidationColonnes(ostream & out);		// Affiche les résultats en décimal
};