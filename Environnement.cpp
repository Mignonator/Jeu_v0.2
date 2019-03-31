#include "pch.h"
#include "Environnement.h"


Environnement::Environnement()
{
	// Chargement de la police de caractère
	if (!font.loadFromFile("ressources/sansation/Sansation_Regular.ttf"))
		cout << "N'a pas pus charger la police de caractère depuis : Environnement" << endl;

	// Initialisation du Menu
	messDistance.setFont(font);
	messDistance.setCharacterSize(20);
	messDistance.setPosition(400.f, 500.f);
	messDistance.setFillColor(sf::Color::White);

	// Initialisation
	distanceMax = 100;
	distance = distanceMax;
}


Environnement::~Environnement()
{
}

// Gestion distance
void Environnement::calculDistance(Vaisseau vaisseau, Golem golem)
{
	// Capacité de soin
	float reparation = vaisseau.getReparation();

	// Res
	float armure = vaisseau.getArmor();

	float vitesse = vaisseau.getVitesse();

	float degats = calculDegats(golem);

	float force = golem.getForce();

	float t = timer.restart().asMilliseconds();
	
	// Calcul de la distance
	distanceEquilibre = min( max( (force - reparation)*distanceMax, 0.f) , distanceMax);

	float rapport = vaisseau.getHP() / vaisseau.getMaxHP();

	if (vaisseau.getHP() / vaisseau.getMaxHP() < 0.8f)
	{
		// Déplacement vers la distance d'équilibre
		if (distance > distanceEquilibre)
			distance += -1* vitesse * timer.restart().asMilliseconds()/1000;
		else
			distance +=  1 * vitesse * timer.restart().asMilliseconds() / 1000;
	}
	else
		distance += -1* vitesse * timer.restart().asMilliseconds() / 1000;

	int tmp = trunc(distance);

	std::string stgDistance = std::to_string(tmp);

	messDistance.setString("Distance : " + stgDistance + " km");
}

// Calcul degats golem
float Environnement::calculDegats(Golem golem)
{
	float force = golem.getForce();
	float degats = -1*force*distance/distanceMax + force;
	return degats;
}

// Affichage de la forme
void Environnement::show(sf::RenderTarget& target, Vaisseau vaisseau, Golem golem)
{
	// Update
	calculDistance(vaisseau, golem);

	target.draw(messDistance);
}

// Renvoie la distance
float Environnement::getDistance()
{
	return distance;
}

void Environnement::setEnvironnement()
{
	timer.restart();
}

void Environnement::damagePhase(Vaisseau vaisseau, Golem golem)
{
	vaisseau.recevoirDegat( calculDegats(golem) , timer.getElapsedTime() );
	vaisseau.recevoirReparation(vaisseau.droneDeReparation.getSoin(), timer.getElapsedTime());
}