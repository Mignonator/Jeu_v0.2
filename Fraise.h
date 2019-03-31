#ifndef DEF_FRAISE
#define DEF_FRAISE

#pragma once
#include "Module.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

class Fraise
{
public:
	// Constructeur
	Fraise();
	Fraise(float point_de_vie, string nom);
	// Destructeur
	~Fraise();

	// Gain de ressource
	void forage(sf::Time temps);

	// Retourne les ressources
	double getRessource();

	// Retire les ressources utilisées pour les améliorations
	bool consommation(int montant);

	// Perte d'énergie
	void perteDEnergie(sf::Time temps);

	// Gain d'énergie
	void gainDEnergie(int gain);

	// Recevoir Soin
	void recevoirSoin(int soin);
	// Retourne la position du curseur par rapport au bouton
	bool eventMouse(int x, int y);
	// Affichage de la forme
	void show(sf::RenderTarget& target);

protected:
	// Texture
	sf::Texture texture;
	// Sprite
	sf::Sprite sprite;
	// Barre d'energie
	sf::RectangleShape nrjBar;
	// Variable
	float pointDeVie;
	float pointDeVieMax;
	string nom;
	int nrjSizeX, nrjInitSizeX;
	int nrjSizeY, nrjInitSizeY;
	int corpsPositionX, corpsPositionY;
	int corpsSizeX, corpsSizeY;
	// Ressource
	double ressource;
	int coeur;
};

#endif // !DEF_FRAISE