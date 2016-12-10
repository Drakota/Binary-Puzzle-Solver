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
#include <iomanip>
using namespace std;

Binairo::Binairo(ifstream & in, ofstream & out) : rOut_(out), m_(NOMBRE_LIGNE, NOMBRE_COLONNE)
{
	InitMatrice(in);
}

/*
Solutionne le binairo
*/
void Binairo::Solutionner()
{
	Chrono temps;
	temps.Start();
	PlacerChiffre(0, 0);
	temps.Stop();
	cout << temps.Read() << endl;
}

/*
Lis le fichier
et initialise la matrice
*/
void Binairo::InitMatrice(ifstream & in)
{
	int nombre = 0;
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

/*
Empêche la valeur
de la case d'être changée
*/
void Binairo::BloquerCase(int x, int y)
{

}

<<<<<<< HEAD
/*
Place un 0 ou un 1
dans la matrice
*/
=======
>>>>>>> refs/remotes/origin/dev
void Binairo::PlacerChiffre(int x, int y)
{
	if (Normaliser(x, y))
	{
		if (PeutBouger(x, y))
		{
			for (int i = 0; i < 2; i++)
			{
				if (PeutPlacer(x, y, i))
				{
					m_[x][y] = i;
					PlacerChiffre(x, y + 1);
					m_[x][y] = VALEUR_SENTINELLE;
				}
			}
		}
		else PlacerChiffre(x, y + 1);
	}
	else
	{
		// la grille est pleine; verifier le succes
		Ecrire(cout);
	}
}

/*
Vérifie si le programme
peut se déplacer dans la matrice
*/
bool Binairo::PeutBouger(int x, int y)
{
	if (minit_[x][y] == 0 || minit_[x][y] == 1) return false;
	else return true;
}

<<<<<<< HEAD
bool Binairo::VerifierVoisin(int x, int y)
{

}

/*
Vérifie si le programme
peut incérer un 1 dans la case
*/
bool Binairo::PeutPlacerUn(int x, int y)
{
	int NombreUnsLigne = 0;
	int NombreUnsColonne = 0;

	for (int i = 0; i < NOMBRE_COLONNE; ++i)
=======
bool Binairo::Normaliser(int & x, int & y)
{
	if (x < NOMBRE_LIGNE && y < NOMBRE_COLONNE) return true;
	if (y >= NOMBRE_COLONNE)
>>>>>>> refs/remotes/origin/dev
	{
		++x;
		y = 0;
	}
	if (x < NOMBRE_LIGNE) return true;
	return false;
}

bool Binairo::CaseExiste(int x, int y)
{
	if (x >= 0 && x < NOMBRE_COLONNE && y >= 0 && y < NOMBRE_LIGNE) return true;
	else return false;
}

<<<<<<< HEAD
/*
Vérifie si le programme
peut incérer un 0 dans la case
*/
bool Binairo::PeutPlacerZéros(int x, int y)
=======
bool Binairo::VerificationHorizontale(int x, int y, int nombre)
{
	bool PeutMettre = false;
	if (CaseExiste(x, y - 1) && CaseExiste(x, y - 2)) if (m_[x][y - 1] == nombre && m_[x][y - 2] == nombre) PeutMettre = true;
	if (CaseExiste(x, y - 1) && CaseExiste(x, y + 1)) if (m_[x][y - 1] == nombre && m_[x][y + 1] == nombre) PeutMettre = true;
	if (CaseExiste(x, y + 1) && CaseExiste(x, y + 2)) if (m_[x][y + 1] == nombre && m_[x][y + 2] == nombre) PeutMettre = true;
	return PeutMettre;
}

bool Binairo::VerificationVerticale(int x, int y, int nombre)
>>>>>>> refs/remotes/origin/dev
{
	bool PeutMettre = false;
	if (CaseExiste(x - 1, y) && CaseExiste(x - 2, y)) if (m_[x - 1][y] == nombre && m_[x - 2][y] == nombre) PeutMettre = true;
	if (CaseExiste(x - 1, y) && CaseExiste(x + 1, y)) if (m_[x - 1][y] == nombre && m_[x + 1][y] == nombre) PeutMettre = true;
	if (CaseExiste(x + 1, y) && CaseExiste(x + 2, y)) if (m_[x + 1][y] == nombre && m_[x + 2][y] == nombre) PeutMettre = true;
	return PeutMettre;
}

bool Binairo::PeutPlacer(int x, int y, int nombre)
{
	int NombreLigne = 0;
	int NombreColonne = 0;

	for (int i = 0; i < NOMBRE_COLONNE; i++)
	{
		if (m_[x][i] == nombre) NombreLigne++;
		if (m_[i][y] == nombre) NombreColonne++;
	}

	if (NombreLigne != NOMBRE_UNS && NombreColonne != NOMBRE_UNS && !VerificationHorizontale(x, y, nombre) && !VerificationVerticale(x, y, nombre)) return true;
	else return false;
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
			if (m_[ligne][j] == VALEUR_SENTINELLE) nbFoisValeurSentinelle + 1;

	return nbFoisValeurSentinelle == 0;
}

bool Binairo::EstColonneComplétée(int colonne) const
{
	int nbFoisValeurSentinelle = 0;

	for (int j = 0; j < nbLignesBinairo_; ++j)
		if (m_[j][colonne] == VALEUR_SENTINELLE) nbFoisValeurSentinelle + 1;

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
	int somme = 0, index = 0;

	for (int i = NOMBRE_COLONNE - 1; i >= 0; --i)
	{
		if (m_[ligne][index] == 1)
		{
			somme += pow(2, i);
		}
		++index;
	}
	return somme;
}

int Binairo::TrouverValidationColonne(int colonne)
{
	int somme = 0, index = 0;

	for (int i = NOMBRE_LIGNE - 1; i >= 0; --i)
	{
		if (m_[index][colonne] == 1)
		{
			somme += pow(2, i);
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
	for (int i = 0; i < NOMBRE_LIGNE; ++i)
		TrouverCodeValidationLigne(i);

	out << " ";

	for (int j = 0; j < NOMBRE_COLONNE; ++j)
	{
		out << setw(3) << TrouverValidationColonne(j) << " ";
	}
	out << endl;
}