#include "../include/Fond.hpp"

std::map<std::CHAINE, sf::Texture *> Fond::texturesFond = {};

Fond::Fond(std::CHAINE nom_piece, sf::VECTEUR_NB_VIRGULE position, sf::VECTEUR_NB_VIRGULE scale, ENTIER_NON_SIGNE couche)
	: _nom_piece(nom_piece)
{
	_affichable.definirCouche(couche);
	_affichable.definirScale(scale);
	_affichable.definirSpritePosition(position);

	// std::SORTIE_ERREUR << nom_piece << std::RETOUR_CHARIOT;
	definirTexture(*texturesFond[nom_piece]);
}

RIEN Fond::definirTexture(sf::Texture &texture)
{
	_affichable.definirTexture(texture);
}

std::map<std::CHAINE, sf::Texture *> &Fond::obtenirTexturesFond()
{
	RETOUR texturesFond;
}

RIEN Fond::initialisationTexture()
{
	CONSTANT std::filesystem::path chemin{"ressources/fonds/"};
	POUR (auto &file : std::filesystem::directory_iterator{chemin}) // loop through the current folder
	{
		// std::SORTIE_ERREUR << file << std::RETOUR_CHARIOT;
		sf::Texture *texture = NOUVEAU sf::Texture();
		texture->loadFromFile(file.path());
		texturesFond.insert(std::make_pair(file.path().CHAINE(), texture));
	}
}
