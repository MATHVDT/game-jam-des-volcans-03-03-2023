#ifndef __OBJET_HPP__
#define __OBJET_HPP__
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

    static std::map<std::string, sf::Texture *> textureMap;

public: // Static
    static std::map<std::string, sf::Texture *> obtenirTextureMap();

public:
    Objet(sf::Vector2f position,
          sf::Vector2f scale,
          uint couche,
          bool visible);
    virtual ~Objet();

    static void initialisationTexture();
    virtual bool estIphone() = 0;
    virtual void clic() = 0;

    bool obtenirVisible() const;
    sf::Sprite *obtenirSprite() const;
    const sf::Rect<float> &obtenirRectangle();
    const sf::Vector2f &obtenirPosition() const;
	const std::vector<Type> obtenirMateriaux() const;

    // Setter
	void ajouterMateriaux(Type type);

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

#endif
