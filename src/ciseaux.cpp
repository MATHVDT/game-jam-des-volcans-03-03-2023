#include "../include/ciseaux.hpp"

Ciseaux::Ciseaux(sf::Vector2f position,
    sf::Vector2f scale,
    uint couche,
    bool visible)
    : Bougeable(position, scale, couche, visible)
    , etat(0)
{
	_materiaux.push_back(metal);
	_affichable.definirTexture(*textureMap["ressources/objets/ciseaux_cache.png"]);
}

void Ciseaux::miseAJour()
{
	if (_selectionnee == 0)
		_affichable.definirTexture(*textureMap["ressources/objets/ciseaux_cache.png"]);
	else if (_selectionnee == 1)
		_affichable.definirTexture(*textureMap["ressources/objets/ciseaux.png"]);
}

bool Ciseaux::estIphone()
{

	auto result1 = std::find(_materiaux.begin(), _materiaux.end(), electircite);
	if (result1 != _materiaux.end()) {
				return true;}
		//implemneter la destruction 
	return false;
}

void Ciseaux::clic() {
	Bougeable::clic();
	miseAJour();
}
