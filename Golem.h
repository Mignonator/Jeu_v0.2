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
	Golem(int point_de_vie, string nom);
	// Deconstructeur
	~Golem();

	// Affichage de la forme
	void show(sf::RenderTarget& target);

	// Infliger des dégats
	void Infliger_Degats(Module &cible);

protected:
	// Corps
	sf::RectangleShape Corps;
	// Barre de vie
	sf::RectangleShape HP_bar;

	// Variable
	int HP_size_x;
	int HP_size_y;
};

#endif // !DEF_GOLEM