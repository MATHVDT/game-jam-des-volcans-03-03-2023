#ifndef __OBJET_HPP__
#define __OBJET_HPP__
#include <Vector2.hpp>

class Objet {
				private:
								bool visible;
								sf::Vector2<int> position;
				public:
								bool estIphone() =0;
								bool clic() = 0;
};


#endif
