#include "../include/Gestionnaire.hpp"

Gestionnaire *Gestionnaire::_instance = nullptr;

Gestionnaire::Gestionnaire(/* args */)
{
    contexte = Contexte::obtenirInstance();
}

Gestionnaire::~Gestionnaire()
{
    delete contexte;
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

    while (contexte->obtenirJeuEnCours())
    {

        while (contexte->obtenirSonderEvenement())
        { // Actualise le contexte seulement quand il ya une evenement
            checkEvenment(contexte->obtenirEvenement());
        }
        contexte->afficherFenetre();
    }
}

/// @brief Lance les actions suivant les evenements
/// @param evenement
void Gestionnaire::checkEvenment(const sf::Event &evenement)
{
    switch (evenement.type)
    {
    case sf::Event::Closed:
        contexte->definirJeuEnCours(false);
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

void Gestionnaire::initScene()
{
    uint scene = 0;
    std::string img = "ressources/prise.png";
    sf::Texture *t = new sf::Texture();
    t->loadFromFile(img);
    Affichable_t a = Affichable_t();
    a.couche = 0;
    a.sprite.setTexture(*t);
    contexte->ajouterAffichable(scene, a);
}