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

// Permet de demander à l'utilisateur le nom du fichier dans lequel
// se trouve la grille de Binairo
string DemanderNom(string sPrompt);

int main()
{
	//This is the start of a great adventure
	// point d'entrée du programme
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
			/*Passez en deuxième paramètre la valeur « cout » pour écrire la réponse
			à l'écran. */
			/*Passez en deuxième paramètre la valeur « cout » pour écrire la réponse
			à l'écran. */
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
// Permet de demander à l'utilisateur le nom du fichier dans lequel
// se trouve la grille de Binairo
// Intrant : la chaine d'incitation à faire apparaitre à l'écran
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
