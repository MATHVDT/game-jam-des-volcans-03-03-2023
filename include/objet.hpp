#ifndef __OBJET_HPP__
#define __OBJET_HPP__

#include "../FRsupEN.hpp"

#include "enum_type.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <vector>
#include <algorithm>
#include "Affichable.hpp"

#include <SFML/Graphics.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

CLASSE Objet
{
protected:
    BOOLEEN _visible;
    sf::RECTANGLE<NB_VIRGULE> _rectangle;
    Affichable _affichable;
    std::VECTEUR<Type> _materiaux;

    STATIQUE std::map<std::CHAINE, sf::Texture *> textureCarte;

PUBLIC: // Static
    STATIQUE std::map<std::CHAINE, sf::Texture *> &obtenirTextureMap();
    STATIQUE RIEN initialisationTexture();

PUBLIC:
    Objet(sf::VECTEUR_NB_VIRGULE position,
          sf::VECTEUR_NB_VIRGULE scale,
          ENTIER_NON_SIGNE couche,
          BOOLEEN visible);
    VIRTUEL ~Objet();

    VIRTUEL BOOLEEN estIphone() = 0;
    VIRTUEL RIEN clic() = 0;

    BOOLEEN obtenirVisible() CONSTANT;
    ENTIER_NON_SIGNE obtenirCouche() CONSTANT;
    sf::LUTIN *obtenirLutin() CONSTANT;
    CONSTANT sf::RECTANGLE<NB_VIRGULE> &obtenirRectangle();
    CONSTANT sf::VECTEUR_NB_VIRGULE &obtenirPosition() CONSTANT;
    CONSTANT std::VECTEUR<Type> obtenirMateriaux() CONSTANT;

    // Fonction définir
    RIEN ajouterMateriaux(Type type);

protected:
    RIEN definirRectangle(NB_VIRGULE gauche, NB_VIRGULE haut);
    RIEN definirRectangle(NB_VIRGULE gauche, NB_VIRGULE haut,
                          NB_VIRGULE largeur, NB_VIRGULE hauteur);
};

/***************************************************/
/*               Fonctions Operateurs              */
/***************************************************/
BOOLEEN operator<(CONSTANT Objet &r1, CONSTANT Objet &r2);
BOOLEEN operator>(CONSTANT Objet &r1, CONSTANT Objet &r2);
BOOLEEN operator==(CONSTANT Objet &r1, CONSTANT Objet &r2);
BOOLEEN operator<=(CONSTANT Objet &r1, CONSTANT Objet &r2);
BOOLEEN operator>=(CONSTANT Objet &r1, CONSTANT Objet &r2);

struct CompareObjetPointeur
{
    BOOLEEN operator()(Objet *o1, Objet *o2) CONSTANT
    {
        RETOUR o1->obtenirCouche() < o2->obtenirCouche();
        ;
    }
};

/***************************************************/
/*                 Méthodes EN_LIGNE                 */
/***************************************************/
EN_LIGNE sf::LUTIN *Objet::obtenirLutin() CONSTANT { RETOUR _affichable.obtenirLutin(); }
EN_LIGNE BOOLEEN Objet::obtenirVisible() CONSTANT { RETOUR _visible; }
EN_LIGNE ENTIER_NON_SIGNE Objet::obtenirCouche() CONSTANT { RETOUR _affichable.obtenirCouche(); }

#endif
