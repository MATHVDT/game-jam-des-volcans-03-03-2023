#include "../include/bougeable.hpp"

void Bougeable::clic()
{
				selectionnee = !selectionnee;
}

void Bougeable::relache()
{
				selectionnee = !selectionnee;
				// appeler dans contexte pour checker la collision
}

void Bougeable::definirPosition(int haut, int gauche)
{
				definirRectangle(haut,gauche);
}

void Bougeable::remettrePosition() {
				definirPosition(position_initiale.x, position_initiale.y);
}
