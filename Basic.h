#ifndef DEF_BASIC
#define DEF_BASIC

#include <string>
#include <iostream>

using namespace std;

#pragma once
class Basic
{
public:
	// Constructeur
	Basic();
	Basic(int point_de_vie, string nom);
	// Descontructeur
	~Basic();

	// Recevoir des d�gats
	void recevoirDegat(int degats);

	// Recevoir des soins
	void recevoirSoin(int soin);

	// Faire du d�gats
	void infligerDegat(Basic &cible);

	// Se pr�senter
	void sePresenter();

	// Est vivant ?
	bool statut();

protected:
	int pointDeVie;
	int pointDeVieMax;
	int armure;
	int force;
	string nom;

};

#endif // !DEF_BASIC