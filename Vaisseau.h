#ifndef DEF_VAISSEAU
#define DEF_VAISSEAU

#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "DroneDeReparation.h"
#include "DroneDExploration.h"
#include "Bouton.h"

using namespace std;

#pragma once
class Vaisseau
{
public:
	// Constructeur
	Vaisseau();
	Vaisseau(int point_de_vie, string nom);
	Vaisseau(int point_de_vie, string nom, int corps_position_x, int corps_position_y, int corps_size_x, int corps_size_y);
	// Destructeur
	~Vaisseau();
	// Affichage de la forme
	void show(sf::RenderTarget& target, bool isJournee);
	// Recevoir des dégats
	void recevoirDegat(float degats, sf::Time temps);
	// Recevoir Soin
	void recevoirSoin(float soin);
	// Soin sur le temps
	void recevoirReparation(float soin, sf::Time temps);
	// Retourne la position du curseur par rapport au bouton
	bool eventMouse(int x, int y);
	// Est vivant ?
	bool statut();
	// gain HP Maw
	void gainHPMax();
	// Retourne Armure
	float getArmor();
	// Retourne la capacité de reparation du drone
	float getReparation();
	// Retourne la vitesse
	float getVitesse();
	// Retourne les HP
	float getHP();
	// Retourne les HP Max
	float getMaxHP();
	// recevoir expérience
	void getExperience(float distance);
	// Get distance
	float getDistance();

	//// Drone
	// De reparation
	DroneDeReparation droneDeReparation;
	// D'exploration
	DroneDExploration *droneExplorateur;
	//// Bouton
	// Structure
	Bouton *boutonDeStructure;
	// Clique de soin
	Bouton *boutonCliqueDeSoin;

protected:
	// Barre de vie
	sf::RectangleShape hpBar;
	// Texture
	sf::Texture texture;
	// Sprite
	sf::Sprite sprite;

	// Nom
	string nom;
	// Variable
	int hpSizeX, hpInitSizeX;
	int hpSizeY, hpInitSizeY;
	int corpsPositionX, corpsPositionY;
	int corpsSizeX, corpsSizeY;
	float pointDeVie;
	float pointDeVieMax;
	int armure;
	int force;
	float vitesse;

	float distance;
	
};

#endif // !DEF_VAISSEAU