#include "../include/Context.hpp"

Context *Context::_instance = nullptr;

Context::Context()
{
    _largeurFenetre = 1300.0f;
    _hauteurFenetre = 900.0f;

    _jeuEnCours = true;

    _window.create(sf::VideoMode(_largeurFenetre,
                                 _hauteurFenetre),
                   "SFML works!",
                   sf::Style::Default);

    _window.setActive();
    _window.setPosition(sf::Vector2i(50, 50));
}

Context::~Context()
{
    _window.close();
}

Context *Context::obtenirInstance()
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

bool Context::obtenirPollEvent()
{
    return _window.pollEvent(_event);
}

/// @brief Dessine tous les objets
void Context::dessiner()
{
    for (auto &scene : _tousLesObjets)
    { // Pour chaque scene
        for (auto &o : scene)
        { // Pour chaque objet
            dessiner(o.sprite);
        }
    }
}

void Context::dessiner(sf::Drawable *dessinable)
{
    _window.draw(*dessinable);
}

/// @brief Affiche la fenetre.
void Context::afficherFenetre()
{
    _window.display();
    _window.clear();
}

/// @brief Ajoute un objet a la liste de tous les objets.
/// @param scene
/// @param affichable
void Context::ajouterAffichable(int scene,
                                const Affichable_t &&affichable)
{
    _tousLesObjets[scene].emplace(affichable);
}
