#ifndef _ALLUMETTE_HPP
#define _ALLUMETTE_HPP

#include "bougeable.hpp"
class Allumette : public Bougeable {
    private:
	int etat;
	void miseAJour();

    public:
	Allumette(sf::Vector2f position, sf::Vector2f scale, uint couche, bool visible);

	virtual ~Allumette() override {};
	void clic() override;
	bool estIphone() override;
};

#endif
