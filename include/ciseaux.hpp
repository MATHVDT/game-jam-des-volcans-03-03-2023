#ifndef _INCLUDE_CISEAUX_HPP
#define _INCLUDE_CISEAUX_HPP

#include "bougeable.hpp"
class Ciseaux : public Bougeable {

		public:
				Ciseaux(sf::Vector2f position, sf::Vector2f scale,  uint couche, bool visible);

				virtual ~Ciseaux() override {};
				// void clic() override ;
				bool estIphone() override {return true;};
};

#endif
