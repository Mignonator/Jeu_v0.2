#include "pch.h"
#include "Module.h"


Module::Module()
{
}

Module::Module(int point_de_vie, string nom) : Basic(point_de_vie, nom)
{
	// Variable
	HP_size_x = 200; HP_init_size_x = HP_size_x;
	HP_size_y = 10;  HP_init_size_y = HP_size_y;
	// Corps
	Corps.setPosition(200, 200);
	Corps.setSize(sf::Vector2f(200,200));
	Corps.setFillColor(sf::Color::White);
	Corps.setOutlineThickness(1.f);
	Corps.setOutlineColor(sf::Color::Black);
	// Barre de vie
	HP_bar.setPosition(200, 200-HP_size_y);
	HP_bar.setSize(sf::Vector2f(HP_size_x, HP_size_y));
	HP_bar.setFillColor(sf::Color::Green);
	HP_bar.setOutlineThickness(1.f);
	HP_bar.setOutlineColor(sf::Color::Black);

}

Module::Module(int point_de_vie, string nom, int corps_position_x, int corps_position_y, int corps_size_x, int corps_size_y) : 
	Basic(point_de_vie, nom), corps_position_x(corps_position_x), corps_position_y(corps_position_y), corps_size_x(corps_size_x), corps_size_y(corps_size_y)
{
	// Variable
	HP_size_x = corps_size_x; HP_init_size_x = HP_size_x;
	HP_size_y = 10;           HP_init_size_y = HP_size_y;
	// Corps
	Corps.setPosition(corps_position_x, corps_position_y);
	Corps.setSize(sf::Vector2f(corps_size_x, corps_size_y));
	Corps.setFillColor(sf::Color::White);
	Corps.setOutlineThickness(1.f);
	Corps.setOutlineColor(sf::Color::Black);
	// Barre de vie
	HP_bar.setPosition(corps_position_x, corps_position_y - HP_size_y);
	HP_bar.setSize(sf::Vector2f(HP_size_x, HP_size_y));
	HP_bar.setFillColor(sf::Color::Green);
	HP_bar.setOutlineThickness(1.f);
	HP_bar.setOutlineColor(sf::Color::Black);
}


Module::~Module()
{
}

// Affichage de la forme
void Module::show(sf::RenderTarget& target)
{
	target.draw(Corps);
	target.draw(HP_bar);
}

// Recevoir des dégats
void Module::Recevoir_Degats(int degats)
{
	// On perds de la vie -- Fonction de base
	Basic::Recevoir_Degats(degats);

	// On modifie la barre de vie -- Spécialisation
	HP_size_x = HP_init_size_x * point_de_vie / point_de_vie_max;
	HP_bar.setSize(sf::Vector2f(HP_size_x, HP_size_y));

	// Mise à jour de la couleur
	int ratio = 100 * point_de_vie / point_de_vie_max;
	if (ratio >= 60)
	{
		HP_bar.setFillColor(sf::Color::Green);
	}
	else if (ratio <= 30)
	{
		HP_bar.setFillColor(sf::Color::Red);
	}
	else
	{
		HP_bar.setFillColor(sf::Color::Yellow);
	}

}

// Recevoir Soin
void Module::Recevoir_Soin(int soin)
{
	// Fonction de base
	Basic::Recevoir_Soin(soin);

	// On modifie la barre de vie -- Spécialisation
	HP_size_x = HP_init_size_x * point_de_vie / point_de_vie_max;
	HP_bar.setSize(sf::Vector2f(HP_size_x, HP_size_y));

	// Mise à jour de la couleur
	int ratio = 100 * point_de_vie / point_de_vie_max;
	if (ratio >= 60)
	{
		HP_bar.setFillColor(sf::Color::Green);
	}
	else if (ratio <= 30)
	{
		HP_bar.setFillColor(sf::Color::Red);
	}
	else
	{
		HP_bar.setFillColor(sf::Color::Yellow);
	}
}

// Retourne la position du curseur par rapport au bouton
bool Module::eventMouse(int x, int y)
{
	sf::Vector2f point(x, y);
	sf::FloatRect boundingBox = Corps.getGlobalBounds();

	return boundingBox.contains(point);
}