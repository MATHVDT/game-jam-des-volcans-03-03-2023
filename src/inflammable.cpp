#include "../include/inflammable.hpp"

Inflammable::Inflammable(sf::VECTEUR_NB_VIRGULE position,
						 sf::VECTEUR_NB_VIRGULE scale,
						 ENTIER_NON_SIGNE couche,
						 BOOLEEN visible)
	: Bougeable(position, scale, couche, visible), etat(0)
{
	_materiaux.AJOUTER_FIN(inflammable);
	_affichable.definirTexture(*textureCarte["ressources/objets/inflammable_range.png"]);
}

RIEN Inflammable::miseAJour()
{
	SI(_selectionnee == 0)
	_affichable.definirTexture(*textureCarte["ressources/objets/inflammable_range.png"]);
	SINON SI(_selectionnee == 1)
		_affichable.definirTexture(*textureCarte["ressources/objets/inflammable.png"]);
}

BOOLEEN Inflammable::estIphone()
{
	auto result1 = std::TROUVER(_materiaux.DEBUT(), _materiaux.FIN(), feu);
	SI(result1 != _materiaux.FIN())
	{
		RETOUR VRAI;
	}
	// implemneter la destruction
	RETOUR FAUX;
}

RIEN Inflammable::clic()
{
	Bougeable::clic();
	miseAJour();
}
