#include "../include/Affichable.hpp"

Affichable::Affichable(uint couche, sf::Sprite s)
{
    _sprite = s;
    _couche = couche;
}

Affichable::Affichable()
    : _sprite{}, _couche(0) {}

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