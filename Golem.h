#ifndef DEF_GOLEM
#define DEF_GOLEM

#pragma once
#include "Module.h"
#include "Vaisseau.h"
#include <SFML/Graphics.hpp>

class Golem
{
public:
	// Constructeur
	Golem(int pointDeVie, string nom);
	// Deconstructeur
	~Golem();

	// Affichage de la forme
	void show(sf::RenderTarget& target);

	// Infliger des dégats
	void infligerDegat(Vaisseau &cible, sf::Time temps);

	// Gain de niveau
	void gainDeNiveau(int jour);

	// retourne la force du golem
	float getForce();

protected:
	// Texture
	sf::Texture texture;
	// Sprite
	sf::Sprite sprite;
	// Barre de vie
	sf::RectangleShape hpBar;

	// Variable
	int hpSizeX, hpInitSizeX;
	int hpSizeY, hpInitSizeY;
	int corpsPositionX, corpsPositionY;
	int corpsSizeX, corpsSizeY;
	float pointDeVie;
	float pointDeVieMax;
	float force;
	string nom;
};

#endif // !DEF_GOLEM