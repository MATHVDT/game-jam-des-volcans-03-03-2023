#ifndef __AFFICHABLE_HPP__
#define __AFFICHABLE_HPP__

#include "../FRsupEN.hpp"

#include <SFML/Graphics/Sprite.hpp>

CLASSE Affichable
{
PRIVEE:
    sf::LUTIN *_lutin;
    ENTIER_NON_SIGNE _couche;

PUBLIC: // Static
    STATIQUE BOOLEEN compare(CONSTANT Affichable &a1, CONSTANT Affichable &a2);

PUBLIC:
    Affichable();
    ~Affichable();

    ENTIER_NON_SIGNE obtenirCouche() CONSTANT;
    sf::LUTIN *obtenirLutin() CONSTANT;
    CONSTANT sf::VECTEUR_NB_VIRGULE &obtenirSpritePosition() CONSTANT;

    RIEN definirCouche(ENTIER_NON_SIGNE couche);
    RIEN definirScale(sf::VECTEUR_NB_VIRGULE &scale);
    RIEN definirTexture(sf::Texture &texture);
    RIEN definirSpritePosition(CONSTANT sf::VECTEUR_NB_VIRGULE &posistion);
    RIEN definirPositionCentreSprite(CONSTANT sf::VECTEUR_NB_VIRGULE &posistion);
};

/***************************************************/
/*               Fonctions Operateurs              */
/***************************************************/
BOOLEEN operator<(CONSTANT Affichable &r1, CONSTANT Affichable &r2);
BOOLEEN operator>(CONSTANT Affichable &r1, CONSTANT Affichable &r2);
BOOLEEN operator==(CONSTANT Affichable &r1, CONSTANT Affichable &r2);
BOOLEEN operator<=(CONSTANT Affichable &r1, CONSTANT Affichable &r2);
BOOLEEN operator>=(CONSTANT Affichable &r1, CONSTANT Affichable &r2);

/***************************************************/
/*                 Méthodes EN_LIGNE                 */
/***************************************************/

// Fonction obtenir
EN_LIGNE ENTIER_NON_SIGNE Affichable::obtenirCouche() CONSTANT { RETOUR _couche; }
EN_LIGNE sf::LUTIN *Affichable::obtenirLutin() CONSTANT { RETOUR _lutin; }
EN_LIGNE CONSTANT sf::VECTEUR_NB_VIRGULE &Affichable::obtenirSpritePosition() CONSTANT { RETOUR _lutin->OBTENIR_POSITION(); }

// Fonction définir
EN_LIGNE RIEN Affichable::definirCouche(ENTIER_NON_SIGNE couche) { _couche = couche; }
EN_LIGNE RIEN Affichable::definirTexture(sf::Texture &texture) { _lutin->setTexture(texture); }
EN_LIGNE RIEN Affichable::definirSpritePosition(CONSTANT sf::VECTEUR_NB_VIRGULE &position) { _lutin->setPosition(position); }
EN_LIGNE RIEN Affichable::definirScale(sf::VECTEUR_NB_VIRGULE &scale) { _lutin->setScale(scale); }

#endif