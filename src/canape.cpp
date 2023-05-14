#include "../include/canape.hpp"

Canape::Canape(sf::VECTEUR_NB_VIRGULE position,
			   sf::VECTEUR_NB_VIRGULE scale,
			   ENTIER_NON_SIGNE couche,
			   BOOLEEN visible)
	: Bougeable(position, scale, couche, visible), etat(0)
{
	_materiaux.AJOUTER_FIN(encombrant);
	_affichable.definirTexture(*textureCarte["ressources/objets/canape_ignifuge.png"]);
}

RIEN Canape::miseAJour() {}

BOOLEEN Canape::estIphone()
{
	auto result1 = std::TROUVER(_materiaux.DEBUT(), _materiaux.FIN(), electricite);
	SI (result1 != _materiaux.FIN())
	{
		RETOUR VRAI;
	}
	// implemneter la destruction
	RETOUR FAUX;
}

RIEN Canape::clic()
{
	Bougeable::clic();
	miseAJour();
}
