#include "pch.h"
#include "Basic.h"


// Constructeur
Basic::Basic()
{

}

Basic::Basic(int pointDeVie, string nom) :
	pointDeVie(pointDeVie), nom(nom)
{
	pointDeVieMax = pointDeVie;
	force  = 0;
	armure = 0;
}

// Deconstructeur
Basic::~Basic()
{
}

// Recevoir dégats
void Basic::recevoirDegat(int degat)
{
	pointDeVie -= degat;

	// Warning
	if (pointDeVie < 0)
		pointDeVie = 0;

	
}

// Recevoir des soins
void Basic::recevoirSoin(int soin)
{
	pointDeVie += soin;

	// Warning
	if (pointDeVie > pointDeVieMax)
		pointDeVie = pointDeVieMax;
}

// Faire du dégats
void Basic::infligerDegat(Basic &cible)
{
	// Affichage
	cout << nom << " a inflige " << force << " de degats a sa cible " << endl;

	cible.recevoirDegat(force);
}

// Est vivant ?
bool Basic::statut()
{

	if (pointDeVie <= 0)
		return false;
	else
		return true;
}

// Se Présenter
void Basic::sePresenter()
{
	cout << "Bonjour, je suis " << nom << "." << endl;
	cout << "J'ai encore " << pointDeVie << " points de vie." << endl;
	cout << "J'ai " << force << " de force." << endl;
}