#include "../include/armoire.hpp"
#include <set>

Armoire::Armoire(sf::Vector2f position,
    sf::Vector2f scale,
    uint couche,
    bool visible,
    std::set<Bougeable*> lisetObjet)
    : Fixe(position, scale, couche, visible)
    , estOuvert(false), _listeObjet(lisetObjet)
{
	_affichable.definirTexture(*textureMap["ressources/armoire_ferme.png"]);
}

Armoire::~Armoire() { }

void Armoire::clic()
{
	estOuvert = !estOuvert;
	if (estOuvert) {
		_affichable.definirTexture(*textureMap["ressources/armoire_ouvert.png"]);
		auto contexte = Contexte::obtenirInstance();
		for (auto& objet : _listeObjet) {
			contexte->ajouterAffichable(contexte->obtenirSceneChargee(), objet);
		}
		_listeObjet.clear();
	}
		else _affichable.definirTexture(*textureMap["ressources/armoire_ferme.png"]);
}
