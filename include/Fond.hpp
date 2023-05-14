#ifndef __FOND_HPP__
#define __FOND_HPP__

#include "../FRsupEN.hpp"

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

CLASSE Fond
{
PRIVEE:
    Affichable _affichable;
    sf::VECTEUR_NB_VIRGULE _position;
    std::CHAINE _nom_piece;

PUBLIC: // Static
    STATIQUE std::map<std::CHAINE, sf::Texture *> texturesFond;

PUBLIC: // Static
    STATIQUE std::map<std::CHAINE, sf::Texture *> &obtenirTexturesFond();
    STATIQUE RIEN initialisationTexture();

PUBLIC:
    Fond(std::CHAINE nom_piece, sf::VECTEUR_NB_VIRGULE position, sf::VECTEUR_NB_VIRGULE scale, ENTIER_NON_SIGNE couche);
    ~Fond() = DEFAUT;

    RIEN definirTexture(sf::Texture &texture);

    sf::LUTIN *obtenirLutin() CONSTANT;
};

EN_LIGNE sf::LUTIN *Fond::obtenirLutin() CONSTANT { RETOUR _affichable.obtenirLutin(); }

#endif