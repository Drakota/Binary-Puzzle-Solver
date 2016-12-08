// Programme Binairo
// par Pierre Prud'homme, décembre 2016
//
// On indiquera dans un fichier de sortie où se trouve chaque
// mot et dans quelle direction dans la grille.
//------------------------------------------------------------
/*
Charles Morin et Jonathan Bouchard
2016-12-03
Binairo
Binairo.cpp
*/
#include "Binairo.h"
#include <iostream>
#include <string>
using namespace std;

Binairo::Binairo(ifstream & in, ofstream & out)
{

}

void Binairo::Solutionner()
{

}

void Binairo::InitMatrice(ifstream & in)
{
	
}

void Binairo::PlacerChiffre(int x, int y)
{
	if (m_[x][y] == )
		PlacerChiffre(x,y);
	else if (m_[x][y] == )
		PlacerChiffre(x,y);
}

// seront rendus disponibles aux étudiants un certain nombre de fonctions
// reliées à l'écriture à l'écran de la solution : 
void Binairo::AfficherEnTete(ostream & output, int maxColonnes) const
{
	output << "  ";
	for (int i = 0; i < maxColonnes; ++i)
	{
		output << "  ";
		output.width(2); output << i;
	}
	output << "\t    " << "Verification" << endl;
}

string Binairo::DeterminerChaine(int i, int j) const
{
	string chaine;

	// La valeur sentinelle est l'étoile ('*')
	if (m_.at(i).at(j) == VALEUR_SENTINELLE)
		chaine = "   !";
	else
		if (m_[i][j] == 0)
		{
			chaine = " 0 !";
		}
		else
		{
			chaine = " 1 !";
		}
	return chaine;
}

bool Binairo::EstLigneComplétée(int ligne) const
{
	int nbFoisValeurSentinelle = 0;

	for (int j = 0; j < nbLignesBinairo_; ++j)
		if (m_[ligne][j] == VALEUR_SENTINELLE) nbFoisValeurSentinelle++;

	return nbFoisValeurSentinelle == 0;
}

bool Binairo::EstColonneComplétée(int colonne) const
{
	int nbFoisValeurSentinelle = 0;

	for (int j = 0; j < nbLignesBinairo_; ++j) 
		if (m_[j][colonne] == VALEUR_SENTINELLE) nbFoisValeurSentinelle++;

	return nbFoisValeurSentinelle == 0;
}

void Binairo::Ecrire(ostream & out)
{
	int i, j;
	int maxLignes = m_.GetNbLignes();
	int maxColonnes = m_.GetNbColonnes();
	const char SEPARATEUR_COLONNE = '|';  
	const char SEPARATEUR_COLONNE_LIGNE_PLEINE = '+'; 

	// ligne d'entête numérotée
	AfficherEnTete(out, maxColonnes);

	// grille
	string ligneDeSeparation;
	string partie = "---";
	partie += SEPARATEUR_COLONNE_LIGNE_PLEINE;
	for (int w = 0; w < maxColonnes + 1; ++w) { ligneDeSeparation += partie; }

	out << ligneDeSeparation << endl;
	for (i = 0; i < maxLignes; i++)
	{
		out.width(2);
		out << i << " " << SEPARATEUR_COLONNE;
		for (j = 0; j < maxColonnes; j++)
		{
			out << DeterminerChaine(i, j);
		}
		if (EstLigneComplétée(i))  out << "\t\t" << TrouverCodeValidationLigne(i);
		out << endl << ligneDeSeparation << endl;
	}
	EcrireCodeValidationColonnes(out);
}

int Binairo::TrouverCodeValidationLigne(int ligne)
{
	// à compléter par l'étudiant


	return 0;
}

void Binairo::EcrireCodeValidationColonnes(ostream & out)
{
	// à compléter par l'étudiant
	// Note : cette méthode fait appel à une autre méthode 
	//        nommée TrouverCodeValidationColonne() calquée
	//        sur l'autre. 
}