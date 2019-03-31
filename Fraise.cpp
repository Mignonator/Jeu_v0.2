#include "pch.h"
#include "Fraise.h"

// Constructeur
Fraise::Fraise()
{
}

Fraise::Fraise(float pointDeVie, string nom) :
	pointDeVie(pointDeVie), pointDeVieMax(pointDeVie), nom(nom)
{
	// Variable
	corpsPositionX = 575;
	corpsPositionY = 350;
	// Test texture
	if (!texture.loadFromFile("ressources/fraise2.png"))
	{
		// Rien à déclarer
	}
	else
	{
		//erreur...
		cout << "Incapable de charger l'image de la fraise" << endl;
	}
	// Sprite
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(corpsPositionX, corpsPositionY));
	sprite.setColor(sf::Color::Red);
	sf::Vector2f position = sprite.getPosition();
	sf::IntRect textureRect = sprite.getTextureRect();
	nrjSizeX = 10;
	nrjSizeY = textureRect.height;
	nrjInitSizeX = nrjSizeX;
	nrjInitSizeY = nrjSizeY;
	// Barre d'energie
	// A Droite
	//nrjBar.setPosition(corpsPositionX + nrjSizeX + textureRect.width, corpsPositionY);
	// A Gauche
	nrjBar.setPosition(corpsPositionX - nrjSizeX, corpsPositionY);
	nrjBar.setSize(sf::Vector2f(nrjSizeX, nrjSizeY));
	nrjBar.setFillColor(sf::Color::Green);
	nrjBar.setOutlineThickness(1.f);
	nrjBar.setOutlineColor(sf::Color::Black);
	// ressource
	ressource = 0;
}

// Destructeur
Fraise::~Fraise()
{
}

// Forage
void Fraise::forage(sf::Time temps)
{
	// Gain de Ressource
	float varTemps = temps.asMilliseconds();
	ressource += 10 * pointDeVie / pointDeVieMax * varTemps / 1000;
}

// Retourne les ressources accumulées
double Fraise::getRessource()
{
	return ressource;
}

// Retire les ressources utilisées pour les améliorations
bool Fraise::consommation(int montant)
{
	if (montant > ressource)
	{
		cout << "Ne peux pas améliorer" << endl;
		return false;
	}
	else
	{
		cout << "Amélioration !" << endl;
		ressource -= montant;
		return true;
	}
}

// Perte d'énergie
void Fraise::perteDEnergie(sf::Time temps)
{
	// Conversion du temps en int
	float varTemps = temps.asMilliseconds();
	pointDeVie = max(0.f, pointDeVie - 10.f * varTemps / 1000);
	nrjBar.setScale(1, pointDeVie / pointDeVieMax);
}


// Gain d'énergie
void Fraise::gainDEnergie(int gain)
{
	pointDeVie = min(pointDeVieMax, pointDeVie + gain);
	nrjBar.setScale(1, pointDeVie / pointDeVieMax);
}

// Affichage de la forme
void Fraise::show(sf::RenderTarget& target)
{
	target.draw(sprite);
	target.draw(nrjBar);
}

// Retourne la position du curseur par rapport au bouton
bool Fraise::eventMouse(int x, int y)
{
	sf::Vector2f point(x, y);
	sf::FloatRect boundingBox = sprite.getGlobalBounds();

	return boundingBox.contains(point);
}

void Fraise::recevoirSoin(int soin)
{

}