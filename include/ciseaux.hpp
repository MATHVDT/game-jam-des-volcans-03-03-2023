#ifndef __CISEAUX_HPP__
#define __CISEAUX_HPP__

// #include "../FRsupEN.hpp"

#include "bougeable.hpp"

class Ciseaux : public Bougeable
{
private:
	int etat;
	void miseAJour();

public:
	Ciseaux(sf::Vector2f position, sf::Vector2f scale, uint couche, bool visible);

	virtual ~Ciseaux() override{};
	void clic() override;
	bool estIphone() override;
};

#endif
