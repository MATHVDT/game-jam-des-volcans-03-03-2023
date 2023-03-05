#include "../include/prise.hpp"

Prise::Prise(sf::Vector2f position,
			 sf::Vector2f scale,
			 uint couche,
			 bool visible)
	: Fixe(position, scale, couche, visible), iphone(false), etat(1)
{
				_materiaux.push_back(electircite);
				_affichable.definirTexture(*textureMap["ressources/objets/prise.png"]);
}

Prise::~Prise() {}
void Prise::miseAJour()
{
	if (etat == 0)
		_affichable.definirTexture(*textureMap["ressources/objets/prise_casse.png"]);
	else if (etat == 1)
		_affichable.definirTexture(*textureMap["ressources/objets/prise.png"]);
}

bool Prise::estIphone()
{

	auto result1 = std::find(_materiaux.begin(), _materiaux.end(), metal);

	if (result1 != _materiaux.end()) {
		etat = 0;
		miseAJour();
	}
	return iphone;
}
