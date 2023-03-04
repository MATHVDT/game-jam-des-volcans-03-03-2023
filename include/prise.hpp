#ifndef _INCLUDE_PRISE_HPP
#define _INCLUDE_PRISE_HPP

#include "fixe.hpp"
#include "enum_type.hpp"

class Prise : public Fixe
{
public:
    Prise(sf::Vector2f position,
          sf::Vector2f scale,
          sf::Texture &texture,
          uint couche,
          bool visible);
    virtual ~Prise() override;

	void clic() override{};
	bool estIphone() override { return true; };
};

#endif
