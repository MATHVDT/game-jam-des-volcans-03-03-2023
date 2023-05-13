#ifndef __CORBEILLE_HPP__
#define __CORBEILLE_HPP__

// #include "../FRsupEN.hpp"

#include "fixe.hpp"

class Corbeille : public Fixe
{
private:
	int etat;
	void miseAJour();

public:
	Corbeille(sf::Vector2f position,
			  sf::Vector2f scale,
			  uint couche,
			  bool visible);
	virtual ~Corbeille() override;

	void clic() override;
	bool estIphone() override;
};

#endif
