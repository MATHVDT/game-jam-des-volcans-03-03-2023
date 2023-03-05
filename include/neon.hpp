#ifndef _INCLUDE_NEON_HPP
#define _INCLUDE_NEON_HPP

#include "bougeable.hpp"
#include "fixe.hpp"
#include "Contexte.hpp"
#include <set>

class Neon : public Fixe {
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
