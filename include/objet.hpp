#ifndef __OBJET_HPP__
#define __OBJET_HPP__

// #include "../FRsupEN.hpp"

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

class Objet
{
protected:
    bool _visible;
    sf::Rect<float> _rectangle;
    Affichable _affichable;
    std::vector<Type> _materiaux;

    static std::map<std::string, sf::Texture *> textureCarte;

public: // Static
    static std::map<std::string, sf::Texture *> &obtenirTextureMap();
    static void initialisationTexture();

public:
    Objet(sf::Vector2f position,
          sf::Vector2f scale,
          uint couche,
          bool visible);
    virtual ~Objet();

    virtual bool estIphone() = 0;
    virtual void clic() = 0;

    bool obtenirVisible() const;
    uint obtenirCouche() const;
    sf::Sprite *obtenirSprite() const;
    const sf::Rect<float> &obtenirRectangle();
    const sf::Vector2f &obtenirPosition() const;
    const std::vector<Type> obtenirMateriaux() const;

    // Fonction définir
    void ajouterMateriaux(Type type);

protected:
    void definirRectangle(float gauche, float haut);
    void definirRectangle(float gauche, float haut,
                          float largeur, float hauteur);
};

/***************************************************/
/*               Fonctions Operateurs              */
/***************************************************/
bool operator<(const Objet &r1, const Objet &r2);
bool operator>(const Objet &r1, const Objet &r2);
bool operator==(const Objet &r1, const Objet &r2);
bool operator<=(const Objet &r1, const Objet &r2);
bool operator>=(const Objet &r1, const Objet &r2);

struct CompareObjetPointeur
{
    bool operator()(Objet *o1, Objet *o2) const
    {
        return o1->obtenirCouche() < o2->obtenirCouche();
        ;
    }
};

/***************************************************/
/*                 Méthodes inline                 */
/***************************************************/
inline sf::Sprite *Objet::obtenirSprite() const { return _affichable.obtenirSprite(); }
inline bool Objet::obtenirVisible() const { return _visible; }
inline uint Objet::obtenirCouche() const { return _affichable.obtenirCouche(); }

#endif
