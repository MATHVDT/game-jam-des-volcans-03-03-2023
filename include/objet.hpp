#ifndef __OBJET_HPP__
#define __OBJET_HPP__
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "enum_type.hpp"
#include <vector>
#include <map>
#include <string>
#include <filesystem>
class Objet
{
private:
    bool visible;
    sf::Rect<int> rectangle;
    sf::Sprite sprite;
	//	static std::map<std::string, sf::Texture> texture;

public:
		static void initialisationTexture();
    virtual bool estIphone() = 0;
    virtual void clic() = 0;
    const sf::Rect<int> &obtenirRectangle() const;
    void definirRectangle(int gauche, int haut);
    void definirRectangle(int gauche, int haut, int largeur, int hauteur);
};

#endif
