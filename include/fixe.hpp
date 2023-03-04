#ifndef __FIXE_HPP__
#define __FIXE_HPP__
#include "objet.hpp"

class Fixe : public Objet {
				private:
								bool cassee;
				public:
								bool clic() override;
};


#endif
