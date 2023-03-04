#include "../include/fixe.hpp"

Fixe::Fixe(sf::Vector2f position,
           sf::Vector2f scale,
           uint couche,
           bool visible)
    : Objet(position, scale,
         couche,
            visible)
{
}

Fixe::~Fixe() {}
