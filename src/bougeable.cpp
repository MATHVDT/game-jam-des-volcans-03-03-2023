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

Bougeable::~Bougeable()
{
}

void Bougeable::clic()
{
	_selectionnee = !_selectionnee;
}

void Bougeable::relache()
{
	_selectionnee = !_selectionnee;
	// appeler dans contexte pour checker la collision
}

void Bougeable::definirPosition(float haut, float gauche)
{
	definirRectangle(haut, gauche);
}

void Bougeable::remettrePosition()
{
	definirPosition(_position_initiale.x, _position_initiale.y);
}

bool Bougeable::estIphone()
{
	return true;
}
