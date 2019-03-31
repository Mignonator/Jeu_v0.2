#ifndef DEF_PLANETE
#define DEF_PLANETE

#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Planete
{
public:
	// Constructeur
	Planete();
	Planete(string nom);
	// Destructeur
	~Planete();

	// Affichage de la forme
	void show(sf::RenderTarget& target);

protected:
	// Texture
	sf::Texture texture;
	// Sprite
	sf::Sprite sprite;
	string nom;
};

#endif // !DEF_PLANETE