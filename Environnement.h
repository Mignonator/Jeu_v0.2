#ifndef DEF_ENVIRONNEMENT
#define DEF_ENVIRONNEMENT

#pragma once
#include "Golem.h"
#include "Vaisseau.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Environnement
{
public:
	Environnement();
	~Environnement();

	// Gestion de la distance
	void calculDistance(Vaisseau vaisseau, Golem golem);
	// Calcul des dégats infligés par le golem
	float calculDegats(Golem golem);

	float getDistance();

	void setEnvironnement();

	// Degats de l'environnement sur le vaisseau
	void damagePhase(Vaisseau vaisseau, Golem golem);

	// Affichage de la forme
	void show(sf::RenderTarget& target, Vaisseau vaisseau, Golem golem);

protected:
	float distance;
	float distanceEquilibre;
	float distanceMax;
	sf::Font font;
	sf::Text messDistance;
	sf::Clock timer;
};

#endif // !DEF_ENVIRONNEMENT