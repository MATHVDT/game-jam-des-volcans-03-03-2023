#ifndef __BOUGEABLE_HPP__
#define __BOUGEABLE_HPP__
#include "objet.hpp"

class Bougeable : public Objet {
		protected:
				bool _selectionnee;
				sf::Vector2<float> _position_initiale;

		public:
				Bougeable(sf::Vector2f position,
						sf::Vector2f scale,
						uint couche,
						bool visible);

				virtual ~Bougeable() override;

				virtual bool estIphone() override;
				void remettrePosition();
				void definirPosition(float haut, float gauche);
				void relache();
				virtual void clic() override;
};

#endif
