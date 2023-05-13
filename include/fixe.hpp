#ifndef __FIXE_HPP__
#define __FIXE_HPP__

// #include "FRsupEN.hpp"

#include "objet.hpp"

class Fixe : public Objet
{
private:
    bool cassee;

public:
    Fixe(sf::Vector2f position,
         sf::Vector2f scale,
         uint couche,
         bool visible);
    virtual ~Fixe() override;

    void clic() override = 0;
    bool estIphone() override = 0;
};

#endif
