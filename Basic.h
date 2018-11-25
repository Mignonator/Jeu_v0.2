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

	// Recevoir des dégats
	void Recevoir_Degats(int degats);

	// Recevoir des soins
	void Recevoir_Soin(int soin);

	// Faire du dégats
	void Infliger_Degats(Basic &cible);

	// Se présenter
	void SePrésenter();

	// Est vivant ?
	bool Statut();

protected:
	int point_de_vie;
	int point_de_vie_max;
	int armure;
	int Force;
	string nom;

};

#endif // !DEF_BASIC