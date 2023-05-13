#include <iostream>
#include <SFML/Graphics.hpp>

#include "../include/Gestionnaire.hpp"
#include "../include/objet.hpp"
#include "../include/Fond.hpp"

int main()
{
  Objet::initialisationTexture();
  Fond::initialisationTexture();

  Gestionnaire *manager = Gestionnaire::obtenirInstance();

  manager->initScene();
  manager->run();

  delete manager;

  return 0;
}
