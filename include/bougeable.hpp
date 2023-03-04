#ifndef __BOUGEABLE_HPP__
#define __BOUGEABLE_HPP__
#include "objet.hpp"

class Bougeable : public Objet {
				public :
								bool selectionnee;
								sf::Vector2<int> position_initiale;
				private:
								bool estIphone() override;
								void reset_position();
								void relache();
								bool clic() override;
};




#endif
