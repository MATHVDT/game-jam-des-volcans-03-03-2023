#include "../include/inflammable.hpp"

Inflammable::Inflammable(sf::Vector2f position,
    sf::Vector2f scale,
    uint couche,
    bool visible)
    : Bougeable(position, scale, couche, visible)
    , etat(0)
{
	_materiaux.push_back(inflammable);
	_affichable.definirTexture(*textureMap["ressources/inflammable_range.png"]);
}

void Inflammable::miseAJour()
{
	if (_selectionnee == 0)
		_affichable.definirTexture(*textureMap["ressources/inflammable_range.png"]);
	else if (_selectionnee == 1)
		_affichable.definirTexture(*textureMap["ressources/inflammable.png"]);
}

bool Inflammable::estIphone()
{

	auto result1 = std::find(_materiaux.begin(), _materiaux.end(), electircite);
	if (result1 == _materiaux.end()) {}
		//implemneter la destruction 
	return true;
}

void Inflammable::clic() {
	Bougeable::clic();
	miseAJour();
}
