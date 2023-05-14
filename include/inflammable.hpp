#ifndef __INFLAMMABLE_HPP__
#define __INFLAMMABLE_HPP__

#include "../FRsupEN.hpp"

#include "bougeable.hpp"

CLASSE Inflammable : PUBLIC Bougeable
{
PRIVEE:
	ENTIER etat;
	RIEN miseAJour();

PUBLIC:
	Inflammable(sf::VECTEUR_NB_VIRGULE position, sf::VECTEUR_NB_VIRGULE scale, ENTIER_NON_SIGNE couche, BOOLEEN visible);

	VIRTUEL ~Inflammable() SURCHARGE{};
	RIEN clic() SURCHARGE;
	BOOLEEN estIphone() SURCHARGE;
};

#endif
