#include "../include/fixe.hpp"

Fixe::Fixe(sf::Vector2f position,
           sf::Vector2f scale,
           sf::Texture &texture,
           uint couche,
           bool visible)
    : Objet(position, scale,
            texture, couche,
            visible)
{
}

Fixe::~Fixe() {}