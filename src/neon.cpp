#include "../include/neon.hpp"

Neon::Neon(sf::VECTEUR_NB_VIRGULE position,
		   sf::VECTEUR_NB_VIRGULE scale,
		   ENTIER_NON_SIGNE couche,
		   BOOLEEN visible)
	: Fixe(position, scale, couche, visible), iphone(FAUX), etat(1)
{
	_materiaux.AJOUTER_FIN(neon);
	_affichable.definirTexture(*textureCarte["ressources/objets/neon.png"]);
}

Neon::~Neon() {}

RIEN Neon::miseAJour()
{
	SI (etat == 0)
		_affichable.definirTexture(*textureCarte["ressources/objets/neon_casse.png"]);
	SINON SI (etat == 1)
		_affichable.definirTexture(*textureCarte["ressources/objets/neon.png"]);
}

BOOLEEN Neon::estIphone()
{
	auto result1 = std::TROUVER(_materiaux.DEBUT(), _materiaux.FIN(), cassant);

	SI (result1 != _materiaux.FIN())
	{
		etat = 0;
		miseAJour();
	}
	RETOUR iphone;
}
