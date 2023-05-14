#include "../include/ciseaux.hpp"

Ciseaux::Ciseaux(sf::VECTEUR_NB_VIRGULE position,
				 sf::VECTEUR_NB_VIRGULE scale,
				 ENTIER_NON_SIGNE couche,
				 BOOLEEN visible)
	: Bougeable(position, scale, couche, visible), etat(0)
{
	_materiaux.AJOUTER_FIN(metal);
	_affichable.definirTexture(*textureCarte["ressources/objets/ciseaux_cache.png"]);
}

RIEN Ciseaux::miseAJour()
{
	SI (_selectionnee == 0)
		_affichable.definirTexture(*textureCarte["ressources/objets/ciseaux_cache.png"]);
	SINON SI (_selectionnee == 1)
		_affichable.definirTexture(*textureCarte["ressources/objets/ciseaux.png"]);
}

BOOLEEN Ciseaux::estIphone()
{

	auto result1 = std::TROUVER(_materiaux.DEBUT(), _materiaux.FIN(), electricite);
	SI (result1 != _materiaux.FIN())
	{
		RETOUR VRAI;
	}
	// implemneter la destruction
	RETOUR FAUX;
}

RIEN Ciseaux::clic()
{
	Bougeable::clic();
	miseAJour();
}
