#ifndef _CANAPE_HPP
#define _CANAPE_HPP

#include "bougeable.hpp"
class Canape : public Bougeable {
		private:
				int etat;
				void miseAJour();

		public:
				Canape(sf::Vector2f position, sf::Vector2f scale, uint couche, bool visible);

				virtual ~Canape() override {};
				void clic() override;
				bool estIphone() override;
};

#endif
