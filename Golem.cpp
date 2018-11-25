#include "pch.h"
#include "Golem.h"


Golem::Golem(int point_de_vie, string nom) : Basic(point_de_vie, nom)
{
	// Variable
	HP_size_x = 10;
	HP_size_y = 200;
	// Corps
	Corps.setPosition(500, 200);
	Corps.setSize(sf::Vector2f(100, 200));
	Corps.setFillColor(sf::Color::White);
	Corps.setOutlineThickness(1.f);
	Corps.setOutlineColor(sf::Color::Black);
	// Barre de vie
	HP_bar.setPosition(600, 200);
	HP_bar.setSize(sf::Vector2f(HP_size_x, HP_size_y));
	HP_bar.setFillColor(sf::Color::Green);
	HP_bar.setOutlineThickness(1.f);
	HP_bar.setOutlineColor(sf::Color::Black);
	// Force du Golem
	Force = 5;
}

Golem::~Golem()
{

}

// Affichage de la forme
void Golem::show(sf::RenderTarget& target)
{
	target.draw(Corps);
	target.draw(HP_bar);
}

// infliger des dégats
void Golem::Infliger_Degats(Module &cible)
{
	cible.Recevoir_Degats(Force);
}