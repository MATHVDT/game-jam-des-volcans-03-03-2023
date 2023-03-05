#include "../include/allumette.hpp"

Allumette::Allumette(sf::Vector2f position,
    sf::Vector2f scale,
    uint couche,
    bool visible)
    : Bougeable(position, scale, couche, visible)
    , etat(0)
{
	_materiaux.push_back(feu);
	_affichable.definirTexture(*textureMap["ressources/allumette_range.png"]);
}

void Allumette::miseAJour()
{
	if (_selectionnee == 0)
		_affichable.definirTexture(*textureMap["ressources/allumette_range.png"]);
	else if (_selectionnee == 1)
		_affichable.definirTexture(*textureMap["ressources/allumette.png"]);
}

bool Allumette::estIphone()
{

	auto result1 = std::find(_materiaux.begin(), _materiaux.end(), electircite);
	if (result1 == _materiaux.end()) {}
		//implemneter la destruction 
	return true;
}

void Allumette::clic() {
	Bougeable::clic();
	miseAJour();
}
