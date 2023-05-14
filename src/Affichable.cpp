#include "../include/Affichable.hpp"

Affichable::Affichable()
    : _lutin{NOUVEAU sf::LUTIN()},
      _couche(0) {}

Affichable::~Affichable()
{
    SUPPRIMER _lutin;
}

RIEN Affichable::definirPositionCentreSprite(CONSTANT sf::VECTEUR_NB_VIRGULE &posistion)
{
    NB_VIRGULE decalageHauteur = _lutin->OBTENIR_EXTREMITES_GLOBAL().height / 2;
    NB_VIRGULE decalageLargeur = _lutin->OBTENIR_EXTREMITES_GLOBAL().width / 2;

    definirSpritePosition(posistion - sf::VECTEUR_NB_VIRGULE(decalageLargeur, decalageHauteur));
}

/// @brief Comparateur STATIQUE
/// @param a1
/// @param a2
BOOLEEN Affichable::compare(CONSTANT Affichable &a1, CONSTANT Affichable &a2)
{
    RETOUR a1.obtenirCouche() < a2.obtenirCouche();
}

/***************************************************/
/*               Fonctions Operateurs              */
/***************************************************/
BOOLEEN operator<(CONSTANT Affichable &r1, CONSTANT Affichable &r2)
{
    RETOUR r1.obtenirCouche() < r2.obtenirCouche();
}
BOOLEEN operator>(CONSTANT Affichable &r1, CONSTANT Affichable &r2)
{
    RETOUR r1.obtenirCouche() > r2.obtenirCouche();
}
BOOLEEN operator==(CONSTANT Affichable &r1, CONSTANT Affichable &r2)
{
    RETOUR r1.obtenirCouche() == r2.obtenirCouche();
}
BOOLEEN operator<=(CONSTANT Affichable &r1, CONSTANT Affichable &r2)
{
    RETOUR r1 < r2 || r1 == r2;
}
BOOLEEN operator>=(CONSTANT Affichable &r1, CONSTANT Affichable &r2)
{
    RETOUR r1 > r2 || r1 == r2;
}
