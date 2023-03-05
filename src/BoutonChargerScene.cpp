#include "../include/BoutonChargerScene.hpp"

BoutonChargerScene::BoutonChargerScene(sf::Vector2f position, sf::Vector2f scale,
                                       uint couche, bool visible,
                                       uint numeroScene, std::string cleTextureScene)

    : Fixe(position, scale, couche, visible)
{
    _numeroScene = numeroScene;

    _affichable.definirTexture(*textureMap[cleTextureScene]);
}

BoutonChargerScene::~BoutonChargerScene() {}

void BoutonChargerScene::clic()
{
    Contexte::obtenirInstance()->definirSceneChargee(_numeroScene);
}
