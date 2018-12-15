#ifndef DEF_MODULE
#define DEF_MODULE



#pragma once
#include "Basic.h"
#include <string>
#include <SFML/Graphics.hpp>

class Module :
	public Basic
{
public:
	// Constructeur
	Module();
	Module(int point_de_vie, string nom);
	Module(int point_de_vie, string nom, int corps_position_x, int corps_position_y, int corps_size_x, int corps_size_y);
	// Deconstructeur
	~Module();

	// Affichage de la forme
	void show(sf::RenderTarget& target);

	// Recevoir des dégats
	void recevoirDegat(int degats);

	// Recevoir Soin
	void recevoirSoin(int soin);

	// Retourne la position du curseur par rapport au bouton
	bool eventMouse(int x, int y);

protected:
	// Corps
	sf::RectangleShape corps;
	// Barre de vie
	sf::RectangleShape hpBar;

	// Variable
	int hpSizeX, hpInitSizeX;
	int hpSizeY, hpInitSizeY;
	int corpsPositionX, corpsPositionY;
	int corpsSizeX, corpsSizeY;

};

#endif // !DEF_MODULE