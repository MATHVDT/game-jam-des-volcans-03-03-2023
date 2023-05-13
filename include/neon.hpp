#ifndef __NEON_HPP__
#define __NEON_HPP__

// #include "FRsupEN.hpp"

#include "bougeable.hpp"
#include "fixe.hpp"
#include "Contexte.hpp"
#include <set>

class Neon : public Fixe
{
private:
	bool estOuvert;
	bool iphone;
	int etat;

public:
	Neon(sf::Vector2f position,
		 sf::Vector2f scale,
		 uint couche,
		 bool visible);
	virtual ~Neon() override;

	void clic() override{};
	bool estIphone() override;
	void miseAJour();
};

#endif
