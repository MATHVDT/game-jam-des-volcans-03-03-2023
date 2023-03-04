#ifndef __OBJET_HPP__
#define __OBJET_HPP__
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>

class Objet {
				private:
								bool visible;
								sf::Rect<int> rectangle;
				public:
								virtual bool estIphone() =0;
								virtual bool clic() = 0;
};


#endif
