#include "pch.h"
#include "DroneDExploration.h"


DroneDExploration::DroneDExploration()
{
	experience = 0;
}

DroneDExploration::DroneDExploration(int pointDeVie, string nom, bool actif, int corps_position_x, int corps_position_y) : Drone(pointDeVie, nom, actif,corps_position_x,corps_position_y)
{
	experience = 0;

	// Chargement de la police de caractère
	if (!font.loadFromFile("ressources/sansation/Sansation_Regular.ttf"))
		cout << "N'a pas pus charger la police de caractère depuis : Environnement" << endl;

	// Initialisation du Menu
	messExperience.setFont(font);
	messExperience.setCharacterSize(20);
	messExperience.setPosition(400.f, 500.f);
	messExperience.setFillColor(sf::Color::White);

	// Timer
	timer.restart();
}

DroneDExploration::~DroneDExploration()
{
}

void DroneDExploration::gainDExperience(sf::Time temps, Environnement medium)
{

	float distance = medium.getDistance();

	float gainXp = min( max(1000 / distance, 1.f), 100.f);

	experience += temps.asMilliseconds() * 1000;
}

float DroneDExploration::getExperience()
{
	return experience;
}

void DroneDExploration::show(sf::RenderTarget& target, Environnement medium)
{
	// gain Xp
	gainDExperience(timer.restart(), medium);
	
	// Mise à jour
	setTextMessExperience();

	// Affichage
	target.draw(sprite);
	target.draw(messExperience);
}

void DroneDExploration::setTextMessExperience()
{
	std::string stgExperience = std::to_string(experience);
	messExperience.setString("Experience : " + stgExperience);
}