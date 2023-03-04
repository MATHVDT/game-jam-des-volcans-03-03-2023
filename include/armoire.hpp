#ifndef _INCLUDE_ARMOIRE_HPP
#define _INCLUDE_ARMOIRE_HPP

#include "fixe.hpp"

class Armoire : public Fixe {
				private :
								bool estOuvert;
				public :
								void clic() override;
};

#endif
