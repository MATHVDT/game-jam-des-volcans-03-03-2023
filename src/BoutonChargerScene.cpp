#include "../include/BoutonChargerScene.hpp"

BoutonChargerScene::BoutonChargerScene(sf::VECTEUR_NB_VIRGULE position, sf::VECTEUR_NB_VIRGULE scale,
                                       ENTIER_NON_SIGNE couche, BOOLEEN visible,
                                       ENTIER_NON_SIGNE numeroScene, std::CHAINE cleTextureScene)

    : Fixe(position, scale, couche, visible)
{
    _numeroScene = numeroScene;
    _affichable.definirTexture(*textureCarte[cleTextureScene]);
}

BoutonChargerScene::~BoutonChargerScene() {}

RIEN BoutonChargerScene::clic()
{
    Contexte::obtenirInstance()->definirSceneChargee(_numeroScene);
}
