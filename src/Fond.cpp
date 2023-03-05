#include "../include/Fond.hpp"

std::map<std::string, sf::Texture *> Fond::texturesFond = {};

Fond::Fond(std::string nom_piece, sf::Vector2f position, sf::Vector2f scale, uint couche)
	: _nom_piece(nom_piece)
{
	_affichable.definirCouche(couche);
	_affichable.definirScale(scale);
	_affichable.definirSpritePosition(position);

	// std::cerr << nom_piece << std::endl;
	definirTexture(*texturesFond[nom_piece]);
}

void Fond::definirTexture(sf::Texture &texture)
{
	_affichable.definirTexture(texture);
}

std::map<std::string, sf::Texture *> Fond::obtenirTexturesFond()
{
	return texturesFond;
}

void Fond::initialisationTexture()
{
	const std::filesystem::path chemin{"ressources/fonds/"};
	for (auto &file : std::filesystem::directory_iterator{chemin}) // loop through the current folder
	{
		// std::cerr << file << std::endl;
		sf::Texture *texture = new sf::Texture();
		texture->loadFromFile(file.path());
		texturesFond.insert(std::make_pair(file.path().string(), texture));
	}
}
