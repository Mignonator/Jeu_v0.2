// Jeu_v0.2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Golem.h"
#include "Vaisseau.h"
#include "Planete.h"
#include "Fraise.h"
#include "Environnement.h"
#include <string>

using namespace std::string_literals;

int main(int argc, char ** argv)
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
	// Vaisseau
	Vaisseau vaisseau(100, "le vaisseau chou");

	//// Création du Golem
	Golem golem(1000, "le mechant Golem");

	//// Création de la Fraise
	Fraise Fraise(100, "La petite Fraise");

	//// Planete
	// Terre
	Planete Terre("La Terre");

	//// Autre
	// Environnement
	Environnement medium;
	float thresholdDistance = 1;

	// Affichage des ressources accumulées
	sf::Text messRessource;
	messRessource.setFont(font);
	messRessource.setCharacterSize(20);
	messRessource.setPosition(200.f, 500.f);
	messRessource.setFillColor(sf::Color::White);

	// Affichage du numéro de Jour
	sf::Text messJour;
	messJour.setFont(font);
	messJour.setCharacterSize(20);
	messJour.setPosition(300.f, 20.f);
	messJour.setFillColor(sf::Color::White);
	// Variable Jour
	int numJour = 1;

	// Timer Jour
	sf::Text Mess_Jour;
	Mess_Jour.setFont(font);
	Mess_Jour.setCharacterSize(20);
	Mess_Jour.setPosition(200.f, 20.f);
	Mess_Jour.setFillColor(sf::Color::White);

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
	sf::Text messTimerNuit;
	messTimerNuit.setFont(font);
	messTimerNuit.setCharacterSize(20);
	messTimerNuit.setPosition(400.f, 20.f);
	messTimerNuit.setFillColor(sf::Color::White);
	// Message Nuit
	sf::Text messMenuNuit;
	messMenuNuit.setFont(font);
	messMenuNuit.setCharacterSize(20);
	messMenuNuit.setPosition(150.f, 200.f);
	messMenuNuit.setFillColor(sf::Color::White);
	messMenuNuit.setString("Menu des améliorations :");
	////// Menu des améliorations
	//// Moteur
	// Bouton associé
	//Bouton Bouton_Moteur("Moteur", 350, 250, 20, 20);
	//// Structure
	// Bouton associé
	//Bouton Bouton_Structure("Structure", 350, 300, 20, 20);
	//// Drone de Soin
	// Bouton associé
	//Bouton Bouton_Drone_de_Soin("Drone de soin", 350, 350, 20, 20);
	//// Soin de clique
	// Bouton associé
	//Bouton Bouton_Soin_de_Clique("Soin de Clique", 350, 400, 20, 20);

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
	sf::Clock timerForage; // Timer pour la foreuse
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
					timerJour.restart();
					timerNuit.restart();
					timerForage.restart();
					medium.setEnvironnement();
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
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && vaisseau.eventMouse(event.mouseButton.x, event.mouseButton.y))
				{
					cout << "Soin de module par le clic" << endl;
					// Bouton Gauche == Soin
					vaisseau.recevoirSoin(1);
				}
				// Foreuse
				// Soin de clique
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Fraise.eventMouse(event.mouseButton.x, event.mouseButton.y))
				{
					Fraise.gainDEnergie(10);
				}
			}
			else
			{
				////// Gestion de la souris
				//// Bouton
				// Structure
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && vaisseau.boutonDeStructure->eventMouse(event.mouseButton.x, event.mouseButton.y))
				{
					// Test de la possibilité de l'amélioration
					if (Fraise.consommation(vaisseau.boutonDeStructure->coutEnRessource()))
					{
						vaisseau.boutonDeStructure->gainDeNiveau();
						vaisseau.gainHPMax();
					}
						
				}
				// Drone de Soin
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && vaisseau.droneDeReparation.bouton.eventMouse(event.mouseButton.x, event.mouseButton.y))
				{

					cout << "clic dans bouton drone de reparation" << endl;

					if (vaisseau.droneDeReparation.getActif())
					{
						// Est actif
						// Amélioration
						if (Fraise.consommation(vaisseau.droneDeReparation.bouton.coutEnRessource()))
						{
							vaisseau.droneDeReparation.gainDeNiveau();
						}
					}
					else
					{
						// N'est pas actif
						// Achat
						if (Fraise.consommation(vaisseau.droneDeReparation.bouton.coutEnRessource()))
						{
							vaisseau.droneDeReparation.achat();
						}
					}

				}
				// Soin de clique
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && vaisseau.boutonCliqueDeSoin->eventMouse(event.mouseButton.x, event.mouseButton.y))
				{
					if (Fraise.consommation(vaisseau.boutonCliqueDeSoin->coutEnRessource()))
					{
						vaisseau.boutonCliqueDeSoin->gainDeNiveau();
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
				if (medium.getDistance() > thresholdDistance)
				{
					medium.damagePhase(vaisseau, golem);
				}
				else
				{
					// Mise à jour des données
					// Golem attaque
					golem.infligerDegat(vaisseau, clock.getElapsedTime());
					// Fraise
					Fraise.forage(timerForage.getElapsedTime());
					Fraise.perteDEnergie(timerForage.restart());
					// Drone de reparation
					vaisseau.recevoirReparation(vaisseau.droneDeReparation.getSoin(), clock.restart());
				}
				
				// Test de l'état du vaisseau -- Module
				isPlaying = vaisseau.statut(); // a mettre dans infliger_degat

				//Module1.sePresenter();
				
				// Temps Jour
				if (timerJour.getElapsedTime() >= tJourRef)
				{
					clock.restart();
					timerJour.restart();
					timerNuit.restart();
					timerForage.restart();
					isJournee = false;
				}
			}
			else
			{
				// Temps Nuit
				if (timerNuit.getElapsedTime() >= tNuitRef)
				{
					clock.restart();
					timerJour.restart();
					timerNuit.restart();
					timerForage.restart();
					isJournee = true;
					//initialition golem / module 100% vie
					vaisseau.recevoirSoin(1000);
					// Incrément du Jour
					numJour += 1;
					// Golem gagne un niveau
					golem.gainDeNiveau(numJour);
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
				

				if (medium.getDistance() > thresholdDistance)
				{
					//// Planete
					//
					Terre.show(window);
					//// Vaisseau
					// Module 1
					// Environnement
					//medium.calculDistance(vaisseau, golem);
					medium.show(window, vaisseau, golem);

					//// UI
					sf::Time elapsed = timerJour.getElapsedTime();
					int sec = elapsed.asSeconds();
					std::string text = std::to_string(sec);
					int t_ref_Jour = tJourRef.asSeconds();
					std::string st_Timer_Jour_ref = std::to_string(t_ref_Jour);
					Mess_Jour.setString(text + " / " + st_Timer_Jour_ref + " s");
					window.draw(Mess_Jour);
					// Numéro du Jour atteint
					messJour.setString("Jour : " + std::to_string(numJour));
					window.draw(messJour);
				}
				else
				{
					//// Planete
					//
					Terre.show(window);
					//// Vaisseau
					// Module 1

					//// Golem 
					golem.show(window);
					//// Fraise
					Fraise.show(window);

					//// UI
					sf::Time elapsed = timerJour.getElapsedTime();
					int sec = elapsed.asSeconds();
					std::string text = std::to_string(sec);
					int t_ref_Jour = tJourRef.asSeconds();
					std::string st_Timer_Jour_ref = std::to_string(t_ref_Jour);
					Mess_Jour.setString(text + " / " + st_Timer_Jour_ref + " s");
					window.draw(Mess_Jour);
					// Ressources accumulées
					std::string stg_Ressources = std::to_string(trunc(Fraise.getRessource()));
					messRessource.setString("Ressources : " + stg_Ressources);
					window.draw(messRessource);
					// Numéro du Jour atteint
					messJour.setString("Jour : " + std::to_string(numJour));
					window.draw(messJour);

				}

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
				messTimerNuit.setString(text + " / " + st_Timer_Jour_ref + " s");
				window.draw(messTimerNuit);
				
				// Ressources accumulées
				std::string stg_Ressources = std::to_string(Fraise.getRessource());
				messRessource.setString("Ressources restantes : " + stg_Ressources);
				window.draw(messRessource);

				// Message Nuit
				window.draw(messMenuNuit);
				////// Menu des améliorations
				//// Moteur
				// Bouton associé
				//Bouton_Moteur.show(window, true);
				//// Structure
				// Bouton associé
				//Bouton_Structure.show(window, true);
				//// Soin de clique
				// Bouton associé
				//Bouton_Soin_de_Clique.show(window, true);
			}
			// Test Affichage
			vaisseau.show(window, isJournee);
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
