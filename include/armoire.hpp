#ifndef _INCLUDE_ARMOIRE_HPP
#define _INCLUDE_ARMOIRE_HPP

#include "fixe.hpp"

class Armoire : public Fixe
{
private:
	bool estOuvert;

public:
    Armoire(sf::Vector2f position,
          sf::Vector2f scale,
          sf::Texture &texture,
          uint couche,
          bool visible);
    virtual ~Armoire() override;

	void clic() override;
	bool estIphone() override { return true; };
};

#endif
