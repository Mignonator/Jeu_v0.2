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
	void Recevoir_Degats(int degats);

	// Recevoir Soin
	void Recevoir_Soin(int soin);

	// Retourne la position du curseur par rapport au bouton
	bool eventMouse(int x, int y);

protected:
	// Corps
	sf::RectangleShape Corps;
	// Barre de vie
	sf::RectangleShape HP_bar;

	// Variable
	int HP_size_x, HP_init_size_x;
	int HP_size_y, HP_init_size_y;
	int corps_position_x, corps_position_y;
	int corps_size_x, corps_size_y;

};

#endif // !DEF_MODULE