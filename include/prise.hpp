#ifndef __PRISE_HPP__
#define __PRISE_HPP__

#include "../FRsupEN.hpp"

#include "fixe.hpp"

CLASSE Prise : PUBLIC Fixe
{
PRIVEE:
	BOOLEEN iphone;
	ENTIER etat;

PUBLIC:
	Prise(sf::VECTEUR_NB_VIRGULE position,
		  sf::VECTEUR_NB_VIRGULE scale,
		  ENTIER_NON_SIGNE couche,
		  BOOLEEN visible);
	VIRTUEL ~Prise() SURCHARGE;

	RIEN miseAJour();
	RIEN clic() SURCHARGE{};
	BOOLEEN estIphone() SURCHARGE;
};

#endif
