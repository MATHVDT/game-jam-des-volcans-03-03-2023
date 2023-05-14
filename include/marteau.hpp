#ifndef __MARTEAU_HPP__
#define __MARTEAU_HPP__

#include "../FRsupEN.hpp"

#include "bougeable.hpp"

CLASSE Marteau : PUBLIC Bougeable
{
PRIVEE:
	ENTIER etat;
	RIEN miseAJour();

PUBLIC:
	Marteau(sf::VECTEUR_NB_VIRGULE position, sf::VECTEUR_NB_VIRGULE scale, ENTIER_NON_SIGNE couche, BOOLEEN visible);

	VIRTUEL ~Marteau() SURCHARGE{};
	RIEN clic() SURCHARGE;
	BOOLEEN estIphone() SURCHARGE;
};

#endif
