#include "pch.h"
#include "Bouton.h"

// Constructeur
Bouton::Bouton()
{
	corps.setSize(sf::Vector2f(20, 20));
	corps.setFillColor(sf::Color::White);
	corps.setOutlineThickness(1.f);
	corps.setOutlineColor(sf::Color::Red);
	// Chargement de la police de caractère
	font.loadFromFile("ressources/sansation/Sansation_Regular.ttf");
	// Message coût en ressource
	messRessource.setFont(font);
	messRessource.setCharacterSize(20);
	messRessource.setFillColor(sf::Color::White);
	// Message du type de module
	mess.setFont(font);
	mess.setCharacterSize(20);
	mess.setFillColor(sf::Color::White);
	// Niveau
	niveau = 1;
	// Ressource
	ressource = 0;
}

Bouton::Bouton(string nom, int corps_position_x, int corps_position_y, int corps_size_x, int corps_size_y) :
	nom(nom), corpsPositionX(corps_position_x), corpsPositionY(corps_position_y), corpsSizeX(corps_size_x), corpsSizeY(corps_size_y), messPosX(corps_position_x), messPosY(corps_position_y)
{
	// Corps
	corps.setPosition(corps_position_x, corps_position_y);
	corps.setSize(sf::Vector2f(corps_size_x, corps_size_y));
	corps.setFillColor(sf::Color::White);
	corps.setOutlineThickness(1.f);
	corps.setOutlineColor(sf::Color::Red);
	// Chargement de la police de caractère
	font.loadFromFile("ressources/sansation/Sansation_Regular.ttf");
	// Message coût en ressource
	messRessource.setFont(font);
	messRessource.setCharacterSize(20);
	messRessource.setPosition(corps_position_x - 200.f,corps_position_y);
	messRessource.setFillColor(sf::Color::White);
	// Message du type de module
	mess.setFont(font);
	mess.setCharacterSize(20);
	mess.setPosition(corps_position_x + 100.f, corps_position_y);
	mess.setFillColor(sf::Color::White);
	// Niveau
	niveau = 1;
	// Ressource
	ressource = 0;
}

// Déconstructeur
Bouton::~Bouton()
{
}

// Setter
void Bouton::setLevel(int lvl)
{
	niveau = lvl;
}
void Bouton::setNom(string name)
{
	nom = name;
}
void Bouton::setPosition(int posX, int posY)
{
	corpsPositionX = posX;
	corpsPositionY = posY;
	corps.setPosition(sf::Vector2f(corpsPositionX, corpsPositionY));
	messRessource.setPosition(corpsPositionX - 250.f, corpsPositionY);
	mess.setPosition(corpsPositionX + 100.f, corpsPositionY);
}
void Bouton::setRessource(int amount)
{
	ressource = amount;
}

void Bouton::setMessage(sf::Text message)
{
	mess = message;
}
// Getter

// Affichage de la forme
void Bouton::show(sf::RenderTarget& target, bool actif)
{
	// Affichage du bouton
	target.draw(corps);
	// Affiche le type de module
	mess.setString(nom);
	target.draw(mess);
	if (actif)
	{
		// Affiche le coût en ressource
		std::string stgRessource = std::to_string(ressource);
		messRessource.setString("Coût : " + stgRessource + " Ressources");
		target.draw(messRessource);
	}
	else
	{
		// Affiche l'achat du drone
		std::string stgAchat = std::to_string(ressource);
		messRessource.setString("Achat : " + stgAchat + " Ressources");
		target.draw(messRessource);
	}
}

// Retourne la position du curseur par rapport au bouton
bool Bouton::eventMouse(int x, int y)
{
	sf::Vector2f point(x, y);
	sf::FloatRect boundingBox = corps.getGlobalBounds();

	return boundingBox.contains(point);
}

// Gain de Niveau
void Bouton::gainDeNiveau()
{
	niveau += 1;
	ressource = 5 * niveau + 2;
}

// Retourne le coût en Ressource
int Bouton::coutEnRessource()
{
	cout << "achat : " << ressource << "!" << endl;
	return ressource;
}