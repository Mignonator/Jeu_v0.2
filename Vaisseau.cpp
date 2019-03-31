#include "pch.h"
#include "Vaisseau.h"


Vaisseau::Vaisseau()
{
}

Vaisseau::Vaisseau(int point_de_vie, string nom) :
	pointDeVie(point_de_vie), pointDeVieMax(point_de_vie), nom(nom), droneExplorateur(100,"Explorateur",true,400,400)
{
	// Variable
	corpsPositionX = 200;
	corpsPositionY = 100;
	vitesse = 10;
	armure = 1;
	// Test texture
	if (texture.loadFromFile("ressources/vaisseau.png"))
	{
		// Rien à déclarer
		cout << "Le sprite du vaisseau est correctement charge" << endl;
	}
	else
	{
		//erreur...
		cout << "Incapable de charger l'image du vaisseau" << endl;
	}
	// Sprite
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(corpsPositionX, corpsPositionY));
	sf::Vector2f position = sprite.getPosition();
	sf::IntRect textureRect = sprite.getTextureRect();
	hpSizeX = textureRect.width;
	hpSizeY = 10;
	hpInitSizeX = hpSizeX;
	hpInitSizeY = hpSizeY;
	// Barre de vie 2
	hpBar.setPosition(position);
	hpBar.move(sf::Vector2f(0, -hpSizeY));
	hpBar.setSize(sf::Vector2f(hpSizeX, hpSizeY));
	hpBar.setFillColor(sf::Color::Green);
	hpBar.setOutlineThickness(1.f);
	hpBar.setOutlineColor(sf::Color::Black);

	//// Drone
	// De reparation
	droneDeReparation.setHealthPoint(100);
	droneDeReparation.setName("le drone de reparation");
	droneDeReparation.setActive(true);
	droneDeReparation.setPosition(position.x, position.y);
	// D'exploration
	//droneExplorateur = new DroneDExploration(100,"Explorateur",true,corpsPositionX,300);
	// Bouton
	droneDeReparation.setBoutonPosition(350, 350);
	droneDeReparation.setBoutonMess("drone de reparation");
	droneDeReparation.setBoutonRessource(250);

	//// Bouton
	// Structure
	boutonDeStructure = new Bouton("Structure",350,250,20,20);
	// Clique de soin
	boutonCliqueDeSoin = new Bouton("Clique de Soin", 350, 400, 20, 20);
}

Vaisseau::Vaisseau(int point_de_vie, string nom, int corps_position_x, int corps_position_y, int corps_size_x, int corps_size_y) :
	pointDeVie(point_de_vie), pointDeVieMax(point_de_vie), corpsPositionX(corps_position_x), corpsPositionY(corps_position_y), corpsSizeX(corps_size_x), corpsSizeY(corps_size_y)
{
	// Variable
	hpSizeX = corps_size_x; hpInitSizeX = hpSizeX;
	hpSizeY = 10;           hpInitSizeY = hpSizeY;
	// Barre de vie
	hpBar.setPosition(corps_position_x, corps_position_y - hpSizeY);
	hpBar.setSize(sf::Vector2f(hpSizeX, hpSizeY));
	hpBar.setFillColor(sf::Color::Green);
	hpBar.setOutlineThickness(1.f);
	hpBar.setOutlineColor(sf::Color::Black);
}

Vaisseau::~Vaisseau()
{
	delete droneDexploration;
}

// Affichage de la forme
void Vaisseau::show(sf::RenderTarget& target, bool isJournee)
{
	if (isJournee)
	{
		//// Vaisseau
		// Barre de vie
		target.draw(hpBar);
		// Sprite
		target.draw(sprite);
		
	}
	else
	{
		//// Bouton
		// Structure
		boutonDeStructure->show(target, true);

	}
	//// Drone
	// Drone de reparation
	droneDeReparation.show(target, isJournee);
}

// Recevoir des dégats
void Vaisseau::recevoirDegat(float degats, sf::Time temps)
{
	// Les points de vie sont mis à jour
	// Conversion du temps en int
	float varTemps = temps.asMilliseconds();

	//cout << "Temps ecoule depuis le debut : " << varTemps << endl;
	//cout << "Degat escompté : " << degats * varTemps / 1000 << endl;

	pointDeVie = max(pointDeVie - degats * varTemps / 1000, 0.f);

	// On modifie la barre de vie -- Spécialisation
	//hpSizeX = hpInitSizeX * pointDeVie / pointDeVieMax;
	//hpBar.setSize(sf::Vector2f(hpSizeX, hpSizeY));
	hpBar.setScale(sf::Vector2f(pointDeVie / pointDeVieMax, 1));

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
void Vaisseau::recevoirSoin(float soin)
{
	//cout << "PdV avant soin : " << pointDeVie << endl;
	pointDeVie = min(pointDeVie + soin, pointDeVieMax);
	//cout << "PdV apres soin : " << pointDeVie << endl;
}

// Recevoir reparation
void Vaisseau::recevoirReparation(float soin, sf::Time temps)
{
	// Les points de vie sont mis à jour
	// Conversion du temps en int
	float varTemps = temps.asMilliseconds();

	//cout << "Temps ecoule depuis le debut : " << varTemps << endl;
	//cout << "Degat escompté : " << degats * varTemps / 1000 << endl;

	pointDeVie = min(pointDeVie + soin * varTemps / 1000, pointDeVieMax);

	// On modifie la barre de vie -- Spécialisation
	//hpSizeX = hpInitSizeX * pointDeVie / pointDeVieMax;
	//hpBar.setSize(sf::Vector2f(hpSizeX, hpSizeY));
	hpBar.setScale(sf::Vector2f(pointDeVie / pointDeVieMax, 1));

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
bool Vaisseau::eventMouse(int x, int y)
{
	sf::Vector2f point(x, y);
	sf::FloatRect boundingBox = sprite.getGlobalBounds();

	return boundingBox.contains(point);
}

// Est vivant ?
bool Vaisseau::statut()
{

	if (pointDeVie <= 0)
		return false;
	else
		return true;
}

void Vaisseau::gainHPMax()
{
	pointDeVieMax = pointDeVieMax + pointDeVieMax*.1;
}

// Retourne armure
float Vaisseau::getArmor()
{
	return armure;
}

// Retourne armure
float Vaisseau::getReparation()
{
	return droneDeReparation.getSoin();
}

// retourne la Vitesse
float Vaisseau::getVitesse()
{
	return vitesse;
}

float Vaisseau::getHP()
{
	return pointDeVie;
}

float Vaisseau::getMaxHP()
{
	return pointDeVieMax;
}