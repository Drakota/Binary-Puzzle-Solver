// Programme Binairo
// par Pierre Prud'homme, décembre 2016
//
// On indiquera dans un fichier de sortie où se trouve chaque
// mot et dans quelle direction dans la grille.
//------------------------------------------------------------
#include "Binairo.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Binairo::Binairo(ifstream & in, ofstream & out) : rOut_(out), m_(NOMBRE_LIGNE, NOMBRE_COLONNE)
{
	InitMatrice(in);
}

void Binairo::Solutionner()
{
	PlacerChiffre(0, 0);
	Ecrire(cout);
}

void Binairo::InitMatrice(ifstream & in)
{
	int nombre;
	int x = 0, y = 0;
	do
	{
		nombre = in.get() - '0';
		if (nombre == 0 || nombre == 1 || nombre == VALEUR_SENTINELLE)
		{
			if (y > NOMBRE_LIGNE - 1) 
			{
				++x;
				y = 0;
			}
			m_[x][y] = nombre;
			++y;
		}
	} while (!in.eof());
}

void Binairo::BloquerCase(int x, int y)
{

}

void Binairo::PlacerChiffre(int x, int y)
{
	if (EstLigneComplétée(x) && x < NOMBRE_COLONNE)
	{
		for (int i = 0; i < NOMBRE_LIGNE; i++)
		{
			if (m_[x][i] == VALEUR_SENTINELLE)
			{
				m_[x][i] = 0;
			}
		}
		PlacerChiffre(x + 1, y);
	}
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
		chaine = "   |";
	else
		if (m_[i][j] == 0)
		{
			chaine = " 0 |";
		}
		else
		{
			chaine = " 1 |";
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