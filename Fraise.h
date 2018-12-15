#ifndef DEF_FRAISE
#define DEF_FRAISE

#pragma once
#include "Module.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

class Fraise :
	public Module
{
public:
	// Constructeur
	Fraise();
	Fraise(int point_de_vie, string nom);
	Fraise(int point_de_vie, string nom, int corps_position_x, int corps_position_y, int corps_size_x, int corps_size_y);
	// Destructeur
	~Fraise();

	// Gain de ressource
	void forage();

	// Retourne les ressources
	int getRessource();

	// Retire les ressources utilisées pour les améliorations
	bool consommation(int montant);

protected:
	// Ressource
	int ressource;
};

#endif // !DEF_FRAISE