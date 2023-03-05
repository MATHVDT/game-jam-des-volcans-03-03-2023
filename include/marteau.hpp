#ifndef _INCLUDE_MARTEAU_HPP
#define _INCLUDE_MARTEAU_HPP

#include "bougeable.hpp"
class Marteau : public Bougeable {
		private:
				int etat;
				void miseAJour();

		public:
				Marteau(sf::Vector2f position, sf::Vector2f scale, uint couche, bool visible);

				virtual ~Marteau() override {};
				void clic() override;
				bool estIphone() override;
};

#endif
