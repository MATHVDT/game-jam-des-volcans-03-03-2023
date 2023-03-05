#include "../include/objet.hpp"

std::map<std::string, sf::Texture *> Objet::textureMap = {};

Objet::Objet(sf::Vector2f position,
			 sf::Vector2f scale,
			 uint couche,
			 bool visible)
	: _visible(visible),
	  _rectangle(), _materiaux({})
{
	_affichable.definirCouche(couche);
	_affichable.definirScale(scale);
	_affichable.definirSpritePosition(position);

	definirRectangle(position.x, position.y);
}

Objet::~Objet() {}

const sf::Rect<float> &Objet::obtenirRectangle()
{
	float haut = _affichable.obtenirSprite()->getGlobalBounds().top;
	float gauche = _affichable.obtenirSprite()->getGlobalBounds().left;
	float hauteur = _affichable.obtenirSprite()->getGlobalBounds().height;
	float largeur = _affichable.obtenirSprite()->getGlobalBounds().width;
	definirRectangle(gauche, haut, hauteur, largeur);
	return _rectangle;
}

void Objet::definirRectangle(float gauche, float haut)
{
	_rectangle.left = gauche;
	_rectangle.top = haut;
}

void Objet::definirRectangle(float gauche,
							 float haut,
							 float largeur,
							 float hauteur)
{
	definirRectangle(gauche, haut);
	_rectangle.width = largeur;
	_rectangle.height = hauteur;
}

void Objet::initialisationTexture()
{
	const std::filesystem::path chemin{"ressources/"};
	for (auto &file : std::filesystem::directory_iterator{chemin}) // loop through the current folder
	{
		// std::cerr << file << std::endl;
		sf::Texture *texture = new sf::Texture();
		texture->loadFromFile(file.path());
		textureMap.insert(std::make_pair(file.path().string(), texture));
	}
}

std::map<std::string, sf::Texture *> Objet::obtenirTextureMap()
{
	return textureMap;
}

void Objet::ajouterMateriaux(Type type)
{
	_materiaux.push_back(type);
}

const std::vector<Type> Objet::obtenirMateriaux() const
{
	return _materiaux;
}
