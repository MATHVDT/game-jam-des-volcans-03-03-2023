#ifndef __CISEAUX_HPP__
#define __CISEAUX_HPP__

#include "../FRsupEN.hpp"

#include "bougeable.hpp"

CLASSE Ciseaux : PUBLIC Bougeable
{
PRIVEE:
	ENTIER etat;
	RIEN miseAJour();

PUBLIC:
	Ciseaux(sf::VECTEUR_NB_VIRGULE position, sf::VECTEUR_NB_VIRGULE scale, ENTIER_NON_SIGNE couche, BOOLEEN visible);

	VIRTUEL ~Ciseaux() SURCHARGE{};
	RIEN clic() SURCHARGE;
	BOOLEEN estIphone() SURCHARGE;
};

#endif
