#include "../include/prise.hpp"

Prise::Prise(sf::VECTEUR_NB_VIRGULE position,
			 sf::VECTEUR_NB_VIRGULE scale,
			 ENTIER_NON_SIGNE couche,
			 BOOLEEN visible)
	: Fixe(position, scale, couche, visible), iphone(FAUX), etat(1)
{
	_materiaux.AJOUTER_FIN(electricite);
	_affichable.definirTexture(*textureCarte["ressources/objets/prise.png"]);
}

Prise::~Prise() {}
RIEN Prise::miseAJour()
{
	SI (etat == 0)
		_affichable.definirTexture(*textureCarte["ressources/objets/prise_casse.png"]);
	SINON SI (etat == 1)
		_affichable.definirTexture(*textureCarte["ressources/objets/prise.png"]);
}

BOOLEEN Prise::estIphone()
{
	auto result1 = std::TROUVER(_materiaux.DEBUT(), _materiaux.FIN(), metal);

	SI (result1 != _materiaux.FIN())
	{
		etat = 0;
		miseAJour();
	}
	RETOUR iphone;
}
