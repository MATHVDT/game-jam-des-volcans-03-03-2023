#include "../include/Context.hpp"

Context *Context::_instance = nullptr;

Context::Context()
{
    _largeurFenetre = 500.0f;
    _hauteurFenetre = 500.0f;

    _window.create(sf::VideoMode(_largeurFenetre,
                                 _hauteurFenetre),
                   "SFML works!",
                   sf::Style::Default);
}

Context::~Context()
{
}

Context *Context::getInstance()
{
    if (Context::_instance == nullptr)
    {
        Context::_instance = new Context();
        if (Context::_instance == nullptr)
        {
            std::cerr << "Erreur de new\n";
            return nullptr;
        }
        else
        {
            return Context::_instance;
        }
    }
}

bool Context::getPollEvent()
{
    return _window.pollEvent(_event);
}

void Context::dessiner(sf::Drawable *dessinable)
{
    _window.draw(*dessinable);
}

void Context::afficherFenetre()
{
    _window.display();
    _window.clear();
}
