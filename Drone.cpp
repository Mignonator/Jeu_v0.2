#include "pch.h"
#include "Drone.h"

// Constructeur
Drone::Drone()
{

}

Drone::Drone(int point_de_vie, string nom, int corps_position_x, int corps_position_y, int corps_size_x, int corps_size_y) :
	Module(point_de_vie,nom, corps_position_x, corps_position_y, corps_size_x, corps_size_y)
{
	soin = 1;
}

// Deconstructeur
Drone::~Drone()
{
}

// Compétence Réparation
void Drone::reparation(Module &cible)
{
	cible.recevoirSoin(soin);
}