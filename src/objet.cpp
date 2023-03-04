#include "../include/objet.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderStates.hpp>

// std::map<std::string, sf::Texture> Objet::texture = {};

Objet::Objet(sf::Vector2f position,
			 sf::Vector2f scale,
			 sf::Texture &texture,
			 uint couche,
			 bool visible)
	: _visible(visible),
	  _rectangle(),
	  _affichable(new Affichable())
{
	_affichable->definirTexture(texture);
	_affichable->definirCouche(couche);
	_affichable->definirSpritePosition(position);

	definirRectangle(position.x, position.y);
}

Objet::~Objet() {}

const sf::Rect<float> &Objet::obtenirRectangle() const
{
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

/*void static Objet::initialisationTexture()
{
				const std::filesystem::path chemin { "../ressources/" };
				for (auto& file : std::filesystem::directory_iterator { chemin }) // loop through the current folder
				{ }
}*/
