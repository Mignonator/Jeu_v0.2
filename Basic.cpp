#include "pch.h"
#include "Basic.h"


// Constructeur
Basic::Basic()
{

}

Basic::Basic(int point_de_vie, string nom) :
	point_de_vie(point_de_vie), nom(nom)
{
	point_de_vie_max = point_de_vie;
	Force  = 0;
	armure = 0;
}

// Deconstructeur
Basic::~Basic()
{
}

// Recevoir dégats
void Basic::Recevoir_Degats(int degats)
{
	point_de_vie -= degats;

	// Warning
	if (point_de_vie < 0)
		point_de_vie = 0;

	
}

// Recevoir des soins
void Basic::Recevoir_Soin(int soin)
{
	point_de_vie += soin;

	// Warning
	if (point_de_vie > point_de_vie_max)
		point_de_vie = point_de_vie_max;
}

// Faire du dégats
void Basic::Infliger_Degats(Basic &cible)
{
	// Affichage
	cout << nom << " a inflige " << Force << " de degats a sa cible " << endl;

	cible.Recevoir_Degats(Force);
}

// Est vivant ?
bool Basic::Statut()
{
	if (point_de_vie <= 0)
		return false;
	else
		return true;
}

// Se Présenter
void Basic::SePrésenter()
{
	cout << "Bonjour, je suis " << nom << "." << endl;
	cout << "J'ai encore " << point_de_vie << " points de vie." << endl;
	cout << "J'ai " << Force << " de force." << endl;
}