#ifndef __AFFICHABLE_HPP__
#define __AFFICHABLE_HPP__

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

    // Getter
    uint obtenirCouche() const;
    sf::Sprite *obtenirSprite() const;
    sf::Vector2f obtenirSpritePosition() const;

    // Setter
    void definirCouche(uint couche);
    void definirTexture(sf::Texture &texture);
    void definirSpritePosition(sf::Vector2f posistion);
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

// Getter
inline uint Affichable::obtenirCouche() const { return _couche; }
inline sf::Sprite *Affichable::obtenirSprite() const { return _sprite; }
inline sf::Vector2f Affichable::obtenirSpritePosition() const { return _sprite->getPosition(); }

// Setter
inline void Affichable::definirCouche(uint couche) { _couche = couche; }
inline void Affichable::definirTexture(sf::Texture &texture) { _sprite->setTexture(texture); }
inline void Affichable::definirSpritePosition(sf::Vector2f position) { _sprite->setPosition(position); }

#endif