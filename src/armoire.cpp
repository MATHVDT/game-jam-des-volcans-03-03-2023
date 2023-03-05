#include "../include/armoire.hpp"

Armoire::Armoire(sf::Vector2f position,
				 sf::Vector2f scale,
				 uint couche,
				 bool visible)
	: Fixe(position, scale, couche, visible),
	estOuvert(false)
{
		_affichable.definirTexture(*textureMap["ressources/objets/armoire_ferme.png"]);
}

Armoire::~Armoire() {}

void Armoire::clic()
{
	estOuvert = !estOuvert;
	if (estOuvert)
		_affichable.definirTexture(*textureMap["ressources/objets/armoire_ouvert.png"]);
	else
		_affichable.definirTexture(*textureMap["ressources/objets/armoire_ferme.png"]);
}
