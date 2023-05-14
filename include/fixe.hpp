#ifndef __FIXE_HPP__
#define __FIXE_HPP__

#include "../FRsupEN.hpp"

#include "objet.hpp"

CLASSE Fixe : PUBLIC Objet
{
PRIVEE:
    BOOLEEN cassee;

PUBLIC:
    Fixe(sf::VECTEUR_NB_VIRGULE position,
         sf::VECTEUR_NB_VIRGULE scale,
         ENTIER_NON_SIGNE couche,
         BOOLEEN visible);
    VIRTUEL ~Fixe() SURCHARGE;

    RIEN clic() SURCHARGE = 0;
    BOOLEEN estIphone() SURCHARGE = 0;
};

#endif
