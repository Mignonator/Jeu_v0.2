#include "pch.h"
#include "Planete.h"

// Constructeur
Planete::Planete()
{
}

Planete::Planete(string nom):
	nom(nom)
{
	// Test texture
	if (!texture.loadFromFile("ressources/sunsetintheswamp.png"))
	{
		//Rien à déclarer
	}
	else
	{
		//erreur...
		cout << "Incapable de charger l'image de la planete" << endl;
	}
	// Sprite
	sprite.setTexture(texture);
	//sprite.scale(sf::Vector2f(800, 600));
}

// Destructeur
Planete::~Planete()
{
}

// Affichage de la forme
void Planete::show(sf::RenderTarget& target)
{
	target.draw(sprite);
}