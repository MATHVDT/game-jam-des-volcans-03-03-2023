#ifndef __AFFICHABLE_HPP__
#define __AFFICHABLE_HPP__

// #include "../FRsupEN.hpp"

#include <SFML/Graphics/Sprite.hpp>

class Affichable
{
private:
    sf::Sprite *_sprite;
    uint _couche;

public: // Static
    static bool compare(const Affichable &a1, const Affichable &a2);

public:
    Affichable();
    ~Affichable();

    uint obtenirCouche() const;
    sf::Sprite *obtenirSprite() const;
    const sf::Vector2f &obtenirSpritePosition() const;

    void definirCouche(uint couche);
    void definirScale(sf::Vector2f &scale);
    void definirTexture(sf::Texture &texture);
    void definirSpritePosition(const sf::Vector2f &posistion);
    void definirPositionCentreSprite(const sf::Vector2f &posistion);
};

/***************************************************/
/*               Fonctions Operateurs              */
/***************************************************/
bool operator<(const Affichable &r1, const Affichable &r2);
bool operator>(const Affichable &r1, const Affichable &r2);
bool operator==(const Affichable &r1, const Affichable &r2);
bool operator<=(const Affichable &r1, const Affichable &r2);
bool operator>=(const Affichable &r1, const Affichable &r2);

/***************************************************/
/*                 Méthodes inline                 */
/***************************************************/

// Fonction obtenir
inline uint Affichable::obtenirCouche() const { return _couche; }
inline sf::Sprite *Affichable::obtenirSprite() const { return _sprite; }
inline const sf::Vector2f &Affichable::obtenirSpritePosition() const { return _sprite->getPosition(); }

// Fonction définir
inline void Affichable::definirCouche(uint couche) { _couche = couche; }
inline void Affichable::definirTexture(sf::Texture &texture) { _sprite->setTexture(texture); }
inline void Affichable::definirSpritePosition(const sf::Vector2f &position) { _sprite->setPosition(position); }
inline void Affichable::definirScale(sf::Vector2f &scale) { _sprite->setScale(scale); }

#endif