#ifndef __CANAPE_HPP__
#define __CANAPE_HPP__

#include "../FRsupEN.hpp"

#include "bougeable.hpp"

CLASSE Canape : PUBLIC Bougeable
{
PRIVEE:
	ENTIER etat;
	RIEN miseAJour();

PUBLIC:
	Canape(sf::VECTEUR_NB_VIRGULE position, sf::VECTEUR_NB_VIRGULE scale, ENTIER_NON_SIGNE couche, BOOLEEN visible);

	VIRTUEL ~Canape() SURCHARGE{};
	RIEN clic() SURCHARGE;
	BOOLEEN estIphone() SURCHARGE;
};

#endif
