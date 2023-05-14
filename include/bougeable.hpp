#ifndef __BOUGEABLE_HPP__
#define __BOUGEABLE_HPP__

#include "../FRsupEN.hpp"

#include "Contexte.hpp"
#include "objet.hpp"

CLASSE Bougeable : PUBLIC Objet
{
protected:
	BOOLEEN _selectionnee;
	sf::VECTEUR_NB_VIRGULE _position_initiale;

PUBLIC:
	Bougeable(sf::VECTEUR_NB_VIRGULE position,
			  sf::VECTEUR_NB_VIRGULE scale,
			  ENTIER_NON_SIGNE couche,
			  BOOLEEN visible);
	VIRTUEL ~Bougeable() SURCHARGE;

	VIRTUEL BOOLEEN estIphone() SURCHARGE;
	RIEN remettrePosition();
	RIEN relache();
	RIEN definirPosition(CONSTANT sf::VECTEUR_NB_VIRGULE &position);
	RIEN definirPositionCentreSprite(CONSTANT sf::VECTEUR_NB_VIRGULE &position);
	RIEN clic() SURCHARGE;
};

#endif
