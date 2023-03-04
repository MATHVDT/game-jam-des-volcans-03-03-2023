#include "../include/Manager.hpp"

Gestionnaire *Gestionnaire::_instance = nullptr;

Gestionnaire::Gestionnaire(/* args */)
{
    context = Contexte::obtenirInstance();
}

Gestionnaire::~Gestionnaire()
{
    delete context;
}

Gestionnaire *Gestionnaire::obtenirInstance()
{
    if (Gestionnaire::_instance == nullptr)
    {
        Gestionnaire::_instance = new Gestionnaire();
        if (Gestionnaire::_instance == nullptr)
        {
            std::cerr << "Erreur de new\n";
            return nullptr;
        }
        else
        {
            return Gestionnaire::_instance;
        }
    }
}

void Gestionnaire::run()
{
    sf::Event event;

    while (context->obtenirJeuEnCours())
    {

        while (context->obtenirSonderEvenement())
        { // Actualise le contexte seulement quand il ya une evenement
            checkEvenment(context->obtenirEvenement());
        }
        context->afficherFenetre();
    }
}

/// @brief Lance les actions suivant les evenements
/// @param evenement
void Gestionnaire::checkEvenment(const sf::Event &evenement)
{
    switch (evenement.type)
    {
    case sf::Event::Closed:
        context->definirJeuEnCours(false);
        break;

    case sf::Event::MouseMoved:
        // Souris bougee
        break;

    case sf::Event::MouseButtonPressed:
        // bouton pressed
        break;

    case sf::Event::MouseButtonReleased:
        // bouton relache
        break;

    default:
        break;
    }
}
