#ifndef _INCLUDE_PRISE_HPP
#define _INCLUDE_PRISE_HPP

#include "fixe.hpp"
#include "enum_type.hpp"

class Prise : public Fixe {
				public:
								void clic() override {};
								bool estIphone() override {return true;};
};

#endif
