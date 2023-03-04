#include "../include/objet.hpp"

std::map<std::string, sf::Texture> Objet::textureMap = {};

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

void Objet::initialisationTexture()
{
				const std::filesystem::path chemin { "../ressources/" };
				for (auto& file : std::filesystem::directory_iterator { chemin }) // loop through the current folder
				{
								sf::Texture texture;
								texture.loadFromFile( file.path());
								textureMap.insert(std::make_pair(file.path().string(), texture));
				}
}
