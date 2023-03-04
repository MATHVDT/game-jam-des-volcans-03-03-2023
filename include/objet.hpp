#ifndef __OBJET_HPP__
#define __OBJET_HPP__
#include "enum_type.hpp"
#include <vector>

#include "Affichable.hpp"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <filesystem>

class Objet
{
private:
    bool _visible;
    sf::Rect<float> _rectangle;
    static std::map<std::string, sf::Texture> textureMap;

    Affichable* _affichable;

public:
    Objet(sf::Vector2f position,
          sf::Vector2f scale,
          sf::Texture &texture,
          uint couche,
          bool visible);
    virtual ~Objet();

    static void initialisationTexture();
    virtual bool estIphone() = 0;
    virtual void clic() = 0;
    const sf::Rect<float> &obtenirRectangle() const;
    void definirRectangle(float gauche, float haut);
    void definirRectangle(float gauche, float haut,
                          float largeur, float hauteur);

    sf::Sprite *obtenirSprite() const;
};

inline sf::Sprite *Objet::obtenirSprite() const { return _affichable->obtenirSprite(); }

#endif
