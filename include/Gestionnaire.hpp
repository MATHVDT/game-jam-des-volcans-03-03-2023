#ifndef __MANAGER_HPP__
#define __MANAGER_HPP__

#include "../FRsupEN.hpp"

#include <iostream>

#include <SFML/Graphics/Texture.hpp>

#include "Contexte.hpp"
#include "armoire.hpp"
#include "ciseaux.hpp"
#include "prise.hpp"
#include "bougeable.hpp"
#include "fixe.hpp"
#include "objet.hpp"
#include "prise.hpp"
#include "inflammable.hpp"
#include "corbeille.hpp"
#include "allumette.hpp"
#include "BoutonChargerScene.hpp"
#include "issue.hpp"
#include "canape.hpp"
#include "neon.hpp"
#include "marteau.hpp"

#include <SFML/Audio.hpp>

CLASSE Gestionnaire
{
PRIVEE:
	Contexte *contexte;

PRIVEE: // Statique
	STATIQUE Gestionnaire *_instance;

PUBLIC: // Statique
	STATIQUE Gestionnaire *obtenirInstance();

PUBLIC:
	Gestionnaire();
	~Gestionnaire();

	RIEN enCours();
	RIEN initScene();

	BOOLEEN objetSelectionneSuivreSouris();
	RIEN checkEvenement(CONSTANT sf::EVENEMENT & evenement);
	BOOLEEN checkSourisSurObjet();
	BOOLEEN trouveObjetEnInteractionAvecObjetSelectionne();
	BOOLEEN interactionObjets();

	RIEN ajouteType(Objet * o, CONSTANT std::VECTEUR<Type> listMat);
};

#endif
