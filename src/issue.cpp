#include "../include/issue.hpp"

Issue::Issue(sf::Vector2f position,
    sf::Vector2f scale,
    uint couche,
    bool visible)
    : Fixe(position, scale, couche, visible)
    , iphone(false)
{
				_materiaux.push_back(issue_secours);
				_affichable.definirTexture(*textureMap["ressources/objets/issue_de_secours.png"]);
}

Issue::~Issue() { }
void Issue::miseAJour()
{
}

bool Issue::estIphone()
{

	auto result1 = std::find(_materiaux.begin(), _materiaux.end(), encombrant);

	if (result1 != _materiaux.end()) {
		miseAJour();
	}
	return false;
}
