#include "../include/neon.hpp"

Neon::Neon(sf::Vector2f position,
    sf::Vector2f scale,
    uint couche,
    bool visible)
    : Fixe(position, scale, couche, visible)
    , iphone(false)
    , etat(1)
{
				_materiaux.push_back(neon);
				_affichable.definirTexture(*textureMap["ressources/objets/neon.png"]);
}

Neon::~Neon() { }
void Neon::miseAJour()
{
	if (etat == 0)
		_affichable.definirTexture(*textureMap["ressources/objets/neon_casse.png"]);
	else if (etat == 1)
		_affichable.definirTexture(*textureMap["ressources/objets/neon.png"]);
}

bool Neon::estIphone()
{

	auto result1 = std::find(_materiaux.begin(), _materiaux.end(), cassant);

	if (result1 != _materiaux.end()) {
		etat = 0;
		miseAJour();
	}
	return iphone;
}
