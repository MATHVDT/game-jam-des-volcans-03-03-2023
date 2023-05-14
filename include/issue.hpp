#ifndef __ISSUUUUUUUUUE_HPP__
#define __ISSUUUUUUUUUE_HPP__

#include "../FRsupEN.hpp"

#include "fixe.hpp"

CLASSE Issue : PUBLIC Fixe
{
PRIVEE:
	BOOLEEN iphone;

PUBLIC:
	Issue(sf::VECTEUR_NB_VIRGULE position,
		  sf::VECTEUR_NB_VIRGULE scale,
		  ENTIER_NON_SIGNE couche,
		  BOOLEEN visible);
	VIRTUEL ~Issue() SURCHARGE;

	RIEN miseAJour();
	RIEN clic() SURCHARGE{};
	BOOLEEN estIphone() SURCHARGE;
};

#endif
