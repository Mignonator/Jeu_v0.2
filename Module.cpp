#include "pch.h"
#include "Module.h"


Module::Module()
{
}

Module::Module(int point_de_vie, string nom) : Basic(point_de_vie, nom)
{
	// Variable
	hpSizeX = 200; hpInitSizeX = hpSizeX;
	hpSizeY = 10;  hpInitSizeY = hpSizeY;
	// Corps
	corps.setPosition(200, 200);
	corps.setSize(sf::Vector2f(200,200));
	corps.setFillColor(sf::Color::White);
	corps.setOutlineThickness(1.f);
	corps.setOutlineColor(sf::Color::Black);
	// Barre de vie
	hpBar.setPosition(200, 200-hpSizeY);
	hpBar.setSize(sf::Vector2f(hpSizeX, hpSizeY));
	hpBar.setFillColor(sf::Color::Green);
	hpBar.setOutlineThickness(1.f);
	hpBar.setOutlineColor(sf::Color::Black);

}

Module::Module(int point_de_vie, string nom, int corps_position_x, int corps_position_y, int corps_size_x, int corps_size_y) : 
	Basic(point_de_vie, nom), corpsPositionX(corps_position_x), corpsPositionY(corps_position_y), corpsSizeX(corps_size_x), corpsSizeY(corps_size_y)
{
	// Variable
	hpSizeX = corps_size_x; hpInitSizeX = hpSizeX;
	hpSizeY = 10;           hpInitSizeY = hpSizeY;
	// Corps
	corps.setPosition(corps_position_x, corps_position_y);
	corps.setSize(sf::Vector2f(corps_size_x, corps_size_y));
	corps.setFillColor(sf::Color::White);
	corps.setOutlineThickness(1.f);
	corps.setOutlineColor(sf::Color::Black);
	// Barre de vie
	hpBar.setPosition(corps_position_x, corps_position_y - hpSizeY);
	hpBar.setSize(sf::Vector2f(hpSizeX, hpSizeY));
	hpBar.setFillColor(sf::Color::Green);
	hpBar.setOutlineThickness(1.f);
	hpBar.setOutlineColor(sf::Color::Black);
}


Module::~Module()
{
}

// Affichage de la forme
void Module::show(sf::RenderTarget& target)
{
	target.draw(corps);
	target.draw(hpBar);
}

// Recevoir des dégats
void Module::recevoirDegat(int degats, sf::Time temps)
{
	// Les points de vie sont mis à jour
	// Conversion du temps en int
	int varTemps = temps.asSeconds();
	pointDeVie = pointDeVieMax - degats * varTemps;

	// On modifie la barre de vie -- Spécialisation
	hpSizeX = hpInitSizeX * pointDeVie / pointDeVieMax;
	hpBar.setSize(sf::Vector2f(hpSizeX, hpSizeY));

	// Mise à jour de la couleur
	int ratio = 100 * pointDeVie / pointDeVieMax;
	if (ratio >= 60)
	{
		hpBar.setFillColor(sf::Color::Green);
	}
	else if (ratio <= 30)
	{
		hpBar.setFillColor(sf::Color::Red);
	}
	else
	{
		hpBar.setFillColor(sf::Color::Yellow);
	}

}

// Recevoir Soin
void Module::recevoirSoin(int soin)
{
	// Fonction de base
	//Basic::recevoirSoin(soin);

	this->sePresenter();

	pointDeVie += soin;

	this->sePresenter();

	// On modifie la barre de vie -- Spécialisation
	hpSizeX = hpInitSizeX * pointDeVie / pointDeVieMax;
	hpBar.setSize(sf::Vector2f(hpSizeX, hpSizeY));

	// Mise à jour de la couleur
	int ratio = 100 * pointDeVie / pointDeVieMax;
	if (ratio >= 60)
	{
		hpBar.setFillColor(sf::Color::Green);
	}
	else if (ratio <= 30)
	{
		hpBar.setFillColor(sf::Color::Red);
	}
	else
	{
		hpBar.setFillColor(sf::Color::Yellow);
	}
}

// Retourne la position du curseur par rapport au bouton
bool Module::eventMouse(int x, int y)
{
	sf::Vector2f point(x, y);
	sf::FloatRect boundingBox = corps.getGlobalBounds();

	return boundingBox.contains(point);
}