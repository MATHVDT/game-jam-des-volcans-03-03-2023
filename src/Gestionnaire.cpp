#include "../include/Gestionnaire.hpp"
#include <SFML/Graphics/Texture.hpp>

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
				contexte->dessiner();
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
   /* Objet *o = new Bougeable(sf::Vector2f(0.0f, 0.0f),
                             sf::Vector2f(1.0f, 1.0f),
                             *t, 0, true);
*/		sf::Texture *ta = Objet::obtenirTextureMap()["ressources/armoire_ferme.png"];
    Objet *o = new Armoire(sf::Vector2f(0.0f, 0.0f),
                             sf::Vector2f(1.0f, 1.0f),
                              *Objet::obtenirTextureMap()["ressources/armoire_ferme.png"]
, 0, true);

    contexte->ajouterAffichable(scene, o);
}

const sf::Vector2f Gestionnaire::getMousePos(sf::RenderWindow &window) const
{
    // récupération de la position de la souris dans la fenêtre
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
    // conversion en coordonnées "monde"
    return window.mapPixelToCoords(pixelPos);
}

