#include "../include/corbeille.hpp"

Corbeille::Corbeille(sf::Vector2f position,
		sf::Vector2f scale,
		uint couche,
		bool visible)
		: Fixe(position, scale, couche, visible)
		,etat(0)
{
								_affichable.definirTexture(*textureMap["ressources/objets/corbeille.png"]);
}

Corbeille::~Corbeille() { }
void Corbeille::miseAJour()
{
				if (etat == 0)
								_affichable.definirTexture(*textureMap["ressources/objets/corbeille.png"]);
				else if (etat == 1)
								_affichable.definirTexture(*textureMap["ressources/objets/corbeille_brule.png"]);
				else if (etat == 2)
								_affichable.definirTexture(*textureMap["ressources/objets/corbeille_brule_beaucoup.png"]);
}
bool Corbeille::estIphone() { return true; }
void Corbeille::clic() { }
