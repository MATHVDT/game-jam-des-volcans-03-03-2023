#include "../include/corbeille.hpp"

Corbeille::Corbeille(sf::Vector2f position,
		sf::Vector2f scale,
		sf::Texture& texture,
		uint couche,
		bool visible)
		: Fixe(position, scale, texture, couche, visible)
		, etat(0)
{
}

Corbeille::~Corbeille() { }
void Corbeille::miseAJour()
{
				if (etat == 0)
								_affichable.definirTexture(*textureMap["ressources/armoire_ouvert.png"]);
				else if (etat == 1)
								_affichable.definirTexture(*textureMap["ressources/armoire_ouvert.png"]);
				else if (etat == 2)
								_affichable.definirTexture(*textureMap["ressources/armoire_ouvert.png"]);
}
bool Corbeille::estIphone() { return true; }
void Corbeille::clic() { }
