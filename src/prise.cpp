#include "../include/prise.hpp"

Prise::Prise(sf::Vector2f position,
             sf::Vector2f scale,
             sf::Texture &texture,
             uint couche,
             bool visible)
    : Fixe(position, scale, texture, couche, visible), iphone(false)
{
}

Prise::~Prise() {}

bool Prise::estIphone()
{
    return iphone;
}
