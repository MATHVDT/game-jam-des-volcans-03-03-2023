#ifndef __BOUGEABLE_HPP__
#define __BOUGEABLE_HPP__

#include "Contexte.hpp"
#include "objet.hpp"

class Bougeable : public Objet
{
protected:
	bool _selectionnee;
	sf::Vector2f _position_initiale;

public:
	Bougeable(sf::Vector2f position,
			  sf::Vector2f scale,
			  uint couche,
			  bool visible);
	virtual ~Bougeable() override;

	virtual bool estIphone() override;
	void remettrePosition();
	void relache();
	void definirPosition(const sf::Vector2f &position);
	void definirPositionCentreSprite(const sf::Vector2f &position);
	void clic() override;
};

#endif
