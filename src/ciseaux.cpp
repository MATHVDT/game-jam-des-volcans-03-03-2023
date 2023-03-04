#include "../include/ciseaux.hpp"

Ciseaux::Ciseaux(sf::Vector2f position,
                 sf::Vector2f scale,
                 uint couche,
                 bool visible)
    : Bougeable(position, scale, couche, visible)
{
    _materiaux.push_back(metal);
    _affichable.definirTexture(*textureMap["ressources/ciseaux.png"]);
}
