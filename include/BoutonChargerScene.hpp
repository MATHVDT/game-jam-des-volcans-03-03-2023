#ifndef __BOUTON_CHARGER_SCENE__
#define __BOUTON_CHARGER_SCENE__

// #include "../FRsupEN.hpp"

#include "fixe.hpp"
#include "Contexte.hpp"

class BoutonChargerScene : public Fixe
{
private:
    uint _numeroScene;

public:
    BoutonChargerScene(sf::Vector2f position,
                       sf::Vector2f scale,
                       uint couche, bool visible,
                       uint numeroScene, std::string cleTextureScene);
    ~BoutonChargerScene();

    void clic() override;
    bool estIphone() override { return false; }
};

#endif