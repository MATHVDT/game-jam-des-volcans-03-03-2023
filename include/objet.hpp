#ifndef __OBJET_HPP__
#define __OBJET_HPP__
#include "enum_type.hpp"
#include <SFML/Graphics/Texture.hpp>
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
protected:
    bool _visible;
    sf::Rect<float> _rectangle;
    Affichable _affichable;

    static std::map<std::string, sf::Texture *> textureMap;

public: // Static
    static std::map<std::string, sf::Texture *> obtenirTextureMap();

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

    // Getter
    bool obtenirVisible() const;
    sf::Sprite *obtenirSprite() const;
    const sf::Rect<float> &obtenirRectangle();
    const sf::Vector2f &obtenirPosition() const;

    // Setter

protected:
    void definirRectangle(float gauche, float haut);
    void definirRectangle(float gauche, float haut,
                          float largeur, float hauteur);
};

/***************************************************/
/*                 Méthodes inline                 */
/***************************************************/
inline sf::Sprite *Objet::obtenirSprite() const { return _affichable.obtenirSprite(); }
inline bool Objet::obtenirVisible() const { return _visible; }
inline const sf::Vector2f &Objet::obtenirPosition() const { return _affichable.obtenirSpritePosition(); }

#endif
