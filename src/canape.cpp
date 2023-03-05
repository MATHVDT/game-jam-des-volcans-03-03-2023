#include "../include/canape.hpp"

Canape::Canape(sf::Vector2f position,
    sf::Vector2f scale,
    uint couche,
    bool visible)
    : Bougeable(position, scale, couche, visible)
    , etat(0)
{
	_materiaux.push_back(encombrant);
	_affichable.definirTexture(*textureMap["ressources/objets/canape_ignufue.png"]);
}

void Canape::miseAJour()
{
}

bool Canape::estIphone()
{

	auto result1 = std::find(_materiaux.begin(), _materiaux.end(), electircite);
	if (result1 != _materiaux.end()) {
				return true;}
		//implemneter la destruction 
	return false;
}

void Canape::clic() {
	Bougeable::clic();
	miseAJour();
}
