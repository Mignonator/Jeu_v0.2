#ifndef DEF_GOLEM
#define DEF_GOLEM

#pragma once
#include "Basic.h"
#include "Module.h"
#include <SFML/Graphics.hpp>

class Golem :
	public Basic
{
public:
	// Constructeur
	Golem(int pointDeVie, string nom);
	// Deconstructeur
	~Golem();

	// Affichage de la forme
	void show(sf::RenderTarget& target);

	// Infliger des dégats
	void infligerDegat(Module &cible);

protected:
	// Corps
	sf::RectangleShape corps;
	// Barre de vie
	sf::RectangleShape hpBar;

	// Variable
	int hpSizeX;
	int hpSizeY;
};

#endif // !DEF_GOLEM