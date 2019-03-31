#include "pch.h"
#include "Golem.h"


Golem::Golem(int point_de_vie, string nom) :
	pointDeVie(point_de_vie), pointDeVieMax(point_de_vie), nom(nom)
{
	// Variable
	hpSizeX = 10; hpInitSizeX = hpSizeX;
	hpSizeY = 200; hpInitSizeY = hpSizeY;
	corpsPositionX = 500;
	corpsPositionY = 200;
	// Test texture
	if (!texture.loadFromFile("ressources/golem.png"))
	{
		// Rien à déclarer
	}
	else
	{
		//erreur...
		cout << "Incapable de charger l'image" << endl;
	}
	// Sprite
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(corpsPositionX, corpsPositionY));
	sprite.setScale(sf::Vector2f(0.5f, 0.5f));
	//sf::Vector2f position = sprite.getPosition();
	// Barre de vie
	//hpBar.setPosition(corpsPositionX, corpsPositionY);
	//hpBar.setSize(sf::Vector2f(hpSizeX, hpSizeY));
	//hpBar.setFillColor(sf::Color::Green);
	//hpBar.setOutlineThickness(1.f);
	//hpBar.setOutlineColor(sf::Color::Black);
	// Force du Golem
	force = 3.0;
}

Golem::~Golem()
{

}

// Affichage de la forme
void Golem::show(sf::RenderTarget& target)
{
	target.draw(sprite);
	//target.draw(hpBar);
}

// infliger des dégats
void Golem::infligerDegat(Vaisseau &cible, sf::Time temps)
{
	cible.recevoirDegat(force, temps);
}

// Gain de Niveau
void Golem::gainDeNiveau(int jour)
{
	force = 2 * jour + 3.0;
	pointDeVie = pointDeVieMax;
}

// Retourne la force du golem
float Golem::getForce()
{
	return force;
}