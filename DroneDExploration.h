#ifndef DEF_DRONEDEXPLORATION
#define DEF_DRONEDEXPLORATION

#pragma once
#include "Drone.h"
#include "Environnement.h"

class DroneDExploration :
	public Drone
{
public:

	// Constructeur
	DroneDExploration();
	DroneDExploration(int pointDeVie, string nom, bool actif, int corps_position_x, int corps_position_y);
	// Destructeur
	~DroneDExploration();

	// Function
	void gainDExperience(sf::Time temps, Environnement medium);
	void show(sf::RenderTarget& target, Environnement medium);
	//Setter
	void setTextMessExperience();
	// Getter
	float getExperience();

protected :
	float experience;
	sf::Font font;
	sf::Text messExperience;
	sf::Clock timer;
};

#endif // !DEF_DRONEDEXPLORATION