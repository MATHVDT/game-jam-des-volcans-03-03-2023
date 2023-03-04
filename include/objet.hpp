#ifndef __OBJET_HPP__
#define __OBJET_HPP__
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "../include/Affichable.hpp"

class Objet
{
private:
    bool visible;
    sf::Rect<int> rectangle;
    sf::Sprite sprite;

    Affichable _affichable;

public:
    virtual bool estIphone() = 0;
    virtual void clic() = 0;
    const sf::Rect<int> &obtenirRectangle() const;
    void definirRectangle(int gauche, int haut);
    void definirRectangle(int gauche, int haut, int largeur, int hauteur);

    sf::Sprite *obtenirSprite() const;
};

inline sf::Sprite *Objet::obtenirSprite() const { return _affichable.obtenirSprite(); }

#endif
