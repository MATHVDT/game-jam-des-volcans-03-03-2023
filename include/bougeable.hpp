#ifndef __BOUGEABLE_HPP__
#define __BOUGEABLE_HPP__
#include "objet.hpp"

class Bougeable : public Objet {
				public :
								bool selectionnee;
								sf::Vector2<int> position_initiale;
				private:
								bool estIphone() override;
								void remettrePosition();
								void definirPosition(int haut, int gauche);
								void relache();
								void clic() override;
};




#endif
