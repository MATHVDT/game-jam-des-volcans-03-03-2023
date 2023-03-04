#include "../include/objet.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderStates.hpp>

//std::map<std::string, sf::Texture> Objet::texture = {};

const sf::Rect<int>& Objet::obtenirRectangle() const
{
				return rectangle;
}

void Objet::definirRectangle(int gauche, int haut)
{
				rectangle.left = gauche;
				rectangle.top = haut;
}

void Objet::definirRectangle(int gauche, int haut, int largeur, int hauteur)
{
				definirRectangle(gauche, haut);
				rectangle.width = largeur;
				rectangle.height = hauteur;
}

/*void static Objet::initialisationTexture()
{
				const std::filesystem::path chemin { "../ressources/" };
				for (auto& file : std::filesystem::directory_iterator { chemin }) // loop through the current folder
				{ }
}*/
