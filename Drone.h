#ifndef DEF_DRONE
#define DEF_DRONE

#pragma once
#include "Module.h"
#include "Bouton.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Drone :
	public Module
{
public:
	// Constructeur
	Drone();
	Drone(int point_de_vie, string nom, int corps_position_x, int corps_position_y, int corps_size_x, int corps_size_y);
	Drone(int point_de_vie, string nom, bool actif, int corps_position_x, int corps_position_y);
	// Destructeur
	~Drone();

	//Setters
	void setPosition(int PosX, int PosY);
	void setActive(bool active);
	void setHealthPoint(int PdV);
	void setName(string nom);
	void setBoutonPosition(int PosX, int PosY);
	void setBoutonMess(string mess);
	void setBoutonRessource(int ress);
	//Getters
	bool getActif();

	// Fonction
	void achat();
	void gainDeNiveau();
	void move();

	// Compétence de Scan
	
	// Affichage de la forme
	void show(sf::RenderTarget& target, bool isJournee);

	// Bouton test
	Bouton bouton;

protected:
	// Texture
	sf::Texture texture;
	// Sprite
	sf::Sprite sprite;
	bool actif;
	int corpsPositionX, corpsPositionY, niveau;
	double pointDeVie, pointDeVieMax;
	string nom;
	
	sf::Clock clockTheta;
	
};

#endif // !DEF_DRONE