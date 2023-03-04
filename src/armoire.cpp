#include "../include/armoire.hpp"

Armoire::Armoire(sf::Vector2f position,
				 sf::Vector2f scale,
				 sf::Texture &texture,
				 uint couche,
				 bool visible)
	: Fixe(position, scale, texture, couche, visible)

{
}

Armoire::~Armoire() {}

void Armoire::clic()
{
	estOuvert = !estOuvert;
	// changer le srpite
}
