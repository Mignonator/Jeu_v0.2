#ifndef DEF_BOUTON
#define DEF_BOUTON

#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

#pragma once
class Bouton
{
public:
	// Constructeur
	Bouton();
	Bouton(string nom, int corps_position_x, int corps_position_y, int corps_size_x, int corps_size_y);
	// D�constructeur
	~Bouton();

	// Affichage de la forme
	void show(sf::RenderTarget& target);

	// Retourne la position du curseur par rapport au bouton
	bool eventMouse(int x, int y);

	// Gain de niveau
	void gainDeNiveau();

	// Retourne le co�t en ressource
	int coutEnRessource();

protected:
	// Corps
	sf::RectangleShape corps;

	// Variable
	string nom;
	int corpsPositionX, corpsPositionY;
	int corpsSizeX, corpsSizeY;
	int niveau;
	int ressource;
	float messPosX, messPosY;

	// Chargement de la police de caract�re
	sf::Font font;
	sf::Text mess, messRessource;
};

#endif // !DEF_BOUTON