#include "../include/Manager.hpp"

Manager *Manager::_instance = nullptr;

Manager::Manager(/* args */)
{
    context = Context::getInstance();
}

Manager::~Manager()
{
    delete context;
}

Manager *Manager::getInstance()
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

    while (1)
    {
        while (context->getPollEvent())
        { // Actualise le contexte seulement quand il ya une evenement

        // context.
        }
    }
}

void checkEvent(sf::Event &event)
{
    switch (event.type)
    {
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
