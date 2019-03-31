#ifndef DEF_DRONEDEREPARATION
#define DEF_DRONEDEREPARATION



#pragma once
#include "Drone.h"
class DroneDeReparation :
	public Drone
{
public:
	// Constructeur
	DroneDeReparation();
	DroneDeReparation(int pointDeVie, string nom, bool actif, int corpsPositionX, int corpsPositionY);
	// Destructeur
	~DroneDeReparation();

	// Getter
	float getSoin();

	// Function
	void amelioration();
	// Compétence de réparation
	void reparation(Module &cible);

protected:
	float soin;
	// Texture
	sf::Texture texture;
	// Sprite
	sf::Sprite sprite;
};

#endif // !DEF_DRONEDEREPARATION