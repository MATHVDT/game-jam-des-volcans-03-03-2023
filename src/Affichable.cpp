#include "../include/Affichable.hpp"

Affichable::Affichable()
    : _sprite{new sf::Sprite()},
      _couche(0) {}

Affichable::~Affichable()
{
    delete _sprite;
}

void Affichable::definirPositionCentreSprite(const sf::Vector2f &posistion)
{
    float decalageHauteur = _sprite->getGlobalBounds().height / 2;
    float decalageLargeur = _sprite->getGlobalBounds().width / 2;

    definirSpritePosition(posistion - sf::Vector2f(decalageLargeur, decalageHauteur));
}

/// @brief Comparateur static
/// @param a1
/// @param a2
/// @return
bool Affichable::compare(const Affichable &a1, const Affichable &a2)
{
    return a1.obtenirCouche() < a2.obtenirCouche();
}

/***************************************************/
/*               Fonctions Operateurs              */
/***************************************************/
bool operator<(const Affichable &r1, const Affichable &r2)
{
    return r1.obtenirCouche() < r2.obtenirCouche();
}
bool operator>(const Affichable &r1, const Affichable &r2)
{
    return r1.obtenirCouche() > r2.obtenirCouche();
}
bool operator==(const Affichable &r1, const Affichable &r2)
{
    return r1.obtenirCouche() == r2.obtenirCouche();
}
bool operator<=(const Affichable &r1, const Affichable &r2)
{
    return r1 < r2 || r1 == r2;
}
bool operator>=(const Affichable &r1, const Affichable &r2)
{
    return r1 > r2 || r1 == r2;
}
