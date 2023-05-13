#ifndef __MARTEAU_HPP__
#define __MARTEAU_HPP__

// #include "FRsupEN.hpp"

#include "bougeable.hpp"

class Marteau : public Bougeable
{
private:
	int etat;
	void miseAJour();

public:
	Marteau(sf::Vector2f position, sf::Vector2f scale, uint couche, bool visible);

	virtual ~Marteau() override{};
	void clic() override;
	bool estIphone() override;
};

#endif
