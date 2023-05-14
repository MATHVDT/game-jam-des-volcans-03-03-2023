#include "../include/fixe.hpp"

Fixe::Fixe(sf::VECTEUR_NB_VIRGULE position,
           sf::VECTEUR_NB_VIRGULE scale,
           ENTIER_NON_SIGNE couche,
           BOOLEEN visible)
    : Objet(position, scale, couche, visible) {}

Fixe::~Fixe() {}
