#include "../FRsupEN.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>

#include "../include/Gestionnaire.hpp"
#include "../include/objet.hpp"
#include "../include/Fond.hpp"

ENTIER PRINCIPAL()
{
  Objet::initialisationTexture();
  Fond::initialisationTexture();

  Gestionnaire *manager = Gestionnaire::obtenirInstance();

  manager->initScene();
  manager->enCours();

  SUPPRIMER manager;

  RETOUR 0;
}
