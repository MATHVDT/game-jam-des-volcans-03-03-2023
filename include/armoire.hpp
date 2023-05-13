#ifndef __ARMOIRE_HPP__
#define __ARMOIRE_HPP__

// #include "../FRsupEN.hpp"

#include "bougeable.hpp"
#include "fixe.hpp"
#include "Contexte.hpp"
#include <set>

class Armoire : public Fixe
{
private:
	bool estOuvert;
	std::set<Bougeable *> _listeObjet;

public:
	Armoire(sf::Vector2f position,
			sf::Vector2f scale,
			uint couche,
			bool visible,
			std::set<Bougeable *> listeObjet);
	virtual ~Armoire() override;

	void clic() override;
	bool estIphone() override { return true; };
};

#endif
