#include "../include/allumette.hpp"

Allumette::Allumette(sf::VECTEUR_NB_VIRGULE position,
					 sf::VECTEUR_NB_VIRGULE scale,
					 ENTIER_NON_SIGNE couche,
					 BOOLEEN visible)
	: Bougeable(position, scale, couche, visible), etat(0)
{
	_materiaux.AJOUTER_FIN(feu);
	_affichable.definirTexture(*textureCarte["ressources/objets/allumette_range.png"]);
}

RIEN Allumette::miseAJour()
{
	SI (_selectionnee == 0)
		_affichable.definirTexture(*textureCarte["ressources/objets/allumette_range.png"]);
	SINON SI (_selectionnee == 1)
		_affichable.definirTexture(*textureCarte["ressources/objets/allumette.png"]);
}

BOOLEEN Allumette::estIphone()
{

	auto result1 = std::TROUVER(_materiaux.DEBUT(), _materiaux.FIN(), papier);
	SI (result1 != _materiaux.FIN())
	{
		RETOUR VRAI;
	}
	// implemneter la destruction
	RETOUR FAUX;
}

RIEN Allumette::clic()
{
	Bougeable::clic();
	miseAJour();
}
