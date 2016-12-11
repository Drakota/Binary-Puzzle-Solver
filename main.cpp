/*
	Charles Morin et Jonathan Bouchard
	2016-12-03
	Binairo
	main.cpp
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Binairo.h"
using namespace std;

// Permet de demander � l'utilisateur le nom du fichier dans lequel
// se trouve la grille de Binairo
string DemanderNom(string sPrompt);

int main()
{
	//This is the start of a great adventure
	// point d'entr�e du programme
	system("Color F0");
	char cReponse = 'O';
	string sFichierGrille = DemanderNom("Entrez le nom du fichier contenant la grille : ");

	while (sFichierGrille != "")
	{
		ifstream in(sFichierGrille.c_str());
		if (!in.fail())
		{
			string sOut = "Solution-" + sFichierGrille;
			ofstream out(sOut.c_str());
			/*Passez en deuxi�me param�tre la valeur � cout � pour �crire la r�ponse
			� l'�cran. */
			/*Passez en deuxi�me param�tre la valeur � cout � pour �crire la r�ponse
			� l'�cran. */
			Binairo Jeu(in, out);
			Jeu.Solutionner();
		}
		else
		{
			cout << "Probleme a la lecture de la grille..." << endl;
		}
		sFichierGrille = DemanderNom("Entrez le nom du fichier contenant la grille : ");
	}

}
// Permet de demander � l'utilisateur le nom du fichier dans lequel
// se trouve la grille de Binairo
// Intrant : la chaine d'incitation � faire apparaitre � l'�cran
// Extrant : le nom du fichier lu
//----------------------------------------------------------------------
string DemanderNom(string sPrompt)
{
	string sNomLu;

	cout << sPrompt;
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, sNomLu);
	cout << endl;
	return sNomLu;
}
