#include "../include/Manager.hpp"

Manager *Manager::_instance = nullptr;

Manager::Manager(/* args */)
{
    context = Context::obtenirInstance();
}

Manager::~Manager()
{
    delete context;
}

Manager *Manager::obtenirInstance()
{
    if (Manager::_instance == nullptr)
    {
        Manager::_instance = new Manager();
        if (Manager::_instance == nullptr)
        {
            std::cerr << "Erreur de new\n";
            return nullptr;
        }
        else
        {
            return Manager::_instance;
        }
    }
}

void Manager::run()
{
    sf::Event event;

    while (context->obtenirJeuEnCours())
    {

        while (context->obtenirPollEvent())
        { // Actualise le contexte seulement quand il ya une evenement
            checkEvent(context->obtenirEvent());
        }
        context->afficherFenetre();
    }
}

void Manager::checkEvent(const sf::Event &event)
{
    switch (event.type)
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
