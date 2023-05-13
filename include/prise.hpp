#ifndef _PRISE_HPP
#define _PRISE_HPP

#include "fixe.hpp"

class Prise : public Fixe
{
private:
	bool iphone;
	int etat;

public:
	Prise(sf::Vector2f position,
		  sf::Vector2f scale,
		  uint couche,
		  bool visible);
	virtual ~Prise() override;

	void miseAJour();
	void clic() override{};
	bool estIphone() override;
};

#endif
