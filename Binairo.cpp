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
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

//Binairo::Binairo(ifstream & in, ofstream & out)
//{
//
//}
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
<<<<<<< HEAD
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
=======
	//if (m_[x][y] == VALEUR_SENTINELLE)
	//	PlacerChiffre(x,y);
	//else if (m_[x][y] == 1)
	//	PlacerChiffre(x +1,y);
	//else if (m_[x][y] = )
>>>>>>> refs/remotes/origin/CHARLES
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
	int somme=0,temp=0,index = 0;

	for(int i = NOMBRE_COLONNE-1; i > 0; --i)
	{
		if (m_[ligne][index] == '1')
		{
			temp = pow(2, i);
			somme += temp;
		}
		++index;
	}
	return somme;
}

void Binairo::EcrireCodeValidationColonnes(ostream & out)
{
	// à compléter par l'étudiant
	// Note : cette méthode fait appel à une autre méthode 
	//        nommée TrouverCodeValidationColonne() calquée
	//        sur l'autre. 

	//for (int i = 0; i < NOMBRE_LIGNE; ++i)
	//{
	//	TrouverCodeValidationLigne(i);
	//}

	//out << "Penis lol xdddd";
}