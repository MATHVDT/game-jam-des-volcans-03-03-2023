#include "../include/ciseaux.hpp"

Ciseaux::Ciseaux(sf::Vector2f position,
             sf::Vector2f scale,
             sf::Texture &texture,
             uint couche,
             bool visible)
    : Bougeable(position, scale, texture, couche, visible)
{
				_materiaux.push_back(metal);
}
