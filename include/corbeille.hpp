#ifndef __CORBEILLE_HPP__
#define __CORBEILLE_HPP__

#include "../FRsupEN.hpp"

#include "fixe.hpp"

CLASSE Corbeille : PUBLIC Fixe
{
PRIVEE:
	ENTIER etat;
	RIEN miseAJour();

PUBLIC:
	Corbeille(sf::VECTEUR_NB_VIRGULE position,
			  sf::VECTEUR_NB_VIRGULE scale,
			  ENTIER_NON_SIGNE couche,
			  BOOLEEN visible);
	VIRTUEL ~Corbeille() SURCHARGE;

	RIEN clic() SURCHARGE;
	BOOLEEN estIphone() SURCHARGE;
};

#endif
