#ifndef __INFLAMMABLE_HPP__
#define __INFLAMMABLE_HPP__

// #include "FRsupEN.hpp"

#include "bougeable.hpp"

class Inflammable : public Bougeable
{
private:
	int etat;
	void miseAJour();

public:
	Inflammable(sf::Vector2f position, sf::Vector2f scale, uint couche, bool visible);

	virtual ~Inflammable() override{};
	void clic() override;
	bool estIphone() override;
};

#endif
