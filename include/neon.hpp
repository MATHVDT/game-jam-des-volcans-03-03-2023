#ifndef __NEON_HPP__
#define __NEON_HPP__

#include "../FRsupEN.hpp"

#include "bougeable.hpp"
#include "fixe.hpp"
#include "Contexte.hpp"
#include <set>

CLASSE Neon : PUBLIC Fixe
{
PRIVEE:
	BOOLEEN estOuvert;
	BOOLEEN iphone;
	ENTIER etat;

PUBLIC:
	Neon(sf::VECTEUR_NB_VIRGULE position,
		 sf::VECTEUR_NB_VIRGULE scale,
		 ENTIER_NON_SIGNE couche,
		 BOOLEEN visible);
	VIRTUEL ~Neon() SURCHARGE;

	RIEN clic() SURCHARGE{};
	BOOLEEN estIphone() SURCHARGE;
	RIEN miseAJour();
};

#endif
