#include "../include/corbeille.hpp"

Corbeille::Corbeille(sf::VECTEUR_NB_VIRGULE position,
					 sf::VECTEUR_NB_VIRGULE scale,
					 ENTIER_NON_SIGNE couche,
					 BOOLEEN visible)
	: Fixe(position, scale, couche, visible), etat(0)
{
	_materiaux.AJOUTER_FIN(papier);
	_affichable.definirTexture(*textureCarte["ressources/objets/corbeille.png"]);
}

Corbeille::~Corbeille() {}
RIEN Corbeille::miseAJour()
{
	SI (etat == 0)
		_affichable.definirTexture(*textureCarte["ressources/objets/corbeille.png"]);
	SINON SI (etat == 1)
		_affichable.definirTexture(*textureCarte["ressources/objets/corbeille_brule.png"]);
	SINON SI (etat == 2)
		_affichable.definirTexture(*textureCarte["ressources/objets/corbeille_brule_beaucoup.png"]);
}
BOOLEEN Corbeille::estIphone()
{
	auto result1 = std::TROUVER(_materiaux.DEBUT(), _materiaux.FIN(), feu);
	auto result2 = std::TROUVER(_materiaux.DEBUT(), _materiaux.FIN(), inflammable);

	SI (result1 != _materiaux.FIN())
	{
		SI (result2 != _materiaux.FIN())
		{
			etat = 2;
		}
		SINON
			etat = 1;
	}
	miseAJour();
	RETOUR VRAI;
}
RIEN Corbeille::clic() {}
