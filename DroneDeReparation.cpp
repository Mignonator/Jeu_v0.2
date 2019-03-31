#include "pch.h"
#include "DroneDeReparation.h"


DroneDeReparation::DroneDeReparation()
{
}


DroneDeReparation::~DroneDeReparation()
{
}

DroneDeReparation::DroneDeReparation(int pointDeVie, string nom, bool actif, int corpsPositionX, int corpsPositionY) : 
	Drone(pointDeVie, nom, corpsPositionX, corpsPositionY, 20 ,20)
{
	// Test texture
	if (!texture.loadFromFile("ressources/drone.png"));
	{
		//erreur...
		cout << "Incapable de charger l'image de drone" << endl;
	}
	// Sprite
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(corpsPositionX, corpsPositionY));
	// Variable
	soin = 1;
}

float DroneDeReparation::getSoin()
{
	return soin;
}

void DroneDeReparation::amelioration()
{
	soin = 5 * niveau;
}

// Compétence Réparation
void DroneDeReparation::reparation(Module &cible)
{
	cible.recevoirSoin(soin);
}