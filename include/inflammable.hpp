#ifndef _INCLUDE_CISEAUX_HPP
#define _INCLUDE_CISEAUX_HPP

#include "bougeable.hpp"
class Inflammable : public Bougeable {
    private:
	int etat;
	void miseAJour();

    public:
	Inflammable(sf::Vector2f position, sf::Vector2f scale, uint couche, bool visible);

	virtual ~Inflammable() override {};
	void clic() override;
	bool estIphone() override;
};

#endif
