#ifndef _CORBEILLE_HPP
#define _CORBEILLE_HPP
#include "fixe.hpp"

class Corbeille : public Fixe {
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
