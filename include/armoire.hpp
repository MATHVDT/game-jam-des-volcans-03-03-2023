#ifndef __ARMOIRE_HPP__
#define __ARMOIRE_HPP__

#include "../FRsupEN.hpp"

#include "bougeable.hpp"
#include "fixe.hpp"
#include "Contexte.hpp"
#include <set>

CLASSE Armoire : PUBLIC Fixe
{
PRIVEE:
	BOOLEEN estOuvert;
	std::ENSEMBLE<Bougeable *> _listeObjet;

PUBLIC:
	Armoire(sf::VECTEUR_NB_VIRGULE position,
			sf::VECTEUR_NB_VIRGULE scale,
			ENTIER_NON_SIGNE couche,
			BOOLEEN visible,
			std::ENSEMBLE<Bougeable *> listeObjet);
	VIRTUEL ~Armoire() SURCHARGE;

	RIEN clic() SURCHARGE;
	BOOLEEN estIphone() SURCHARGE { RETOUR VRAI; };
};

#endif
