#include "../include/Fond.hpp"

Fond::Fond(std::string nom_piece, sf::Vector2f position, sf::Vector2f scale, uint couche)
	: _nom_piece(nom_piece)
{
	_affichable.definirCouche(couche);
	_affichable.definirScale(scale);
	_affichable.definirSpritePosition(position);

    _texture.loadFromFile(_nom_piece);
    definirTexture();
}

void Fond::definirTexture() {
    _affichable.definirTexture(_texture);
}