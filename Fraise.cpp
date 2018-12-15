#include "pch.h"
#include "Fraise.h"

// Constructeur
Fraise::Fraise()
{
}

Fraise::Fraise(int point_de_vie, string nom) : Module(point_de_vie, nom)
{
	// ressources
	ressource = 0;
}

Fraise::Fraise(int point_de_vie, string nom, int corps_position_x, int corps_position_y, int corps_size_x, int corps_size_y) :
	Module(point_de_vie, nom,corps_position_x, corps_position_y, corps_size_x, corps_size_y)
{
	// ressources
	ressource = 100;
}

// Destructeur
Fraise::~Fraise()
{
}

// Forage
void Fraise::forage()
{
	// Gain de Ressource
	ressource += 10 * pointDeVie / pointDeVieMax;
}

// Retourne les ressources accumulées
int Fraise::getRessource()
{
	return ressource;
}

// Retire les ressources utilisées pour les améliorations
bool Fraise::consommation(int montant)
{
	if (montant < ressource)
	{
		return false;
		cout << "Ne peux pas améliorer" << endl;
	}
	else
	{
		return true;
		cout << "Amélioration !" << endl;
		ressource -= montant;
	}
}