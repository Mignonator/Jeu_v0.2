#include "pch.h"
#include "Drone.h"

// Constructeur
Drone::Drone()
{
	// Test texture
	if (texture.loadFromFile("ressources/drone.png"))
	{

	}
	else
	{
		//erreur...
		cout << "Incapable de charger l'image de drone" << endl;
	}
	// Sprite
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(0, 0));
	sprite.setScale(sf::Vector2f(0.3, 0.3));
	// Variable
	actif = false;
	niveau = 0;
}

Drone::Drone(int point_de_vie, string nom, int corps_position_x, int corps_position_y, int corps_size_x, int corps_size_y) :
	Module(point_de_vie,nom, corps_position_x, corps_position_y, corps_size_x, corps_size_y)
{
	actif = false;
}

Drone::Drone(int pointDeVie, string nom, bool actif, int corps_position_x, int corps_position_y) :
	pointDeVie(pointDeVie), pointDeVieMax(pointDeVie), nom(nom), actif(actif), corpsPositionX(corps_position_x), corpsPositionY(corps_position_y)
{

	corpsSizeX = 20;
	corpsSizeY = 20;

	//Sprite
	sprite.setPosition(corps_position_x, corps_position_y);
	sprite.setScale(sf::Vector2f(0.3, 0.3));

}

// Deconstructeur
Drone::~Drone()
{
}

// Setters
void Drone::setName(string name)
{
	nom = name;
}

void Drone::setActive(bool activation)
{
	//cout << "activation du drone : " << activation << endl;
	actif = activation;
}

void Drone::setHealthPoint(int HP)
{
	pointDeVie = HP;
	pointDeVieMax = HP;
}

void Drone::setPosition(int PosX, int PosY)
{
	corpsPositionX = PosX;
	corpsPositionY = PosY;
	sprite.setPosition(sf::Vector2f(corpsPositionX, corpsPositionY));
}

void Drone::setBoutonPosition(int posX, int posY)
{
	bouton.setPosition(posX, posY);
}
void Drone::setBoutonMess(string text)
{
	bouton.setNom(text);
}

void Drone::setBoutonRessource(int ress)
{
	bouton.setRessource(ress);
}
// Getters

bool Drone::getActif()
{
	return actif;
}

// Fonction
void Drone::achat()
{
	this->setActive(true);
	this->gainDeNiveau();

	bouton.setRessource(7);

	clockTheta.restart();
}

void Drone::gainDeNiveau()
{
	niveau += 1;
}


void Drone::move()
{
	int rayon = 25;
	double theta = clockTheta.getElapsedTime().asSeconds()*3.14;
	corpsPositionX = rayon * cos(theta);
	corpsPositionY = rayon * sin(theta);
}

// Affichage de la forme
void Drone::show(sf::RenderTarget& target, bool isJournee)
{
	if (isJournee)
	{
		if (actif)
		{
			this->move();
			target.draw(sprite);
		}
	}
	else
	{
		bouton.show(target, actif);
	}	
}