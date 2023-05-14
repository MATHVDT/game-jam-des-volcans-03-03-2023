#include "../include/marteau.hpp"

Marteau::Marteau(sf::VECTEUR_NB_VIRGULE position,
				 sf::VECTEUR_NB_VIRGULE scale,
				 ENTIER_NON_SIGNE couche,
				 BOOLEEN visible)
	: Bougeable(position, scale, couche, visible), etat(0)
{
	_materiaux.AJOUTER_FIN(cassant);
	_affichable.definirTexture(*textureCarte["ressources/objets/brise_vitre_range.png"]);
}

RIEN Marteau::miseAJour()
{
	SI (_selectionnee == 0)
		_affichable.definirTexture(*textureCarte["ressources/objets/brise_vitre_range.png"]);
	SINON SI (_selectionnee == 1)
		_affichable.definirTexture(*textureCarte["ressources/objets/brise_vitre_sorti.png"]);
}

BOOLEEN Marteau::estIphone()
{
	auto result1 = std::TROUVER(_materiaux.DEBUT(), _materiaux.FIN(), neon);
	SI (result1 != _materiaux.FIN())
	{
		RETOUR VRAI;
	}
	// implemneter la destruction
	RETOUR FAUX;
}

RIEN Marteau::clic()
{
	Bougeable::clic();
	miseAJour();
}
