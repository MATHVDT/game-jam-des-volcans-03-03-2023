#include "../include/armoire.hpp"

Armoire::Armoire(sf::VECTEUR_NB_VIRGULE position,
				 sf::VECTEUR_NB_VIRGULE scale,
				 ENTIER_NON_SIGNE couche,
				 BOOLEEN visible,
				 std::ENSEMBLE<Bougeable *> lisetObjet)
	: Fixe(position, scale, couche, visible), estOuvert(FAUX), _listeObjet(lisetObjet)
{
	_affichable.definirTexture(*textureCarte["ressources/objets/armoire_ferme.png"]);
}

Armoire::~Armoire() {}

RIEN Armoire::clic()
{
	estOuvert = !estOuvert;
	SI (estOuvert)
	{
		_affichable.definirTexture(*textureCarte["ressources/objets/armoire_ouvert.png"]);
		auto contexte = Contexte::obtenirInstance();
		POUR (auto &objet : _listeObjet)
		{
			contexte->ajouterAffichable(contexte->obtenirSceneChargee(), objet);
		}
		_listeObjet.EFFACER();
	}
	SINON
		_affichable.definirTexture(*textureCarte["ressources/objets/armoire_ferme.png"]);
}
