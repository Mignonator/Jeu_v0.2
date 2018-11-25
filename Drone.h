#ifndef DEF_DRONE
#define DEF_DRONE

#pragma once
#include "Module.h"


class Drone :
	public Module
{
public:
	// Constructeur
	Drone();
	Drone(int point_de_vie, string nom, int corps_position_x, int corps_position_y, int corps_size_x, int corps_size_y);
	// Destructeur
	~Drone();

	// Comp�tence de r�paration
	void Reparation(Module &cible);

	// Comp�tence de Scan
	


protected:
	int soin;
};

#endif // !DEF_DRONE