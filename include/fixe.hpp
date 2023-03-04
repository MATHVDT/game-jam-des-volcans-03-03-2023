#ifndef __FIXE_HPP__
#define __FIXE_HPP__
#include "objet.hpp"

class Fixe : public Objet {
				private:
								bool cassee;
				public:
								void clic() override = 0;
								bool estIphone() override = 0;
};


#endif
