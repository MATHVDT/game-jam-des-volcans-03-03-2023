#ifndef __OBJET_HPP__
#define __OBJET_HPP__
#include "enum_type.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
class Objet {
		private:
				std::string name;
				bool visible;
				sf::Rect<int> rectangle;
				sf::Sprite sprite;
				static std::map<std::string, sf::Texture> textureMap;

		public:
				static void initialisationTexture();
				Objet(std::string name);
				virtual bool estIphone() = 0;
				virtual void clic() = 0;
				const sf::Rect<int>& obtenirRectangle() const;
				void definirRectangle(int gauche, int haut);
				void definirRectangle(int gauche, int haut, int largeur, int hauteur);
};

#endif
