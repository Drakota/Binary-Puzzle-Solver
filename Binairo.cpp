// Programme Binairo
// par Pierre Prud'homme, d�cembre 2016
//
// On indiquera dans un fichier de sortie o� se trouve chaque
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
	minit_ = m_;
}

void Binairo::BloquerCase(int x, int y)
{

}


void Binairo::PlacerChiffre(int x, int y)
{
	if (EstLigneCompl�t�e(x) && x < NOMBRE_COLONNE)
	{
		for (int i = 0; i < NOMBRE_LIGNE; i++)
		{
			if (PeutBouger(x, i))
			{
				if (PeutPlacerUn(x, i))
				{
					m_[x][i] = 1;
					PlacerChiffre(x + 1, y);
				}
				else if (PeutPlacerZ�ros(x, i))
				{
					m_[x][i] = 0;
					PlacerChiffre(x + 1, y);
				}
			}
		}
	}

}

bool Binairo::PeutBouger(int x, int y)
{
	if (minit_[x][y] == 0 || minit_[x][y] == 1) return false;
	else return true;
}

bool Binairo::PeutPlacerUn(int x, int y)
{
	int NombreUnsLigne = 0;
	int NombreUnsColonne = 0;

	for (int i = 0; i < NOMBRE_COLONNE; i++)
	{
		if (m_[x][i] == 1) NombreUnsLigne++;
		if (m_[i][y] == 1) NombreUnsColonne++;
	}
	if (NombreUnsLigne != NOMBRE_UNS && NombreUnsColonne != NOMBRE_UNS) return true;
	else return false;
}

bool Binairo::PeutPlacerZ�ros(int x, int y)
{
	int NombreZ�rosLigne = 0;
	int NombreZ�rosColonne = 0;

	for (int i = 0; i < NOMBRE_COLONNE; i++)
	{
		if (m_[x][i] == 0) NombreZ�rosLigne++;
		if (m_[i][y] == 0) NombreZ�rosColonne++;
	}
	if (NombreZ�rosLigne != NOMBRE_Z�ROS && NombreZ�rosColonne != NOMBRE_Z�ROS) return true;
	else return false;
}

// seront rendus disponibles aux �tudiants un certain nombre de fonctions
// reli�es � l'�criture � l'�cran de la solution : 
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

	// La valeur sentinelle est l'�toile ('*')
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

bool Binairo::EstLigneCompl�t�e(int ligne) const
{
	int nbFoisValeurSentinelle = 0;

	for (int j = 0; j < nbLignesBinairo_; ++j)
		if (m_[ligne][j] == VALEUR_SENTINELLE) nbFoisValeurSentinelle++;

	return nbFoisValeurSentinelle == 0;
}

bool Binairo::EstColonneCompl�t�e(int colonne) const
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

	// ligne d'ent�te num�rot�e
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
		if (EstLigneCompl�t�e(i))  out << "\t\t" << TrouverCodeValidationLigne(i);
		out << endl << ligneDeSeparation << endl;
	}
	EcrireCodeValidationColonnes(out);
}

int Binairo::TrouverCodeValidationLigne(int ligne)
{
	// � compl�ter par l'�tudiant
	int somme = 0, index = 0;

	for(int i = NOMBRE_COLONNE - 1; i > 0; --i)
	{
		if (m_[ligne][index] == 1)
		{
			somme += pow(2, i);
		}
		++index;
	}
	return somme;
}

void Binairo::EcrireCodeValidationColonnes(ostream & out)
{
	// � compl�ter par l'�tudiant
	// Note : cette m�thode fait appel � une autre m�thode 
	//        nomm�e TrouverCodeValidationColonne() calqu�e
	//        sur l'autre. 

	for (int i = 0; i < NOMBRE_LIGNE; ++i)
	{
		TrouverCodeValidationLigne(i);
	}
}