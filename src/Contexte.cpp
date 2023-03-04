#include "../include/Contexte.hpp"

Contexte *Contexte::_instance = nullptr;

Contexte::Contexte()
{
    _largeurFenetre = 1300.0f;
    _hauteurFenetre = 900.0f;

    _jeuEnCours = true;

    _objetBougeableSelectionne = nullptr;
    _objetEnInteractionAvecObjetBougeableSelectionne = nullptr;

    _window.create(sf::VideoMode(_largeurFenetre,
                                 _hauteurFenetre),
                   "SFML works!",
                   sf::Style::Default);

    _window.setActive();
    _window.setPosition(sf::Vector2i(50, 50));
}

Contexte::~Contexte()
{
    _window.close();
}

Contexte *Contexte::obtenirInstance()
{
    if (Contexte::_instance == nullptr)
    {
        Contexte::_instance = new Contexte();
        if (Contexte::_instance == nullptr)
        {
            std::cerr << "Erreur de new\n";
            return nullptr;
        }
        else
        {
            return Contexte::_instance;
        }
    }
}

bool Contexte::obtenirSonderEvenement()
{
    return _window.pollEvent(_event);
}

/// @brief Dessine tous les objets
void Contexte::dessiner()
{
    for (auto &scene : _tousLesObjets)
    { // Pour chaque scene
        for (auto &o : scene)
        { // Pour chaque objet
            const sf::Sprite &s = o.sprite;
            dessiner(s);
        }
    }
}

void Contexte::dessiner(const sf::Drawable &dessinable)
{
    _window.draw(dessinable);
}

void Contexte::dessiner(const sf::Drawable *dessinable)
{
    _window.draw(*dessinable);
}

/// @brief Affiche la fenetre.
void Contexte::afficherFenetre()
{
    _window.display();
    _window.clear();
}

/// @brief Ajoute un objet a la liste de tous les objets.
/// @param scene
/// @param affichable
void Contexte::ajouterAffichable(int scene,
                                 const Affichable_t &&affichable)
{
    _tousLesObjets[scene].emplace(affichable);
}
