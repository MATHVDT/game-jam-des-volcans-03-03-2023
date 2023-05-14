#include "../include/issue.hpp"

Issue::Issue(sf::VECTEUR_NB_VIRGULE position,
			 sf::VECTEUR_NB_VIRGULE scale,
			 ENTIER_NON_SIGNE couche,
			 BOOLEEN visible)
	: Fixe(position, scale, couche, visible), iphone(FAUX)
{
	_materiaux.AJOUTER_FIN(issue_secours);
	_affichable.definirTexture(*textureCarte["ressources/objets/issue_de_secours.png"]);
}

Issue::~Issue() {}
RIEN Issue::miseAJour() {}

BOOLEEN Issue::estIphone()
{
	auto result1 = std::TROUVER(_materiaux.DEBUT(), _materiaux.FIN(), encombrant);

	SI (result1 != _materiaux.FIN())
	{
		miseAJour();
	}
	RETOUR FAUX;
}
