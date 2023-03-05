#include "../include/Contexte.hpp"

Contexte *Contexte::_instance = nullptr;

Contexte::Contexte()
{
    _largeurFenetre = 1600.0f;
    _hauteurFenetre = 900.0f;

    _sceneChargee = 0;
    for (int k = 0; k < NB_SCENES; ++k)
    {
        _tousLesObjets.push_back(std::set<Objet *>{});
    }

    _jeuEnCours = true;

    _objetBougeableSelectionne = nullptr;
    _objetEnInteractionAvecObjetBougeableSelectionne = nullptr;

    _window.create(sf::VideoMode(_largeurFenetre,
                                 _hauteurFenetre),
                   "SFML works!",
                   sf::Style::Default);

    _window.setActive();
    _window.setPosition(sf::Vector2i(50, 50));
    for (int k = 0; k < 6; k++)
    {
        _tousLesObjets.push_back(std::set<Objet *>{});
    }
}

Contexte::~Contexte()
{
    for (auto &scene : _tousLesObjets)
    { // Pour chaque scene
        for (auto &o : scene)
        { // Pour chaque objet
            delete o;
        }
    }
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
    int i = 1;
    
    std::string nom_piece = "ressources/piece_" + std::to_string(i) + ".png";
    _fond = new Fond(nom_piece, sf::Vector2f(0.0f, 0.0f), sf::Vector2f(_largeurFenetre/1920.0f, _hauteurFenetre/1080.0f), (unsigned int)0);
    
    dessiner(_fond->obtenirSprite());
    for (auto &scene : _tousLesObjets)
    { // Pour chaque scene
        // auto &scene = _tousLesObjets[_sceneChargee];
        for (auto &o : scene)
        { // Pour chaque objet
            dessiner(o->obtenirSprite());
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
                                 Objet *o)
{
    _tousLesObjets[scene].emplace(o);
}

const sf::Vector2f Contexte::obtenirSourisPosition() const
{
    // récupération de la position de la souris dans la fenêtre
    sf::Vector2i pixelPos = sf::Mouse::getPosition(_window);
    // conversion en coordonnées "monde"
    return _window.mapPixelToCoords(pixelPos);
}
