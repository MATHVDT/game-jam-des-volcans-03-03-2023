#ifndef __ALLUMETTE_HPP__
#define __ALLUMETTE_HPP__

#include "../FRsupEN.hpp"

#include "bougeable.hpp"

CLASSE Allumette : PUBLIC Bougeable
{
PRIVEE:
	ENTIER etat;
	RIEN miseAJour();

PUBLIC:
	Allumette(sf::VECTEUR_NB_VIRGULE position, sf::VECTEUR_NB_VIRGULE scale, ENTIER_NON_SIGNE couche, BOOLEEN visible);

	VIRTUEL ~Allumette() SURCHARGE{};
	RIEN clic() SURCHARGE;
	BOOLEEN estIphone() SURCHARGE;
};

#endif
