#ifndef _INCLUDE_FOND_HPP
#define _INCLUDE_FOND_HPP

#include "enum_type.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <vector>

#include "Affichable.hpp"
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

class Fond
{
private:
    Affichable _affichable;
    sf::Vector2<float> _position;
    std::string _nom_piece;

public: // Static
    static std::map<std::string, sf::Texture *> texturesFond;
    

public: // Static
    static std::map<std::string, sf::Texture *>& obtenirTexturesFond();
    static void initialisationTexture();

public:
    Fond(std::string nom_piece, sf::Vector2f position, sf::Vector2f scale, uint couche);
    ~Fond() = default;

    void definirTexture(sf::Texture& texture);

    sf::Sprite *obtenirSprite() const;
};

inline sf::Sprite *Fond::obtenirSprite() const { return _affichable.obtenirSprite(); }

#endif