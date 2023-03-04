#ifndef __OBJET_HPP__
#define __OBJET_HPP__
#include <SFML/System/Vector2.hpp>

class Objet {
				private:
								bool visible;
								sf::Vector2<int> position;
				public:
								virtual bool estIphone() =0;
								virtual bool clic() = 0;
};


#endif
