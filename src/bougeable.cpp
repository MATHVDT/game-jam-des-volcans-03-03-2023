#include "../include/bougeable.hpp"

Bougeable::Bougeable(sf::VECTEUR_NB_VIRGULE position,
					 sf::VECTEUR_NB_VIRGULE scale,
					 ENTIER_NON_SIGNE couche,
					 BOOLEEN visible)
	: Objet(position, scale,
			couche,
			visible)
{
	_selectionnee = FAUX;
	_position_initiale = position;
}

Bougeable::~Bougeable() {}

RIEN Bougeable::clic()
{
	_selectionnee = VRAI;
	Contexte::obtenirInstance()->definirObjetBougeableSelectionne(this);
	_position_initiale = _affichable.obtenirSpritePosition();
}

RIEN Bougeable::relache()
{
	_selectionnee = FAUX;
	Contexte::obtenirInstance()->definirObjetBougeableSelectionne(nullptr);
	remettrePosition();
}

RIEN Bougeable::definirPosition(CONSTANT sf::VECTEUR_NB_VIRGULE &position)
{
	_affichable.definirSpritePosition(position);
}

RIEN Bougeable::definirPositionCentreSprite(CONSTANT sf::VECTEUR_NB_VIRGULE &position)
{
	_affichable.definirPositionCentreSprite(position);
}

RIEN Bougeable::remettrePosition()
{
	definirPosition(_position_initiale);
}

BOOLEEN Bougeable::estIphone()
{
	RETOUR VRAI;
}
