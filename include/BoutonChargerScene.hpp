#ifndef __BOUTON_CHARGER_SCENE__
#define __BOUTON_CHARGER_SCENE__

#include "../FRsupEN.hpp"

#include "fixe.hpp"
#include "Contexte.hpp"

CLASSE BoutonChargerScene : PUBLIC Fixe
{
PRIVEE:
    ENTIER_NON_SIGNE _numeroScene;

PUBLIC:
    BoutonChargerScene(sf::VECTEUR_NB_VIRGULE position,
                       sf::VECTEUR_NB_VIRGULE scale,
                       ENTIER_NON_SIGNE couche, BOOLEEN visible,
                       ENTIER_NON_SIGNE numeroScene, std::CHAINE cleTextureScene);
    ~BoutonChargerScene();

    RIEN clic() SURCHARGE;
    BOOLEEN estIphone() SURCHARGE { RETOUR FAUX; }
};

#endif