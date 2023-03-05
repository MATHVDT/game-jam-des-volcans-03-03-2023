#include "../include/marteau.hpp"

Marteau::Marteau(sf::Vector2f position,
    sf::Vector2f scale,
    uint couche,
    bool visible)
    : Bougeable(position, scale, couche, visible)
    , etat(0)
{
	_materiaux.push_back(cassant);
	_affichable.definirTexture(*textureMap["ressources/objets/brise_vitre_range.png"]);
}

void Marteau::miseAJour()
{
	if (_selectionnee == 0)
		_affichable.definirTexture(*textureMap["ressources/objets/brise_vitre_range.png"]);
	else if (_selectionnee == 1)
		_affichable.definirTexture(*textureMap["ressources/objets/brise_vitre_sorti.png"]);
}

bool Marteau::estIphone()
{

	auto result1 = std::find(_materiaux.begin(), _materiaux.end(), neon);
	if (result1 != _materiaux.end()) {
				return true;}
		//implemneter la destruction 
	return false;
}

void Marteau::clic() {
	Bougeable::clic();
	miseAJour();
}
