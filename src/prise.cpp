#include "../include/prise.hpp"

Prise::Prise(sf::Vector2f position,
             sf::Vector2f scale,
             uint couche,
             bool visible)
    : Fixe(position, scale, couche, visible), iphone(false)
{
				_materiaux.push_back(electircite);
								_affichable.definirTexture(*textureMap["ressources/prise.png"]);
}

Prise::~Prise() {}

bool Prise::estIphone()
{
    return iphone;
}
