// Jeu_v0.2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Golem.h"
#include "Basic.h"
#include "Module.h"
#include "Drone.h"

int main()
{
	// création de la fenêtre
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	window.setFramerateLimit(60);

	//// Création du Vaisseau
	// Module 1
	Module Module1(100, "le module Drone");
	Module1.SePrésenter();

	//// gestion des drônes
	// Drone de soin
	Drone Drone_Soigneur(10, "le drone soigneur", 50, 200, 50, 50);
	// Drone de scan
	Drone Drone_Scanneur(10, "le drone scanneur", 50, 350, 50, 50);

	//// Création du Golem
	Golem Golem(1000, "le mechant Golem");
	Golem.SePrésenter();

	// Chargement de la police de caractère
	sf::Font font;
	if (!font.loadFromFile("ressources/sansation/Sansation_Regular.ttf"))
		return EXIT_FAILURE;

	// Initialisation du Menu
	sf::Text pauseMessage;
	pauseMessage.setFont(font);
	pauseMessage.setCharacterSize(20);
	pauseMessage.setPosition(200.f, 150.f);
	pauseMessage.setFillColor(sf::Color::White);
	pauseMessage.setString("Bienvenue !\nPressez la touche espace pour continuer !");

	// variable de Jeu
	sf::Clock clock; // Démarre le Chrono
	sf::Time t_oneSec = sf::seconds(1);
	bool isPlaying = false;

	// on fait tourner le programme tant que la fenêtre n'a pas été fermée
	while (window.isOpen())
	{
		// on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
		sf::Event event;
		while (window.pollEvent(event))
		{
			// fermeture de la fenêtre lorsque l'utilisateur le souhaite
			if (event.type == sf::Event::Closed)
				window.close();

			// Gestion de la souris
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Module1.eventMouse(event.mouseButton.x, event.mouseButton.y))
			{
				// Bouton Gauche == Soin
				Module1.Recevoir_Soin(1);
			}

			// Gestion du Menu Pause
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
			{
				if (!isPlaying)
				{
					// (re)Démarrage du Jeu
					isPlaying = true;
					clock.restart();
				}

			}

		}

		// Jeu
		if (isPlaying)
		{
			// Phase de Jeu par seconde
			if (clock.getElapsedTime() >= t_oneSec)
			{
				// Golem Attaque
				Golem.Infliger_Degats(Module1);
				
				// Soin
				Drone_Soigneur.Reparation(Module1);

				// Fin de la phase d'attaque
				clock.restart();
			}

			// Check Hull State
			isPlaying = Module1.Statut();
		}

		// effacement de la fenêtre en noir
		window.clear(sf::Color::Black);

		//////////////
		//
		// Affichage
		//
		//////////////
		if (isPlaying)
		{
			//// Vaisseau
			// Module 1
			Module1.show(window);
			//// Drone
			// Drone de soin
			Drone_Soigneur.show(window);
			// Drone scanneur
			Drone_Scanneur.show(window);
			//// Golem 
			Golem.show(window);
		}
		else
		{
			// Menu Pause
			window.draw(pauseMessage);
		}
		
		// fin de la frame courante, affichage de tout ce qu'on a dessiné
		window.display();
	}

	return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Conseils pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
