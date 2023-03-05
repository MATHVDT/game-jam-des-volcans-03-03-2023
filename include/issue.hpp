#ifndef _INCLUDE_ISSUUUUUUUUUE_HPP
#define _INCLUDE_ISSUUUUUUUUUE_HPP

#include "fixe.hpp"

class Issue : public Fixe {
		private:
				bool iphone;

		public:
				Issue(sf::Vector2f position,
						sf::Vector2f scale,
						uint couche,
						bool visible);
				virtual ~Issue() override;

				void miseAJour(); 
				void clic() override {};
				bool estIphone() override;
};

#endif
