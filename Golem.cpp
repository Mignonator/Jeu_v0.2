#include "pch.h"
#include "Golem.h"


Golem::Golem(int point_de_vie, string nom) : Basic(point_de_vie, nom)
{
	// Variable
	hpSizeX = 10;
	hpSizeY = 200;
	// Corps
	corps.setPosition(500, 200);
	corps.setSize(sf::Vector2f(100, 200));
	corps.setFillColor(sf::Color::White);
	corps.setOutlineThickness(1.f);
	corps.setOutlineColor(sf::Color::Black);
	// Barre de vie
	hpBar.setPosition(600, 200);
	hpBar.setSize(sf::Vector2f(hpSizeX, hpSizeY));
	hpBar.setFillColor(sf::Color::Green);
	hpBar.setOutlineThickness(1.f);
	hpBar.setOutlineColor(sf::Color::Black);
	// Force du Golem
	force = 5;
}

Golem::~Golem()
{

}

// Affichage de la forme
void Golem::show(sf::RenderTarget& target)
{
	target.draw(corps);
	target.draw(hpBar);
}

// infliger des dégats
void Golem::infligerDegat(Module &cible)
{
	cible.recevoirDegat(force);
}