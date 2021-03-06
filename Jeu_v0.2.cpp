// Jeu_v0.2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Golem.h"
#include "Basic.h"
#include "Module.h"
#include "Drone.h"
#include "Bouton.h"
#include "Fraise.h"
#include <string>

using namespace std::string_literals;

int main()
{
	// création de la fenêtre
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	window.setFramerateLimit(60);

	// Chargement de la police de caractère
	sf::Font font;
	if (!font.loadFromFile("ressources/sansation/Sansation_Regular.ttf"))
		return EXIT_FAILURE;

	/////////////////////
	//
	// Jour
	//
	////////////////////

	//// Création du Vaisseau
	// Module 1
	Module Module1(100, "le module Drone");
	Module1.sePresenter();

	//// gestion des drônes
	// Drone de soin
	Drone Drone_Soigneur(10, "le drone soigneur", 50, 200, 50, 50);
	// Drone de scan
	Drone Drone_Scanneur(10, "le drone scanneur", 50, 350, 50, 50);

	//// Création du Golem
	Golem Golem(1000, "le mechant Golem");
	Golem.sePresenter();

	//// Création de la Fraise
	Fraise Fraise(100, "La petite Fraise", 500, 300, 50 ,50);

	// Affichage des ressources accumulées
	sf::Text Mess_Ressources;
	Mess_Ressources.setFont(font);
	Mess_Ressources.setCharacterSize(20);
	Mess_Ressources.setPosition(200.f, 500.f);
	Mess_Ressources.setFillColor(sf::Color::White);
	

	/////////////////////
	//
	// Menu pause
	//
	////////////////////

	// Initialisation du Menu
	sf::Text pauseMessage;
	pauseMessage.setFont(font);
	pauseMessage.setCharacterSize(20);
	pauseMessage.setPosition(200.f, 150.f);
	pauseMessage.setFillColor(sf::Color::White);
	pauseMessage.setString("Bienvenue !\nPressez la touche espace pour continuer !");

	////////////////
	//
	// Nuit
	//
	////////////////

	//// UI
	// Timer Nuit
	sf::Text Mess_Timer_Nuit;
	Mess_Timer_Nuit.setFont(font);
	Mess_Timer_Nuit.setCharacterSize(20);
	Mess_Timer_Nuit.setPosition(400.f, 20.f);
	Mess_Timer_Nuit.setFillColor(sf::Color::White);
	// Message Nuit
	sf::Text Mess_Menu_Nuit;
	Mess_Menu_Nuit.setFont(font);
	Mess_Menu_Nuit.setCharacterSize(20);
	Mess_Menu_Nuit.setPosition(150.f, 200.f);
	Mess_Menu_Nuit.setFillColor(sf::Color::White);
	Mess_Menu_Nuit.setString("Menu des améliorations :");
	////// Menu des améliorations
	//// Moteur
	// Bouton associé
	Bouton Bouton_Moteur("Moteur", 350, 250, 20, 20);
	//// Structure
	// Bouton associé
	Bouton Bouton_Structure("Structure", 350, 300, 20, 20);
	//// Drone de Soin
	// Bouton associé
	Bouton Bouton_Drone_de_Soin("Drone de soin", 350, 350, 20, 20);
	//// Soin de clique
	// Bouton associé
	Bouton Bouton_Soin_de_Clique("Soin de Clique", 350, 400, 20, 20);

	//////////////////
	//
	// Autre
	//
	//////////////////

	//// variable de Jeu
	// Timer
	sf::Clock clock; // Démarre le Chrono
	sf::Clock timerJour; // Timer pour la journée
	sf::Clock timerNuit; // Timer pour la nuit
	sf::Time tOneSec = sf::seconds(1);
	sf::Time tJourRef = sf::seconds(30);
	sf::Time tNuitRef = sf::seconds(30);
	bool isPlaying = false;
	bool isJournee = true;
	// Autre
	int soinParClique = 1;

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

			// Gestion du Menu Pause
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
			{
				if (!isPlaying)
				{
					// (re)Démarrage du Jeu
					isPlaying = true;
					clock.restart();
				}
				else
				{
					// Retour du Menu Pause
					isPlaying = false;
				}
			}

			// gestion du Jeu
			if (isJournee)
			{
				// Gestion de la souris
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Module1.eventMouse(event.mouseButton.x, event.mouseButton.y))
				{
					// Bouton Gauche == Soin
					Module1.recevoirSoin(soinParClique);
				}
				// Foreuse
				// Soin de clique
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Fraise.eventMouse(event.mouseButton.x, event.mouseButton.y))
				{
					Fraise.recevoirSoin(10);
				}
			}
			else
			{
				////// Gestion de la souris
				//// Bouton
				// Moteur
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Bouton_Moteur.eventMouse(event.mouseButton.x, event.mouseButton.y))
				{
					// Test de la possibilité de l'amélioration
					if (Fraise.consommation(Bouton_Moteur.coutEnRessource()))
					{
						Bouton_Moteur.gainDeNiveau();
						tJourRef = tJourRef - sf::seconds(1);
					}
						
				}
				// Structure
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Bouton_Structure.eventMouse(event.mouseButton.x, event.mouseButton.y))
				{

				}
				// Drone de Soin
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Bouton_Drone_de_Soin.eventMouse(event.mouseButton.x, event.mouseButton.y))
				{

				}
				// Soin de clique
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Bouton_Soin_de_Clique.eventMouse(event.mouseButton.x, event.mouseButton.y))
				{
					if (Fraise.consommation(Bouton_Soin_de_Clique.coutEnRessource()))
					{
						Bouton_Soin_de_Clique.gainDeNiveau();
						soinParClique += 1;
					}
				}
			}
		}

		// Jeu
		if (isPlaying)
		{
			//// Journée
			if (isJournee)
			{
				// Phase de Jeu par seconde
				if (clock.getElapsedTime() >= tOneSec)
				{
					// Golem Attaque
					Golem.infligerDegat(Module1);

					// Check Hull State
					isPlaying = Module1.statut(); // a mettre dans infliger_degat

					// Soin
					Drone_Soigneur.reparation(Module1);

					// Fraise
					Fraise.recevoirDegat(20);
					Fraise.forage();

					Module1.sePresenter();

					// Fin de la phase d'attaque
					clock.restart();
				}


				// Temps Jour
				if (timerJour.getElapsedTime() >= tJourRef)
				{
					timerJour.restart();
					timerNuit.restart();
					isJournee = false;
				}
			}
			else
			{
				// Temps Nuit
				if (timerNuit.getElapsedTime() >= tNuitRef)
				{
					timerJour.restart();
					timerNuit.restart();
					isJournee = true;
					//initialition golem / module 100% vie
				}
			}

			
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
			if (isJournee)
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
				//// Fraise
				Fraise.show(window);

				//// UI
				// Timer Jour
				sf::Text Mess_Jour;
				Mess_Jour.setFont(font);
				Mess_Jour.setCharacterSize(20);
				Mess_Jour.setPosition(200.f, 20.f);
				Mess_Jour.setFillColor(sf::Color::White);
				sf::Time elapsed = timerJour.getElapsedTime();
				int sec = elapsed.asSeconds();
				std::string text = std::to_string(sec);
				int t_ref_Jour = tJourRef.asSeconds();
				std::string st_Timer_Jour_ref = std::to_string(t_ref_Jour);
				Mess_Jour.setString(text + " / " + st_Timer_Jour_ref + " s");
				window.draw(Mess_Jour);
				// Ressources accumulées
				std::string stg_Ressources = std::to_string(Fraise.getRessource());
				Mess_Ressources.setString("Ressources : " + stg_Ressources);
				window.draw(Mess_Ressources);
			}
			else
			{
				//// UI
				// Timer Nuit
				sf::Time elapsed = timerNuit.getElapsedTime();
				int sec = elapsed.asSeconds();
				std::string text = std::to_string(sec);
				int t_ref_Nuit = tNuitRef.asSeconds();
				std::string st_Timer_Jour_ref = std::to_string(t_ref_Nuit);
				Mess_Timer_Nuit.setString(text + " / " + st_Timer_Jour_ref + " s");
				window.draw(Mess_Timer_Nuit);
				
				// Ressources accumulées
				std::string stg_Ressources = std::to_string(Fraise.getRessource());
				Mess_Ressources.setString("Ressources restantes : " + stg_Ressources);
				window.draw(Mess_Ressources);

				// Message Nuit
				window.draw(Mess_Menu_Nuit);
				////// Menu des améliorations
				//// Moteur
				// Bouton associé
				Bouton_Moteur.show(window);
				//// Structure
				// Bouton associé
				Bouton_Structure.show(window);
				//// Drone de Soin
				// Bouton associé
				Bouton_Drone_de_Soin.show(window);
				//// Soin de clique
				// Bouton associé
				Bouton_Soin_de_Clique.show(window);
			}
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
