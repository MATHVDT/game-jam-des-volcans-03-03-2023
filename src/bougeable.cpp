#include "../include/bougeable.hpp"

Bougeable::Bougeable(sf::Vector2f position,
					 sf::Vector2f scale,
					 uint couche,
					 bool visible)
	: Objet(position, scale,
			couche,
			visible)
{
	_selectionnee = false;
	_position_initiale = position;
}

Bougeable::~Bougeable() {}

void Bougeable::clic()
{
	// _selectionnee = !_selectionnee;
	_selectionnee = true;
	Contexte::obtenirInstance()->definirObjetBougeableSelectionne(this);
	_position_initiale = _affichable.obtenirSpritePosition();
}

void Bougeable::relache()
{
	// _selectionnee = !_selectionnee;
	_selectionnee = false;
	Contexte::obtenirInstance()->definirObjetBougeableSelectionne(nullptr);
	remettrePosition();
}

void Bougeable::definirPosition(const sf::Vector2f &position)
{
	_affichable.definirSpritePosition(position);
}

void Bougeable::remettrePosition()
{
	definirPosition(_position_initiale);
}

bool Bougeable::estIphone()
{
	return true;
}
